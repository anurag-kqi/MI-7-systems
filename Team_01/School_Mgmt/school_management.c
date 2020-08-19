/*School Mnagement Systems*/
#include "header.h"

void *conn_handlar(void *sock_desc);

struct student_disk stud;
extern void write_stud(struct student_disk stud);
extern void insert_stud(struct student_disk);
extern void display_stud(int sockfd);
extern void update_stud(struct student_disk upsd);
extern void delete_stud(int id);
extern void search_stud(int id, int newsockfd);

struct teacher_disk teach;
extern void write_teach(struct teacher_disk teach);
extern void insert_teach(struct teacher_disk teach);
extern void display_teach(int sockfd);
extern void delete_teach(int id);
extern void search_teach(int id, int newsockfd);
extern void update_teach(struct teacher_disk uptd);

//main menus
//extern void menus();

//init array of list to NULL
extern void init_stud();
extern void init_teacher();
extern void read_stud();
extern void read_teach();
extern int num_record;
extern int num_records;

void error(const char *msg) {
	perror(msg);
    printf("Exiting thread %ld\n", pthread_self());
    pthread_exit(NULL);
}

int
main(int argc, char *argv[])
{
    int num_client = 5;
	int sock_desc, i;
    pthread_t thread;
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    if (argc < 2) {
            fprintf(stderr,"ERROR, no port provided\n");
            exit(1);
    }

    init_stud();
	init_teacher();

	//reading student datafile
	printf("\n_______________________________________________________________________________\n");
	printf("\t\tSTUDENT DATAFILE\n\n");
	read_stud();

	//reading teacher datafile
	printf("\n_______________________________________________________________________________\n");
	printf("\t\tTEACHER DATAFILE\n\n");
	read_teach();

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


	// for (i = 0; i < num_client; i++) {
    //     printf("creating thread %d \n", i);
	// 	if (pthread_create(&thread, NULL, conn_handlar, (void *)portno) < 0) {
	// 			perror("could not create thread");
	// 			return 1;
	// 	}
	// 	sleep(3);
	// }

    printf("Exiting main\n");
	pthread_exit(NULL);
    close(sockfd);

    return 0;
}

void *
conn_handlar(void *arg)
{
	int newsockfd;
	char buffer[1024];
	int n;
    int ch, id, index,contact,j,digit,alpha;
    char name[30], address[50], class[10], department[30];

    newsockfd = *(int *)arg;
    printf("In thread %ld newsockfd %d\n", pthread_self(), newsockfd);
	//init array of list to NULL

	while (1) {
		read(newsockfd, &ch, sizeof(int));
		switch (ch) {
			case 1:
								read(newsockfd, &ch, sizeof(int));
								switch (ch) {
								case 1:
								write(newsockfd, &num_records, sizeof(int));
								read(newsockfd, &stud, sizeof(struct student_disk));
								insert_stud(stud);
								write_stud(stud);
								num_records++;
								break;

								case 2:
								write(newsockfd, &num_record, sizeof(int));
								read(newsockfd, &teach, sizeof(struct teacher_disk));
								insert_teach(teach);
								write_teach(teach);
								num_record++;
															break;

											case 3: exit(0);

											default: printf("\n\n\t1Wrong Choice!!\n");
									}
									break;

						case 2:
					printf("\n\n\t---- DISPLAY DATA ----");
										read(newsockfd, &ch, sizeof(int));
										switch (ch) {
												case 1:
								display_stud(newsockfd);
																break;
												case 2: display_teach(newsockfd);
																break;

												case 3: exit(0);

												default: printf("\n\n\t2Wrong Choice!!\n");
										}
										break;

						case 3:
										read(newsockfd, &ch, sizeof(int));
										switch(ch)
										{
												case 1:
								read(newsockfd, &id, sizeof(int));
												delete_stud(id);
																break;

												case 2:
								read(newsockfd, &id, sizeof(int));
												delete_teach(id);
																break;

												case 3: exit(0);

												default: printf("\n\n\tWrong Choice!!\n");
										}
										break;

						case 4:
					read(newsockfd, &ch, sizeof(int));
										switch(ch)
										{
												case 1:
								read(newsockfd, &stud, sizeof(struct student_disk));
												update_stud(stud);
																break;
												case 2:
								read(newsockfd, &teach, sizeof(struct teacher_disk));
												update_teach(teach);
																break;

												case 3: exit(0);

												default: printf("\n\n\tWrong Choice!!\n");
										}
										break;

						case 5:
					read(newsockfd, &ch, sizeof(int));
										switch(ch)
										{
												case 1:
								read(newsockfd, &id, sizeof(int));
												search_stud(id,newsockfd);
																break;

												case 2:
								read(newsockfd, &id, sizeof(int));
												search_teach(id,newsockfd);
																break;

												case 3: exit(0);

												default: printf("\n\n\tWrong Choice!!\n");
										}
										break;

						case 6:
					exit(0);

							default: printf("\n\n\t3Wrong Choice!!\n");
				}
		};


		close(newsockfd);

}
