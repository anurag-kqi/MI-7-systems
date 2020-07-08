#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define MAXLINE 1024

int 
main(int argc, char **argv)
{
    int listenfd, connfd;
    char buff[MAXLINE + 1];
    struct sockaddr_in servaddr;
    time_t ticks;

    if (argc != 1) {
        fprintf(stderr, "usage:server \n");
        exit(1);
    }

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13); 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
 
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind error");
        exit(1);
    }
    if (listen(listenfd, 10) < 0) {
        perror("listen failed");
        exit(1);
    }

    for ( ; ;) {
        connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
        if (connfd < 0) {
            perror("accept failed");
            exit(1);
        }
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        if (write(connfd, buff, strlen(buff)) < 0) {
            perror("write failed");
            exit(1);
        }
        fprintf(stdout, "wrote %s\n", buff);
        close(connfd);
    }
 
    exit(0);
}
