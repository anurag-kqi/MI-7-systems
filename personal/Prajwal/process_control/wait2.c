#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int
main()
{
    int stat;
    if(fork() == 0) {
        exit(1);
        printf("Hello from Child..\n");
    } else {
        wait(&stat);
    }
    if(WIFEXITED(stat)) {
        printf("Exit status: %d\n", WEXITSTATUS(stat));
    } else if(WIFSIGNALED(stat)){
        psignal(WIFSIGNALED(stat),"Exit signal");
    }
    printf("Over..\n");
    return 0;
}
