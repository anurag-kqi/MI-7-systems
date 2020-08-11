#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


void signal_catch(int signal) {
    printf("signal caught\n");
}


int main() {
    int ret;

    ret = signal(SIGINT, signal_catch);

    if (ret == SIG_ERR) {
        printf("ERROR:...\n");
        exit(0);
    }
    printf("Going to raise a signal\n");
    ret = raise(SIGINT);

    if (ret != 0) {
        printf("ERROR:\n");
        exit(0);
    }
    printf("Exiting...\n");

    return 0;
}
