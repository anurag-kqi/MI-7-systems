#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void
main()
{
    int pid;
    int glob = 100;
    printf("I am parent process\n");

    printf("My id is %d my parent id %d\n", getpid(), getppid());
    if ((pid = fork()) == 0) {
        printf("%d pid from fork %d My id is %d my parent id %d\n", __LINE__, pid, getpid(), getppid());
        glob = 200;
        printf("%d glob %d\n", __LINE__, glob);
        sleep(1);
        exit(1);
    } else {
        int status, cpid;
        printf("%d pid from fork %d My id is %d my parent id %d\n", __LINE__, pid, getpid(), getppid());
        printf("%d glob %d\n", __LINE__, glob);
        cpid = wait(&status);
        printf("cpid %d status %d wexitstats %d\n", cpid, status, WEXITSTATUS(status));
        // sleep(10);
    }
    printf("%d glob %d\n", __LINE__, glob);
    printf("%d Life is good pid %d\n", __LINE__, getpid());
    sleep(10);
}
