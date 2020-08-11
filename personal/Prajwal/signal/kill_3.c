#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int val = 10;

void handler (int sig) {
    val += 5;
}

int main() {
    pid_t pid;
    signal(SIGCHLD, handler);
    if((pid = fork()) == 0) {
        printf("**** %d, CH parent %d ****\n", getpid(), getppid());
        val -= 3;
        printf("val = %d\n\n", val);
        exit(0);
    }

    waitpid(pid, NULL, 0);
    printf("**** %d, Parent %d ****\n", getpid(), getppid());
    printf("val = %d\n", val);
    exit(0);

    return 0;
}
