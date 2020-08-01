
#include "head.h"

struct student_disk std;
struct student *temp;
struct student_disk stud;
struct teacher_disk teach;
int
num_records;
int
num_record;
struct student_exchange{
    // struct student_exchange sed;
    int valid;
};
struct student_exchange sed;

void
error(const char *msg) {
	perror(msg);
	exit(1);
}

int
main(int argc, char *argv[])
{
	int sockfd, newsockfd, portno, n,writefd;
	int ch,i, id, index,contact,j,digit,alpha;
	char name[30], address[50], class[10], department[30];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];
    if (argc < 3)
    {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

	// int ch, id, index,contact;

    while (1) {
        printf("\n_______________________________________________________________________________");
        printf("\n\n\t---- SCHOOL MANAGEMENT SYSTEM MENU ----");
        printf("\n\n\t1.ADD ENTRY\n\t2.DISPLAY DATA\n\t3.DELETE ENTRY\n\t4.UPDATE ENTRY\n\t5.SEARCH ENTRY\n\t6.EXIT\n\n");
        printf("\n\tEnter your choice(1-6) : ");
        scanf("\t %d", &ch);
        write(sockfd, &ch, sizeof(ch));
	      printf("\n_______________________________________________________________________________");
        switch (ch) {
            case 1:
                printf("\n\n\t---- INSERT IN TO ----");
                printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                printf("\n\n\tEnter your choice to insert(1-3) : ");
                scanf("\t %d", &ch);
                write(sockfd, &ch, sizeof(ch));
                switch (ch) {
                    case 1:
                            printf("\n\n\tIndex : %d" ,num_records);
                            stud.index = num_records;
                            //scanf("\t %d", &stud.index);
                        		printf("\n\n\tEnter ID : ");
                        		scanf("\t %d", &stud.id);
                        		printf("\n\tEnter Name : ");
                        		scanf("\t %[^\n]%*c", stud.name);
					                  for (j=0; stud.name[j]!= '\0'; j++)
    				                {
       		    		              if (isalpha(stud.name[j]) != 0)
            	        		          alpha++;

  	      	    		            else if (isdigit(stud.name[j]) != 0)
            				                digit++;
    				                }
    				                if(alpha == 0 && digit > 0)
    				                {
		    		                    printf("Enter characters only\n");
    				                } else{

                        		    printf("\n\tEnter Class : ");
                        		    scanf("\t %s", stud.class);
                        		    printf("\n\tEnter Address : ");
                        		    scanf("\t %[^\n]%*c", stud.address);
                                printf("\n\tEnter Contact : ");
                        		    scanf("\t %d", &stud.contact);
                                //send(s,(const char*)&stud,sizeof(struct student_disk),0);
                                write(sockfd, &stud, sizeof(struct student_disk));
                                //insert_stud(stud);
                                //write_stud(stud);
                                // num_records++;
								printf("\n\tYour DATA RECORDED successful");
                            }
                            break;
                    case 2:
									printf("\n\n\tIndex : %d" ,num_record);
		                            teach.index = num_record;
							                  printf("\n\n\tEnter ID : ");
		                        		scanf("\t %d", &teach.id);
		                        		printf("\n\tEnter Name : ");
		                        		scanf("\t %[^\n]%*c", teach.name);
		                            for (j=0; teach.name[j]!= '\0'; j++)
		    				                {
		       		    		              if (isalpha(teach.name[j]) != 0)
		            	        		          alpha++;

		  	      	    		            else if (isdigit(teach.name[j]) != 0)
		            				                digit++;
		    				                }
		    				                if(alpha == 0 && digit > 0)
		    				                {
				    		                    printf("Enter characters only\n");
		    				                } else{

		                        		    printf("\n\tEnter Department : ");
                        		    scanf("\t %[^\n]%*c", teach.department);
                        		    printf("\n\tEnter Contact : ");
                        		    scanf("\t %d", &teach.contact);
																write(sockfd, &teach, sizeof(struct teacher_disk));
                        		    //insert_teach(teach);
			                          //write_teach(teach);
                                // num_record++;
																printf("\n\tYour DATA RECORED successful");
                                }
                            break;
                    case 3: exit(0);
                    default: printf("\n\n\tWrong Choice!!\n");
                }
            break;
           case 2:
					          printf("\n\n\t---- DISPLAY DATA ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to display(1-3) : ");
                    scanf("\t%d", &ch);
              			write(sockfd, &ch, sizeof(ch));
                    switch (ch)
                    {
											// read(newsockfd, &ch, sizeof(ch));

                        case 1:
                                     // display_stud();
                                         read(sockfd, &temp->std, sizeof(struct student_disk));
										 // display_stud(w);
										 // printf("%d\n",sed.valid );
										 printf("%d\t%d\t%s\t%s\t%s\t%d\n", temp->std.index, temp->std.id, temp->std.name, temp->std.class, temp->std.address, temp->std.contact);
                  // read(sockfd, &display_stud, sizeof(void display_stud));
                                break;
                        case 2: //display_teach();
                                break;
                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;
            case 3:
						        printf("\n\n\t---- DELETE FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to delete(1-3) : ");
                    scanf("\t %d", &ch);
                    write(sockfd, &ch, sizeof(ch));
                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter Student id for Delete : ");
                                scanf("\t %d", &stud.id);
    				                   	write(sockfd, &stud.id, sizeof(stud.id));
                                break;

                        case 2: printf("\n\n\tEnter Teacher id for Delete : ");
                                scanf("\t %d", &teach.id);
																write(sockfd, &stud.id, sizeof(stud.id));
                                break;

                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

           case 4:
					          printf("\n\n\t---- UPDATE FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to update(1-3) : ");
                    scanf("\t %d", &ch);
                    write(sockfd, &ch, sizeof(ch));
                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter Student ID for Update : ");
                                scanf("\t %d", &id);
                                write(sockfd, &id, sizeof(id));
				                 //       update_stud(id);
                                break;
                        case 2: printf("\n\n\tEnter Teacher ID for Update : ");
                                scanf("\t %d", &id);
                                write(sockfd, &id, sizeof(id));
				                   //     update_teach(id);
                                break;
                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

  	        case 5:
						        printf("\n\n\t---- SEARCH FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to search(1-3) : ");
                    scanf("\t %d", &ch);
              	    write(sockfd, &ch, sizeof(ch));
                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter Student ID for Search : ");
                                scanf("\t%d", &id);
                                write(sockfd, &id, sizeof(id));
			       //  search_stud(id);
                                break;
                        case 2: printf("\n\n\tEnter Teacher ID for Search : ");
                                scanf("\t%d", &id);
                                write(sockfd, &id, sizeof(id));
			         //search_teach(id);
                                break;
                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

          case 6: exit(0);
      	  default: printf("\n\n\tWrong Choice!!\n");
        }
    };
		close(sockfd);
		return 0;
}
