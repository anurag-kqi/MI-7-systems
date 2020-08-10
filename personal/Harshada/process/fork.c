#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int
main()
{
    printf("befor fork\n");
    fork();
    printf("middle of fork\n");
    fork();
    printf("after fork\n");
    fork();
    printf("end fork\n");
    return 0;
}
