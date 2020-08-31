#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int
main()
{
    for(int i=0;i<10;i++) // loop will run n times (n=5)
    {
        if(fork() == 0)
        {
            printf("Child pid: %d Parent pid: %d\n",getpid(),getppid());
            exit(0);
        }
        else
        {
            for(int i=0;i<10;i++)
            {
                wait(NULL);
                // printf("Parent pid %d\n",getpid());
            }
        }
    }

    return 0;
}
