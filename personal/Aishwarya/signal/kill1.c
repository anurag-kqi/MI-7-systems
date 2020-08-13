#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void handle_sigint(int sig) {
    printf(" Caught signal %d\n", sig);
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);

    while(1) {
        printf("hello_world...\n");
        sleep(1);
    }
    return 0;
}
