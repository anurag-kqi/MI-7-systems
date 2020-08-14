#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main()
{
    int stat;
    pid_t pid;
    if ((pid = fork()) == 0){
        printf("I am Child\n");
        while(1) ;
    }

    else
    {
        kill(pid, SIGINT);
        wait(&stat);
        if (WIFSIGNALED(stat))
            psignal(WTERMSIG(stat), "Child term due to");
    }
}
