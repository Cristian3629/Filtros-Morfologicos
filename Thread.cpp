#include "Thread.h"
#include <iostream> //cout

void* Thread::starter(void* args){
	Thread* thread = (Thread*)args;
	thread->run_func(thread->run_data);
	return NULL;
}

Thread::Thread(thread_run_func_t run_func, thread_run_data_t run_data) {
	this->run_func = run_func;
	this->run_data = run_data;
}

void Thread::destroy(){
}

void Thread::start() {
	//this es el dato
	//starter es la funcion
	pthread_create(&this->thread, NULL, starter, this);
}

void Thread::join(void** result){
	pthread_join(this->thread,result);
}

Thread::~Thread(){}
