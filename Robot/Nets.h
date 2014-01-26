#ifndef _NETS_H_
#define _NETS_H_

#define NETS_DATA_MAGIC 0x12345678

struct nets_data {
	unsigned char *info;
	size_t len;
	size_t max_len;
	pthread_mutex_t *lck;
};

struct nets_header {
	unsigned int magic;
	unsigned int len;
};

enum nets_type { NETS_TYPE_UNDEFINED = 0, NETS_TYPE_CLIENT, NETS_TYPE_SERVER };
typedef enum nets_type nets_type;

class Nets {
	public:
		Nets(int port, void (*conn_callback)(void));
		Nets(char *hostname, int port, void (*conn_callback)(void));

		/* ACCEPT OR CONNECT */
		int make_connection(void);

		/* SEND DATAS */
		int send_datas(struct nets_data *data);

		/* READ DATAS */
		int read_datas(struct nets_data *data, void (*callback)(struct nets_data *, void *context), void *context);

		/* INIT SERVER */
		int server_init();

		/* TASK HELPERS */
		static void *send_task_helper(void *context) {
			((Nets *)context)->send_task();
			return NULL;
		}
		static void *read_task_helper(void *context) {
			((Nets *)context)->read_task();
			return NULL;
		}
		static void *conn_task_helper(void *context) {
			((Nets *)context)->conn_task();
			return NULL;
		}

	private:
		/* TASKS */
		void send_task(void);
		void read_task(void);
		void conn_task(void);

		/* CONNECTION */
		int accept_connection(void);
		int connect_to_server(void);
		void handle_connection_error(void);

		/* DATAS */
		struct nets_data *data_to_send;
		struct nets_data *data_to_read;
		struct nets_header send_header;
		struct nets_header read_header;

		/* CONNECTION STUFFZ */
		int fd;
		int server_fd;

		/* SETTINGS */
		int port;
		char *hostname;
		nets_type type;

		/* STATE */
		bool haz_connection;

		/* CALLBACKS */
		void (*read_callback)(struct nets_data *, void *context);
		void *read_callback_context;
		void (*conn_callback)(void);
};

#endif /* _NETS_H_ */
