#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void alarmHandler(int signo) {
    printf("Alarm signal Sent!!\n");
}


int main() {
    alarm(5);
    printf("Hello...Calling signal\n");
    signal(SIGALRM, alarmHandler);

    for(int i = 1; i <= 5; i++) {
        printf("%d. \n", i);
        sleep(1);
    }

    return 0;
}
