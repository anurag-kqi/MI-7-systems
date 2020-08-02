#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>



void
main()
{
    int pid;
    int glob = 100;
    struct timeval cur_time;

    gettimeofday(&cur_time, NULL);
    printf("Time in sec %ld\n", cur_time.tv_sec);

    printf("I am parent process\n");


    printf("My id is %d my parent id %d\n", getpid(), getppid());
    if ((server_pid = fork()) == 0) {
        printf("%d pid from fork %d My id is %d my parent id %d\n", __LINE__, pid, getpid(), getppid());
        glob = 200;
        printf("%d glob %d\n", __LINE__, glob);
        sleep(10);
        gettimeofday(&cur_time, NULL);
        printf("Time in sec %ld\n", cur_time.tv_sec);
        exec("./socm", "4000");

    }

    if ((client_pid = fork()) == 0) {
        printf("%d pid from fork %d My id is %d my parent id %d\n", __LINE__, pid, getpid(), getppid());
        exec("./client", "127.0.0.1", "4000");
    }


    ch1pid = wait(&status);
    //which process has completed and why
    ch2pid = wait(&status);
    //which process has completed and why
    




    printf("%d glob %d\n", __LINE__, glob);
    printf("%d Life is good pid %d\n", __LINE__, getpid());
    sleep(10);
}
