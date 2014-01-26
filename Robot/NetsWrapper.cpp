#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Nets.h"
#include "NetsWrapper.h"

#define DEBUG_LEVEL 0
#if DEBUG_LEVEL > 0
#  define DEBUG(fmt) fprintf(stderr, "%d: " fmt, (int)clock() / 10)
#  define DEBUGF(fmt, ...) fprintf(stderr, "%d: " fmt, (int)clock() / 10, __VA_ARGS__)
#else
#  define DEBUG(...)
#  define DEBUGF(...)
#endif

#define PORT 2223

namespace {
	void callback_helper(struct nets_data *data, void *context) {
		((NetsWrapper *)context)->callback_me_maybe(data);
	}
}

#if !defined(CLIENT) && !defined(SERVER)
#  warning "CLIENT and SERVER not defined. Defaulting to CLIENT test."
#  define CLIENT
#endif

NetsWrapper::NetsWrapper() {
#if defined(CLIENT)
# ifdef __linux__
	nets = new Nets((char *)"localhost", PORT, NULL);
# else
	nets = new Nets((char *)"10.18.85.56", PORT, NULL);
# endif
#elif defined(SERVER)
	nets = new Nets(PORT, NULL);
#endif
}

/* CALLBACKS {{{ */
void NetsWrapper::callback_me_maybe(struct nets_data *data) {
	DEBUG("callback_me_maybe: waiting for lock...\n");

	pthread_mutex_lock(data->lck);

	DEBUGF("callback_me_maybe: data length: %d\n", (int)data->len);

	DEBUGF("callback_me_maybe: i1 is 0x%X, f is %f, i2 is 0x%X\n", \
		((struct test_info *)data->info)->i1,
		((struct test_info *)data->info)->f,
		((struct test_info *)data->info)->i2);

	pthread_mutex_unlock(data->lck);

	DEBUG("callback_me_maybe: released lock...\n");

	/* NEW READ {{{ */
	if (nets->read_datas(&read_data, &callback_helper, this)) {
		DEBUG("callback_me_maybe: read_datas failed\n");
		return;
	}
	/*}}}*/
}
/*}}}*/

int NetsWrapper::send(void *data, size_t len) {
	/* INIT DATA {{{ */
	send_data.info = (unsigned char *)data;
	send_data.lck = &send_lck;
	send_data.len = len;

	read_data.info = (unsigned char *)data;
	read_data.lck = &read_lck;
	read_data.max_len = len;
	/*}}}*/

	return 0;
}

int NetsWrapper::init() {
	/* CONNECTION {{{ */
#if defined(SERVER)
	DEBUG("SERVER\n");
	if (nets->server_init()) {
		DEBUG("failed to init server\n");
	}
#else
	DEBUG("CLIENT\n");
#endif

	DEBUG("here we go \\o/\n");

	/* INIT LOCKS {{{ */
	if (pthread_mutex_init(&send_lck, NULL) != 0) {
		DEBUG("failed mutex init\n");
		return 1;
	}

	if (pthread_mutex_init(&read_lck, NULL) != 0) {
		DEBUG("failed mutex init\n");
		return 1;
	}
	/*}}}*/

	/* CREATE THREADS {{{ */
	if (pthread_create(&send_tid, NULL, &Nets::send_task_helper, nets)) {
		perror("pthread_create for send_task");
		/* TODO: cleanup */
		return 1;
	}

	if (pthread_create(&read_tid, NULL, &Nets::read_task_helper, nets)) {
		perror("pthread_create for read_task");
		/* TODO: cleanup */
		return 1;
	}

	if (pthread_create(&conn_tid, NULL, &Nets::conn_task_helper, nets)) {
		perror("pthread_create for conn_task");
		/* TODO: cleanup */
		return 1;
	}
	/*}}}*/

	/* FIRST READ {{{ */
	if (nets->read_datas(&read_data, &callback_helper, this)) {
		DEBUG("inital read_datas failed\n");
		return 1;
	}
	/*}}}*/

	return 0;
}
