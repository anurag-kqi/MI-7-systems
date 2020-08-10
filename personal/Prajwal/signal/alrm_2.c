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
    int status;

    signal(SIGALRM, alarmHandler);
    int pid = fork();
    if(pid == 0) {
        alarm(5);
        for(int i = 1; i < 8; i++) {
            printf("In clild process..%d\n", i);
            sleep(1);
        }
    } else {
        wait(NULL);
        alarm(7);
        for(int i = 1; i < 16; i++) {
            printf("In parent process..%d\n", i);
            sleep(1);
        }
    }

    return 0;
}
