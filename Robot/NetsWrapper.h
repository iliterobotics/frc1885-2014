class NetsWrapper {
	public:
		NetsWrapper();

		void callback_me_maybe(struct nets_data *data);

		int init();
		int send(void *data, size_t len);

	private:
		Nets *nets;

		/* TIDS */
		pthread_t send_tid;
		pthread_t read_tid;
		pthread_t conn_tid;

		/* LOCKS */
		pthread_mutex_t send_lck;
		pthread_mutex_t read_lck;

		/* DATAS */
		struct nets_data send_data;
		struct nets_data read_data;
};

