#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#ifdef __linux__
#  include <netdb.h>
#  include <memory.h>
#else
#  include <resolvLib.h>
#  include <WPILib.h>
#endif
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Nets.h"

#ifndef __linux__
namespace {
	char resolv_buf[1024];
	hostent *gethostbyname(char *_hostname) {
		return resolvGetHostByName(_hostname, resolv_buf, sizeof(resolv_buf));
	}
}
#endif

#define DEBUG_LEVEL 1
#if DEBUG_LEVEL > 0
#  define DEBUG(fmt) fprintf(stderr, "%d: " fmt, (int)clock() / 10)
#  define DEBUGF(fmt, ...) fprintf(stderr, "%d: " fmt, (int)clock() / 10, __VA_ARGS__)
#else
#  define DEBUG(...)
#endif

/*
 * This is sort of awkward, but this initiates the network stuff as a client.
 * conn_callback may be NULL.
 */
Nets::Nets(char *hostname, int port, void (*conn_callback)(void)) {
	type = NETS_TYPE_CLIENT;
	this->port = port;
	this->hostname = hostname;
	this->conn_callback = conn_callback;

	data_to_send = NULL;
	data_to_read = NULL;
	haz_connection = false;
}

/*
 * And this initiates it as a server. \o/
 * TODO: make this at least slightly intuitive?^W^W^W^W^W^Wmeh. whatever.
 * conn_callback may be NULL.
 */
Nets::Nets(int port, void (*conn_callback)(void)) {
	type = NETS_TYPE_SERVER;
	this->port = port;
	this->conn_callback = conn_callback;

	data_to_send = NULL;
	data_to_read = NULL;
	haz_connection = false;
}

/*
 * The connection stuff is not thread safe. Only call it from one thread at a
 * time.
 */
int Nets::make_connection(void) {
	int ret;

	DEBUG("make_connection: attempting to create a connection...\n");

	if (type == NETS_TYPE_SERVER) {
		ret = accept_connection();
	} else if (type == NETS_TYPE_CLIENT) {
		ret = connect_to_server();
	} else {
		DEBUG("make_connection: invalid type\n");
		return 1;
	}

	/* Connection succeeded. */
	if (!ret) {
		DEBUG("make_connection: connection created\n");
		haz_connection = true;
	} else {
		DEBUG("make_connection: connection attempt failed\n");
	}

	/* CALLBACK */
	if (conn_callback) {
		(*conn_callback)();
	}

	return ret;
}

/* TODO: Move all of the folded stuff to a separate file. */
/* SERVER STUFF {{{ */
int Nets::server_init() {
	int val;
	sockaddr_in addr;

	if (type != NETS_TYPE_SERVER) {
		DEBUG("this is not a server -_-");
		return 1;
	}

	/* Just in case. */
	close(server_fd);
	server_fd = -1;

	/* MAKE SOCKET */
	server_fd  = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1) {
		perror("socket");
		return 1;
	}

	/* SO_REUSEADDR */
	val = 1;
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&val, sizeof(val)) < 0 ) {
		perror("SO_REUSEADDR");
		close(server_fd);
		return 1;
	}

	/* BIND */
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);
	if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("bind");
		close(server_fd);
		return 1;
	}

	/* LISTEN */
	if (listen(server_fd, 1) < 0) {
		perror("listen");
		close(server_fd);
		return 1;
	}

	return 0;
}

int Nets::accept_connection(void) {
	fd = accept(server_fd, NULL, 0);
	if (fd == -1) {
		perror("accept");
		return 1;
	}

	return 0;
}
/* }}} END SERVER STUFF */

/* CLIENT STUFF {{{ */
int Nets::connect_to_server(void) {
	struct hostent *host;
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);

	/* MAKE SOCKET */
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1) {
		perror("socket");
		return 1;
	}

	/* RESOLVE HOSTNAME */
	host = gethostbyname(hostname);
	if (!host) {
		perror("gethostbyname");
		close(fd);
		fd = -1;
		return 1;
	}

	/* CONNECT */
	memcpy((char *)&(addr.sin_addr.s_addr), (char *)(host->h_addr), host->h_length);
	if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		perror("connect");
		close(fd);
		fd = -1;
		return 1;
	}

	DEBUG("connected to server\n");

	return 0;
}
/* }}} END CLIENT STUFF */

/*
 * The actual sending is delegated to send_task, which runs in a different thread.
 * Returns 1 if we still have data to send.
 */
int Nets::send_datas(struct nets_data *data) {
	if (data_to_send) {
		DEBUG("send_datas: We still have data to send\n");
		return 1;
	}

	data_to_send = data;
	return 0;
}

/* The actual reading is delegated to read_task, which runs in a different thread. */
int Nets::read_datas(struct nets_data *data, void (*callback)(struct nets_data *, void *context), void *context) {
	if (data_to_read) {
		DEBUG("send_datas: We still have data to read.\n");
		return 1;
	}

	data_to_read = data;
	read_callback = callback;
	read_callback_context = context;

	return 0;
}

/*
 * Tell the connection thread to reconnect.
 * Block until we are reconnected.
 */
void Nets::handle_connection_error(void) {
	DEBUG("handle_connection_error: reconnecting...\n");

	haz_connection = false;

	/* There is a tiny race condition here. I don't feel like fixing it. */

	while (!haz_connection) {
		sleep(1);
	}
}

/* This does not return. */
void Nets::conn_task(void) {
	for (;;) {
		if (!haz_connection) {
			close(fd);
			fd = -1;
			/* Try to reconnect forever. */
			while (make_connection()) {
				sleep(1);
			}
		}
		sleep(1);
	}
}

/* This does not return. */
void Nets::send_task(void) {
	int len;
	int ret;
	bool error;
	size_t i;

	DEBUG("send_task: initialized\n");

	for (;;) {
		error = false;

		DEBUG("send_task: waiting for data\n");
		while (!data_to_send || !haz_connection) {
			sleep(1);
		}

		DEBUGF("send_task: sending %d bytes of data at %p\n", (int)data_to_send->len, data_to_send->info);

		DEBUG("send_task: waiting for lock\n");
		pthread_mutex_lock(data_to_send->lck);

		DEBUG("send_task: lock obtained\n");

		/* HEADER */
		memset(&send_header, 0, sizeof(send_header));
		len = sizeof(send_header);
		send_header.magic = htonl(NETS_DATA_MAGIC);
		send_header.len = htonl(data_to_send->len);
		DEBUG("send_task: writing header...\n");
		while (len) {
			ret = write(fd, (char *)&send_header + sizeof(send_header) - len, len);
			if (ret == -1) {
				perror("send_task: write header");

				pthread_mutex_unlock(data_to_send->lck);
				handle_connection_error();

				/* Sorry about the error fall through crap. */
				error = true;
				break;
			}

			len -= ret;
		}

		/* INFO */
		if (!error) {
			for (i = 0; i < data_to_send->len / sizeof(uint32_t); i++) {
				((uint32_t *)data_to_send->info)[i] = htonl(((uint32_t *)data_to_send->info)[i]);
			}

			len = data_to_send->len;
			DEBUG("send_task: writing info...\n");
			while (len) {
				ret = write(fd, (char *)data_to_send->info + data_to_send->len - len, len);
				if (ret == -1) {
					perror("send_task: write info");

					pthread_mutex_unlock(data_to_send->lck);
					handle_connection_error();

					error = true;
					break;
				}
				DEBUGF("send_task: wrote %d bytes of data...\n", ret);

				len -= ret;
			}
		}

		if (!error) {
			pthread_mutex_unlock(data_to_send->lck);
			DEBUG("send_task: lock released\n");
			data_to_send = NULL;
		}

		/* TODO: rid ourselves of this call */
		sleep(1);
	}
}

/* This does not return. */
void Nets::read_task(void) {
	ssize_t ret;
	ssize_t len;
	bool error;
	size_t i;
	struct nets_data *tmp;

	DEBUG("read_task: initialized\n");

	for (;;) {
		error = false;

		DEBUG("read_task: waiting for a place to store read data\n");
		while (!data_to_read || !haz_connection) {
			sleep(1);
		}

		DEBUG("read_task: waiting for lock...\n");
		pthread_mutex_lock(data_to_read->lck);

		/* HEADER */
		DEBUG("read_task: reading header...\n");
		len = sizeof(read_header);
		memset(&read_header, 0, sizeof(read_header));
		while (len) {
			ret = read(fd, (char *)&read_header + sizeof(read_header) - len, len);
			if (ret <= 0) {
				/* Assume all errors are fatal. Reconnect. */
				perror("read_task: read header");

				pthread_mutex_unlock(data_to_read->lck);
				DEBUG("read_task: lock released\n");
				handle_connection_error();

				error = true;
				break;
			}
			DEBUGF("read_task: read %ld bytes of data with %ld left to read...\n", ret, len);

			len -= ret;
		}

		read_header.magic = ntohl(read_header.magic);
		read_header.len = ntohl(read_header.len);

		/* Check magic */
		if (!error) {
			if (read_header.magic != NETS_DATA_MAGIC) {
				/* Bad data. Reconnect. */
				DEBUGF("read_task: received a bad header %X\n", read_header.magic);

				pthread_mutex_unlock(data_to_read->lck);
				handle_connection_error();

				error = true;
			} else {
				DEBUG("read_task: received a good header\n");
			}
		}

		/* CHECK LENGTH */
		if (read_header.len > data_to_read->max_len) {
			DEBUG("read_task: data too large\n");

			pthread_mutex_unlock(data_to_read->lck);
			handle_connection_error();
		}

		/* INFO */
		if (!error) {
			DEBUG("read_task: reading info...\n");

			// TODO: Verify rh.len <= sizeof(dtr->info) .. vulnerability
			data_to_read->len = read_header.len;
			len = read_header.len;
			memset(data_to_read->info, 0, data_to_read->len);
			while (len) {
				ret = read(fd, (char *)data_to_read->info + read_header.len - len, len);
				if (ret == -1) {
					/* Assume all errors are fatal. Reconnect. */
					perror("read_task: read info");

					pthread_mutex_unlock(data_to_read->lck);
					handle_connection_error();

					error = true;
					break;
				}

				len -= ret;
			}

			for (i = 0; i < data_to_read->len / sizeof(uint32_t); ++i) {
				((uint32_t *)data_to_read->info)[i] = ntohl(((uint32_t *)data_to_read->info)[i]);
			}
		}

		if (!error) {
			pthread_mutex_unlock(data_to_read->lck);

			DEBUG("read_task: releasing lock\n");

			tmp = data_to_read;
			data_to_read = NULL;

			if (read_callback) {
				DEBUG("read_task: calling callback\n");
				(*read_callback)(tmp, read_callback_context);
			}
		}

		/* TODO: find better solution. */
		sleep(1);
	}
}
