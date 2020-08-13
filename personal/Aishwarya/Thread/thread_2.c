
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int pthread_detach(pthread_t thread);
int pthread_join(pthread_t th, void **thread_return);
int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *), void *arg);

void* func(void* arg)
{

	pthread_detach(pthread_self());

	printf("Inside the thread\n");

	pthread_exit(NULL);
}

void fun()
{
	pthread_t ptid;

	pthread_create(&ptid, NULL, &func, NULL);
	printf("This line may be printed before thread terminates\n");

	if(pthread_equal(ptid, pthread_self())){
		printf("Threads are equal\n");
	}
	else{
		printf("Threads are not equal\n");
	}

	pthread_join(ptid, NULL);

	printf("This line will be printed after thread ends\n");

	pthread_exit(NULL);
}

int main()
{
	fun();
	return 0;
}
