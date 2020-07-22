#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
int 
main(int argc, char *argv[])
{
   
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }
    
    int sockfd, portno, n;
    char buff[255];

    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such Host\n");
        exit(1);
    }
 
    bzero((char *) (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: connecting");
    }

    printf("Please enter the message: ");
    bzero(buff, 256);
    fgets(buff, 255, stdin);
    n = write(sockfd, buff, strlen(buff));
    if(n < 0)
    {
        perror("ERROR writing to socket");
    }

    bzero(buff, 256);
    n = read(sockfd, buff, 255);
    if(n < 0)
    {
        perror("ERROR reading from socket");
    }

    printf("%s\n", buff);
       
    return 0;

}
    
