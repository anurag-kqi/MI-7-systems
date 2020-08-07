/*School Mnagement Systems*/
#include "header.h"

struct student_disk stud;
void write_stud(struct student_disk stud);
void insert_stud(struct student_disk);

struct teacher_disk teach;
extern void write_teach(struct teacher_disk teach);
extern void insert_teach(struct teacher_disk teach);
extern void delete_stud(int id);
extern void delete_teach(int id);
extern void search_stud(int id, int newsockfd);

//main menus
//extern void menus();
extern void display_stud(int sockfd);

//init array of list to NULL
extern void init_stud();
extern void init_teacher();
extern void read_stud();
extern void read_teach();
extern int num_record;
extern int num_records;
extern void update_stud(struct student_disk upsd);
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
    //init array of list to NULL
    init_stud();
    //init_teacher();

    //reading student datafile
    printf("\n_______________________________________________________________________________\n");
    printf("\t\tSTUDENT DATAFILE\n\n");
    read_stud();

    //reading teacher datafile
    printf("\n_______________________________________________________________________________\n");
    printf("\t\tTEACHER DATAFILE\n\n");
    read_teach();

    int ch, id, index,contact,j,digit,alpha;
    char name[30], address[50], class[10], department[30];

	while (1) {
        read(newsockfd, &ch, sizeof(int));
        switch (ch) {
            case 1:
                	read(newsockfd, &ch, sizeof(int));
                	switch (ch) {
                    	case 1:
								read(newsockfd, &stud, sizeof(struct student_disk));
								insert_stud(stud);
								write_stud(stud);
                            	break;

                    	case 2:
								read(newsockfd, &teach, sizeof(struct teacher_disk));
								printf("%d\t%d\t%s\t%s\t%d\n", teach.index, teach.id, teach.name, teach.department,teach.contact);
								insert_teach(teach);
								write_teach(teach);
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
								// printf("Start\n");
								display_stud(newsockfd);
                                break;
                        case 2: //display_teach();
                                break;

                        case 3: exit(0);
                        default: printf("\n\n\t2Wrong Choice!!\n");
                    }
                    break;

          	case 3:
                  	read(newsockfd, &ch, sizeof(int));
					// printf("1\n");
                    switch(ch)
                    {
                        case 1:
								// printf("2\n");
								read(newsockfd, &id, sizeof(int));
								// printf("3\n");
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
                        /*case 2:
								printf("\n\n\tEnter Teacher ID for Update : ");
                                scanf("\t %d", &id);
				                update_teach(id);
                                break;*/
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
                        /*case 2: printf("\n\n\tEnter Teacher ID for Search : ");
                                scanf("\t%d", &id);
				                        search_teach(id);
                                break;*/
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
    close(sockfd);
    return 0;
}
