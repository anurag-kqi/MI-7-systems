#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int 
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "ERROR: No Port Provided");
        exit(1);
    }
    
    int sockfd, newsockfd, portno, n;
    char buff[255];

    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno); 
    
    if (bind(sockfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind error");
        exit(1);
    }
    
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr, &clilen);

    if (newsockfd < 0)
    {
        perror("accept error");
    }

    bzero(buff, 256);

    n = read(newsockfd, buff, 255);
 
    if(n < 0)
    {
        perror("ERROR reading from socket");
    }

    printf("Here is the message: %s\n", buff);

    n = write(newsockfd, "I got your message", 18);

    if(n < 0)
    {
        perror("ERROR writing from socket");
    }
   
    return 0;
}
    
