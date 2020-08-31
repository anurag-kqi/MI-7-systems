#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int
main()
{
    // fork();
    printf("Hello....\n");
    if(fork() == 0)
    {
         printf("Hello From Child => PPID: %d PID: %d\n", getppid(), getpid());
    }
    else
    {
        wait(NULL);
        printf("Hello From Parent => PID: %d\n", getpid());
    }


    return 0;
}
