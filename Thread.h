#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

typedef void* thread_run_data_t;
typedef void* (*thread_run_func_t)(thread_run_data_t run_data);

class Thread{
	pthread_t thread;
	thread_run_func_t run_func;
	thread_run_data_t run_data;
public:
	Thread(thread_run_func_t run_func, thread_run_data_t run_data);
	void destroy();
	void start();
	void join(void** result);
	virtual ~Thread();
	static void* starter(void* args);
};

#endif /*THREAD_H_*/
