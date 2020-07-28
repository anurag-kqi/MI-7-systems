#include <unistd.h>
#include <stdio.h>

void
main()
{
    int pid;
    printf("I am parent process\n");

    printf("My id is %d my parent id %d\n", getpid(), getppid());
    if ((pid = fork()) == 0) {
        printf("%d pid from fork %d My id is %d my parent id %d\n", __LINE__, pid, getpid(), getppid());
        sleep(10);
    } else {
        printf("%d pid from fork %d My id is %d my parent id %d\n", __LINE__, pid, getpid(), getppid());
        sleep(10);
    }
    printf("%d Life is good pid %d\n", getpid());
}
