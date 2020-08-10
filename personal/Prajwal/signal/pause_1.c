#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void alarmHandler(int signo) {
    printf("Alarm signal Sent!!\n");
    printf("signal value= %d\n", signo);
}


int main() {
    alarm(7);
    signal(SIGALRM, alarmHandler);

    if(alarm(5) > 0) {
        printf("An alarm has already been set..\n");
    }
    pause();

    printf("We should not see the text..\n");

    return 1;
}
