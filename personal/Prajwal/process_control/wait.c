#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int
main()
{
    pid_t cpid;
    printf("check\n");
    if(fork() == 0) {
        exit(0);
        printf("Hello from Child..\n");
    } else {
        cpid = wait(NULL);
        printf("parent pid:  %d\n", getpid());
        printf("Child pid: %d\n", cpid);
    }
    printf("Over..\n");
    return 0;
}
