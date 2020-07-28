#include <stdio.h>
#include <unistd.h>

 int
 main()
 {
     int pid;
     int pid1;
     printf("I am parent procss\n");

     printf("My id is %d My parent id %d\n", getpid(), getppid());

     if((pid = fork() == 0))
     {
       printf("%d pid from fork %d my parent id %d\n", pid, getpid(), getppid());
       sleep(30);

     } else {
        printf("%d pid from fork %d my parent id %d\n", pid, getpid(), getppid());
        sleep(30);
     }

     printf("My id1 is %d My parent id1 %d\n", getpid(), getppid());
     if((pid1 = fork() == 0))
     {
       printf("%d pid1 from fork %d my parent id1 %d\n", pid1, getpid(), getppid());
       sleep(30);

     } else {
        printf("%d pid1 from fork %d my parent id1 %d\n", pid1, getpid(), getppid());
        sleep(30);
     }

     return 0;
 }
