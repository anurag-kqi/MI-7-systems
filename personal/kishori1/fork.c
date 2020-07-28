/*Program of printing the even numbers from 1 to 10 using fork*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int
main()
{
  int pid,i;
  pid = fork();
  if (pid == 0) {
  /*parent process*/
    printf("%d fork created...\n", __LINE__);
  }
  else {
  /*child process*/
    printf("%d Parent section...\n", __LINE__);
  }
  printf("Printing the even numbers from 0 to 10\n");
  for(i = 1; i <= 10; i++) {
    while (i % 2 == 0) {
      printf("%d\n", i);
      break;
      return 0;
    }
  }
}
