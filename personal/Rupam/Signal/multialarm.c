#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_handler(int signum){

  printf("Inside handler function\n");
  alarm(2); //schedule alarm after every 2 second
}

int main(){

  signal(SIGALRM,sig_handler); // Register signal handler

  alarm(7);  // Scheduled alarm after 7 seconds
  alarm(3);  // Scheduled alarm after 3 seconds

  for(int i=1;i<=50;i++){

    printf("%d\n",i);
    sleep(1);  // Delay for 1 second
}

return 0;
}
