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

struct maintData maint;
struct maintData maintd;
extern void insert_maint(struct maintData);
extern void write_maint(struct maintData maint);
extern void display_maint();
extern void display1_maint(struct maintData maintd);
extern void update_maint(struct maintData upsd);
extern void delete_maint(int flat_num1);
extern void search_maint(int flat_num1, int newsockfd);

extern void init_maint();
extern void init_complaints_D();
extern void init_maint();
extern void init_vis();

extern void read_maint();
extern void read_complaints_D();
extern void read_maint();
extern void read_vis();

void error(const char *msg) {
	perror(msg);
	exit(1);
}

int a = 10, b = 20, ans;

int
main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    //char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    //int n;
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
    if (newsockfd < 0) {
         error("ERROR on accept");
    }

	printf("ans of add =%d",a+b);
	 init_maint();
     // init_maint();
     // init_complaints_D();
     // init_vis();


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

    int ch, flat_num1;

	while(1){
		printf("Now Next...........\n");
		read(newsockfd, &ch, sizeof(int));//main menu choice
		switch(ch){
			case 1:
					read(newsockfd, &ch, sizeof(int));//submenu choice
					switch(ch) {
						case 1:
								read(newsockfd, &soc, sizeof(struct maintData));
								// printf("%d. \t%s\t\t%d\t%d\n", maint.index, maint.owner_name, maint.flat_num, maint.owner_contact);
								insert_maint(maint);
								write_maint(maint);
								break;
					}
					break;

			case 2:
					read(newsockfd, &ch, sizeof(int));//submenu choice
					switch(ch) {
						case 1:
								display_maint(newsockfd);
								// display1_soc(soc);
								break;
						case 5:
                                exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
	        		}
					break;

			case 3:
					read(newsockfd, &ch, sizeof(int));//submenu choice
					switch(ch) {
						case 1:
								read(newsockfd, &flat_num1, sizeof(int));
								search_maint(flat_num1, newsockfd);

					}
					break;

			case 4:
					read(newsockfd, &ch, sizeof(int));//submenu choice
					switch (ch) {
						case 1:
								read(newsockfd, &maint, sizeof(struct maintData));
								update_maint(maint);

								break;

						case 5:
								exit(0);

						default: printf("\n\n\tWrong Choice!!\n");
					}
					break;

			case 5:
					read(newsockfd, &ch, sizeof(int));//submenu choice
					switch (ch) {
						case 1:
								read(newsockfd, &flat_num1, sizeof(int));
								delete_maint(flat_num1);
								break;

						case 5:
                                exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
					}
					break;

			case 6:
					exit(0);

				default: printf("\n\n\tWrong Choice!!\n");
		}
	};
	// void display1_soc(struct socData socd){
	// 	printf("%s\t%d\t%d", socd.owner_name, socd.flat_num, socd.owner_contact);
	// 	write(newsockfd, &socd, sizeof(struct socData));
	// }

    close(newsockfd);
    close(sockfd);

    return 0;
}
