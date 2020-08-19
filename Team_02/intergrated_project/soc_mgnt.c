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
#include <pthread.h>
#include "soc.h"
void *conn_handlar(void *sock_desc);
struct socData soc;
struct socData socd;
extern void insert_soc(struct socData);
extern void write_soc(struct socData soc);
extern void display_soc(int sockfd);
extern void update_soc(struct socData upsd);
extern void delete_soc(int flat_num);
extern void search_soc(int flat_num, int newsockfd);

struct comData com;
extern void insert_complaints_D(struct comData);
extern void write_complaints_D(struct comData com);
extern void display_complaints_D(int sockfd);
extern void update_complaints_D(struct comData upcd);
extern void delete_complaints_D(int flat_num3);
extern void search_complaints_D(int flat_num3, int newsockfd);

struct maintData maint;
extern void insert_maint(struct maintData);
extern void write_maint(struct maintData maint);
extern void display_maint(int sockfd);
extern void update_maint(struct maintData upmd);
extern void delete_maint(int flat_num1);
extern void search_maint(int flat_num1, int newsockfd);

struct visData vis;
extern void insert_vis(struct visData);
extern void write_vis(struct visData vis);
extern void display_vis(int sockfd);
extern void update_vis(struct visData upvd);
extern void delete_vis(int vehicle_num);
extern void search_vis(int vehicle_num, int newsockfd);

extern void init_soc();
extern void init_maint();
extern void init_vis();
extern void init_complaints_D();

extern void read_soc(int newsockfd);
extern void read_maint(int newsockfd);
extern void read_vis(int newsockfd);
extern void read_complaints_D(int newsockfd);

extern int num_records, num_records1, num_records2, num_records3;

void error(const char *msg) {
	perror(msg);
    printf("Exiting thread %ld\n", pthread_self());
    pthread_exit(NULL);
}

int
main(int argc, char *argv[])
{
    //int i, num_client = 5;

    pthread_t thread;
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    if (argc < 2) {
            fprintf(stderr,"ERROR, no port provided\n");
            exit(1);
    }

		init_soc();
		init_maint();
		init_vis();
		init_complaints_D();

		//reading society datafile
		printf("\n==================================================================\n");
		printf("\t\tSOCIETY DATAFILE\n\n");
		read_soc(newsockfd);

		//reading maintenamce datafile
		printf("\n==================================================================\n");
		printf("\t\tMAINTENANCE DATAFILE\n\n");
		read_maint(newsockfd);

		//reading visitor datafile
		printf("\n==================================================================\n");
		printf("\t\tVISITOR DATAFILE\n\n");
		read_vis(newsockfd);

		//reading complaint datafile
		printf("\n==================================================================\n");
		printf("\t\tCOMPLAINT DATAFILE\n\n");
		read_complaints_D(newsockfd);

      portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		 error("ERROR opening socket");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *) &serv_addr,
					 sizeof(serv_addr)) < 0)
					 error("ERROR on binding");
	listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    printf("Server thread  %ld waiting for accept\n", pthread_self());
		while (1) {
    	newsockfd = accept(sockfd,
    							(struct sockaddr *) &cli_addr,
    							&clilen);
    	if (newsockfd < 0)
    			 error("ERROR on accept");

        if (pthread_create(&thread, NULL, conn_handlar,
                           (void *)&newsockfd) < 0) {
         				perror("could not create thread");
         				return 1;
        }
        printf("Main: New client thread %ld newsockfd %d\n", thread, newsockfd);
    }


	//for (i = 0; i < num_client; i++) {
        //printf("creating thread %d \n", i);
		//if (pthread_create(&thread, NULL, conn_handlar, (void *)portno) < 0) {
				//perror("could not create thread");
				//return 1;
	//	}
	//	sleep(3);
	//}

    printf("Exiting main\n");
	pthread_exit(NULL);
    close(sockfd);

    return 0;
}

void *
conn_handlar(void *arg)
{
	int newsockfd;

    int ch, flat_num, flat_num1, flat_num3, vehicle_num;
    //char owner_name[30], visitor_name[30], complaints_name, suggestions_name;

    newsockfd = *(int *)arg;
    printf("In thread %ld newsockfd %d\n", pthread_self(), newsockfd);

	    while(1)
	    {
			read(newsockfd, &ch, sizeof(int));//main menu choice
 			switch(ch){
 				case 1:
 						read(newsockfd, &ch, sizeof(int));//submenu choice
 						switch(ch) {
 							case 1:
 									write(newsockfd, &num_records, sizeof(int));
 									read(newsockfd, &soc, sizeof(struct socData));
 									insert_soc(soc);
 									write_soc(soc);
 									num_records++;
 									break;

 							case 2:
 									write(newsockfd, &num_records1, sizeof(int));
 									read(newsockfd, &maint, sizeof(struct maintData));
 									insert_maint(maint);
 									write_maint(maint);
 									num_records1++;
 									break;

 							case 3:
 									write(newsockfd, &num_records2, sizeof(int));
 									read(newsockfd, &vis, sizeof(struct visData));
 									insert_vis(vis);
 									write_vis(vis);
 									num_records2++;
 									break;

 							case 4:
 									write(newsockfd, &num_records3, sizeof(int));
 									read(newsockfd, &com, sizeof(struct comData));
 									insert_complaints_D(com);
 									write_complaints_D(com);
 									num_records3++;
 									break;

 							case 5:
 	                                exit(0);

 	                        default: printf("\n\n\tWrong Choice!!\n");
 						}
 						break;

 				case 2:
 						read(newsockfd, &ch, sizeof(int));//submenu choice
 						switch(ch) {
 							case 1:
 									printf("\n==================================================================\n");
 									display_soc(newsockfd);
 									break;

 							case 2:
 									printf("\n==================================================================\n");
 									display_maint(newsockfd);
 									break;

 							case 3:
 									printf("\n==================================================================\n");
 									display_vis(newsockfd);
 									break;

 							case 4:
 									printf("\n==================================================================\n");
 									display_complaints_D(newsockfd);
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
 									printf("\n==================================================================\n");
 									read(newsockfd, &flat_num, sizeof(int));
 									search_soc(flat_num, newsockfd);
 									break;

 							case 2:
 									printf("\n==================================================================\n");
 									read(newsockfd, &flat_num1, sizeof(int));
 									search_maint(flat_num1, newsockfd);
 									break;

 							case 3:
 									printf("\n==================================================================\n");
 									read(newsockfd, &vehicle_num, sizeof(int));
 									search_vis(vehicle_num, newsockfd);
 									break;

 							case 4:
 									printf("\n==================================================================\n");
 									read(newsockfd, &flat_num3, sizeof(int));
 									search_complaints_D(flat_num3, newsockfd);
 									break;

 							case 5:
 	                                exit(0);

 	                        default: printf("\n\n\tWrong Choice!!\n");
 						}
 						break;

 				case 4:
 						read(newsockfd, &ch, sizeof(int));//submenu choice
 						switch (ch) {
 							case 1:
 									printf("\n==================================================================\n");
 									read(newsockfd, &soc, sizeof(struct socData));
 									update_soc(soc);
 									break;

 							case 2:
 									printf("\n==================================================================\n");
 									read(newsockfd, &maint, sizeof(struct maintData));
 									update_maint(maint);
 									break;

 							case 3:
 									printf("\n==================================================================\n");
 									read(newsockfd, &vis, sizeof(struct visData));
 									update_vis(vis);
 									break;

 							case 4:
 									printf("\n==================================================================\n");
 									read(newsockfd, &com, sizeof(struct comData));
 									update_complaints_D(com);
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
 									read(newsockfd, &flat_num, sizeof(int));
 									delete_soc(flat_num);
 									break;

 							case 2:
 									read(newsockfd, &flat_num1, sizeof(int));
 									delete_maint(flat_num1);
 									break;

 							case 3:
 									read(newsockfd, &vehicle_num, sizeof(int));
 									delete_vis(vehicle_num);
 									break;

 							case 4:
 									read(newsockfd, &flat_num3, sizeof(int));
 									delete_complaints_D(flat_num3);
 									break;

 							case 5:
 	                                exit(0);

 	                        default: printf("\n\n\tWrong Choice!!\n");
 						}
 						break;

 				case 6:
 						pthread_exit(NULL);

 					default: printf("\n\n\tWrong Choice!!\n");
		}
	};
    close(newsockfd);
    //return 0;
}
