/*School Mnagement Systems*/
#include "head.h"

struct student_disk stud;
void write_stud(struct student_disk stud);
void insert_stud(struct student_disk);

struct teacher_disk teach;
extern void write_teach(struct teacher_disk);
extern void insert_teach(struct teacher_disk teach);
extern void delete_teach_file(struct teacher_disk teach_data);
extern void delete_stud(int id);
extern void delete_teach(int id);
extern void delete_stud_file(struct student_disk stud_data);
//main menus
//extern void menus();
extern void display_stud();
extern void display_teach();
//init array of list to NULL
extern void init_stud();
extern void init_teacher();
extern void read_stud();
extern void read_teach();
extern int num_record;
extern int num_records;

extern void update_stud_file(struct student_disk stu_data);
extern void update_stud(int id);
extern void update_teach(int id);

extern void search_stud(int id);
extern void search_teach(int id);


void update_teach_file(struct teacher_disk tea_data);
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
	      printf("\n_______________________________________________________________________________");
        printf("\n\n\t---- SCHOOL MANAGEMENT SYSTEM MENU ----\n\n");
        read(newsockfd, &ch, sizeof(ch));

        switch (ch) {
            case 1:
                read(newsockfd, &ch, sizeof(ch));
                switch (ch) {
                    case 1:
                      printf("NewStudent Data Has Been Added Successfully!!!\n\n");
                      read(newsockfd, &stud, sizeof(struct student_disk));
			                printf("\n\tINDEX : %d\n\tID : %d\n\tNAME : %s\n\tCLASS : %s\n\tADDRESS : %s\n\tCONTACT_NO : %d\n", stud.index, stud.id, stud.name, stud.class, stud.address, stud.contact);
			                insert_stud(stud);
									    write_stud(stud);
									    num_records++;
										//}
					          //read_stud();	    }
                      printf("\n_______________________________________________________________________________\n");
				              printf("\t\tSTUDENT DATAFILE\n\n");
				              read_stud();
                       break;
                   case 2:
                       printf("New teacher Data Has Been Added Successfully!!!");
            			     read(newsockfd, &teach, sizeof(struct teacher_disk));
                       printf("\n\tINDEX : %d\n\tID : %d\n\tNAME : %s\n\tDEPARTMMENT : %s\n\tCONTACT %d", teach.index, teach.id, teach.name, teach.department, stud.contact);
									     insert_teach(teach);
									     write_teach(teach);
									     num_records++;

									     printf("\n_______________________________________________________________________________\n");
									     printf("\t\tTEACHER DATAFILE\n\n");
									     read_teach();
						            break;
                    case 3: exit(0);
                            default: printf("\n\n\tWrong Choice!!\n");
                     }
                 break;
            case 2:
			               	read(newsockfd, &ch, sizeof(int));//submenu choice
                      switch (ch)
                          {
                          case 1:display_stud();
                                //  write(newsockfd, &display_stud, sizeof(void display_stud));
                                break;
                          case 2: display_teach();
                                break;
                          case 3: exit(0);
                          default: printf("\n\n\tWrong Choice!!\n");
                           }
													 write(sockfd, &ch, sizeof(int));//submenu choice

                      break;
             case 3:
                      read(newsockfd, &ch, sizeof(int));//submenu choice
                      switch(ch)
                           {
                        case 1: //printf("\n\n\tEnter Student id for Delete : ");
                         				read(newsockfd, &stud.id, sizeof(stud.id));//submenu choice
    				                    delete_stud(stud.id);
																printf("Your DATA HAS BEEN DELETED ");
                                break;

                        case 2: //printf("\n\n\tEnter Teacher id for Delete : ");
 																read(newsockfd, &teach.id, sizeof(teach.id));
    				                    delete_teach(teach.id);
																printf("Your DATA HAS BEEN DELETED ");
                                break;

                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }

																				printf("\n_______________________________________________________________________________\n");
																		    printf("\t\tSTUDENT DATAFILE\n\n");
																		    read_stud();
																				printf("\n_______________________________________________________________________________\n");
																				printf("\t\tTEACHER DATAFILE\n\n");
																				read_teach();
                    break;

           case 4:
					              read(newsockfd, &ch, sizeof(int));//submenu choice
                        switch(ch)
                         {
                        case 1:
                        //      read(newsockfd, &id, sizeof(id));

				                        update_stud(id);
                                break;
                        case 2:         // read(newsockfd, &id, sizeof(id));
                                update_teach(id);
                                break;
                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                     }
                     break;

            case 5:
              	         read(newsockfd, &ch, sizeof(ch));
                         switch(ch)
                          {
                          case 1:
													         read(newsockfd, &id, sizeof(id));
                                   search_stud(id);
                                   break;
                        case 2: 	 read(newsockfd, &id, sizeof(id));
                                   search_teach(id);
                                    break;
                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }

										printf("\n_______________________________________________________________________________\n");
								    printf("\t\tSTUDENT DATAFILE\n\n");
								    read_stud();
										printf("\n_______________________________________________________________________________\n");
										printf("\t\tTEACHER DATAFILE\n\n");
										read_teach();
                    break;

          }
   }

    close(newsockfd);
    close(sockfd);
    return 0;
}
