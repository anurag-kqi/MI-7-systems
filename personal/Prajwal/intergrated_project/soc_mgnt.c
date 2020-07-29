// server.c
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "soc.h"

struct socData soc;
extern void insert_soc(struct socData);
extern void write_soc(struct socData soc);
extern void display_soc();

extern void init_soc();
extern void init_complaints_D();
extern void init_maint();
extern void init_vis();

extern void read_soc();
extern void read_complaints_D();
extern void read_maint();
extern void read_vis();

void error(const char *msg) {
	perror(msg);
	exit(1);
}

int
main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
             error("ERROR on binding");
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,
                (struct sockaddr *) &cli_addr,
                &clilen);
    if (newsockfd < 0)
         error("ERROR on accept");

	 init_soc();
     // init_maint();
     // init_complaints_D();
     // init_vis();

     //reading society datafile
     printf("\n==================================================================\n");
     printf("\t\tSOCIETY DATAFILE\n\n");
     read_soc();

     //reading maintenamce datafile
     printf("\n==================================================================\n");
     printf("\t\tMAINTENANCE DATAFILE\n\n");
     //read_maint();

     //reading visitor datafile
     printf("\n==================================================================\n");
     printf("\t\tVISITOR DATAFILE\n\n");
     //read_vis();

     //reading complaint datafile
     printf("\n==================================================================\n");
     printf("\t\tCOMPLAINT DATAFILE\n\n");
     //read_complaints_D();

    int ch, flat_num, owner_contact;
	char owner_name[30];

	while(1){
		read(newsockfd, &ch, sizeof(int));//main menu choice
		switch(ch){
			case 1:
				read(newsockfd, &ch, sizeof(int));//submenu choice

				switch(ch){
					case 1:
						read(newsockfd, &soc, sizeof(struct socData));
						printf("%d. \t%s\t\t%d\t%d\n", soc.index, soc.owner_name, soc.flat_num, soc.owner_contact);
						insert_soc(soc);
						write_soc(soc);
						break;
				}
				break;

			case 2:
				read(newsockfd, &ch, sizeof(int));//submenu choice

				switch(ch){
					case 1:
						display_soc();
						break;



				}
				break;

		}


	};
    close(newsockfd);
    close(sockfd);
    return 0;
}
