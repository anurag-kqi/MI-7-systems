#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int
main()
{
    printf("child id %d and parent id %d\n\n", getpid(), getppid());
    fork();
    printf("child id %d and parent id %d\n", getpid(), getppid());
    printf("hello...\n");
    fork();
    printf("child id1 %d and parent id1 %d\n", getpid(), getppid());
    printf("hello 1...\n");
    fork();
    printf("child id1 %d and parent id1 %d\n", getpid(), getppid());
    printf("hello 2...\n");
    // fork();
    // printf("hello...\n");
    // printf("child id is %d and parent id %d\n", getpid(), getppid());
    return 0;
}
