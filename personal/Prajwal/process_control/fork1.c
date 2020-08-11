#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int
main()
{
    if(fork() == 0)
        printf("Hello from Child..\n");
    else
        printf("Hello from Prarent...\n");

    printf("Over..\n");
    return 0;
}
