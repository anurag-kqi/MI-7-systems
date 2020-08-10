#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if(pid == 0) {
        while(1) {
            printf("hello world...\n");
            usleep(50000);
        }
    } else {
        sleep(1);
        kill(pid, SIGKILL);
        wait(NULL);
        printf("Im the parent\n");
    }

    return 0;
}
