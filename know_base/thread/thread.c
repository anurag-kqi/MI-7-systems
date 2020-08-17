#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

void
printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid,
            (unsigned int)tid, (unsigned int)tid);
}

void *
thr_fn(void *arg)
{
    printids("new thread: ");
    return((void *)0);
}

void *
thr_fn1(void *arg)
{
    int         i;
    pthread_t   tid;
    tid = pthread_self();

    printf("thread 1 sleeping\n");
    for (i = 0; i < 10; i++) {
        count += 5;
        printf("Thread tid %lu count %d\n", tid, count);
        // sleep(2);
    }
    printf("thread 1 now returning\n");
    return((void *)1);
}

void *
thr_fn2(void *arg)
{
    printf("thread 2 exiting\n");
    pthread_exit((void *)2);
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
    err = pthread_create(&tid2, NULL, thr_fn1, NULL);
    if (err != 0) {
        printf("can't create thread 2: %s\n", strerror(err));
        exit(1);
    }

    thr_fn1(NULL);

    err = pthread_join(tid1, &tret);
    if (err != 0) {
        printf("can't join with thread 1: %s\n", strerror(err));
        exit(1);
    }
    printf("thread 1 exit code 0x%lx\n", (unsigned long)tret);
    err = pthread_join(tid2, &tret);
    if (err != 0) {
        printf("can't join with thread 2: %s\n", strerror(err));
        exit(1);
    }
    printf("thread 2 exit code 0x%lx\n", (unsigned long)tret);
    exit(0);

    // err = pthread_create(&ntid, NULL, thr_fn, NULL);
    // if (err != 0) {
    //     printf("can't create thread: %s\n", strerror(err));
    //     exit(1);
    // }
    //
    // pid = getpid();
    // printf("%s pid %u ntid %u (0x%x)\n", "main thread", (unsigned int)pid,
    //         (unsigned int)ntid, (unsigned int)ntid);
    //
    // printids("main thread:");
    // sleep(1);
    // exit(0);
}
