#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t mutex;
void *
thr_fn1(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("thread 1 sleeping\n");
    // sleep(2);
    printf("thread 1 now returning\n");
    pthread_mutex_unlock(&mutex);
    return((void *)1);
}
void *
thr_fn2(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("thread 2 exiting\n");
    pthread_exit((void *)2);
    pthread_mutex_unlock(&mutex);
}

int
main(void)
{
    int err;
    pid_t pid;
    pthread_t ntid;
    pthread_t tid1, tid2;
    void *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0) {
        printf("can't create thread 1: %s\n", strerror(err));
        exit(1);
    }
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0) {
        printf("can't create thread 2: %s\n", strerror(err));
        exit(1);
    }

    err = pthread_join(tid1, tret);
    if (err != 0) {
        printf("can't join with thread 1: %s\n", strerror(err));
        exit(1);
    }
    printf("thread 1 exit code 0x%lx\n", (unsigned long)tret);

    err = pthread_join(tid2, tret);
    if (err != 0) {
        printf("can't join with thread 2: %s\n", strerror(err));
        exit(1);
    }

    printf("thread 2 exit code 0x%lx\n", (unsigned long)tret);
    exit(0);
}
