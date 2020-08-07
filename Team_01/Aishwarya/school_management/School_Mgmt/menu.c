#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include "structure.h"

struct student_disk stud;
struct teacher_disk teach;
int num_records = 0,n;
int num_record = 0;

void error(const char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int sockfd, portno, n;
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



    int ch, id, index = 0,contact,j,digit,alpha,display_data;
    char name[30], address[50], class[10], department[30];

    while (1) {
	    printf("\n_______________________________________________________________________________");
        printf("\n\n\t---- SCHOOL MANAGEMENT SYSTEM MENU ----");
        printf("\n\n\t1.ADD ENTRY\n\t2.DISPLAY DATA\n\t3.DELETE ENTRY\n\t4.UPDATE ENTRY\n\t5.SEARCH ENTRY\n\t6.EXIT\n\n");
        printf("\n\tEnter your choice(1-6) : ");
        scanf("\t %d", &ch);
        write(sockfd, &ch, sizeof(int));
	    printf("\n_______________________________________________________________________________");
        switch (ch) {
            case 1:
                	printf("\n\n\t---- INSERT IN TO ----");
                	printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                	printf("\n\n\tEnter your choice to insert(1-3) : ");
                	scanf("\t %d", &ch);
                	write(sockfd, &ch, sizeof(int));
                	switch (ch) {
                    	case 1:
                            	printf("\n\n\tIndex : %d" ,num_records);
                            	stud.index = num_records;
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
                                	write(sockfd, &stud, sizeof(struct student_disk));
                                	num_records++;
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
										write(sockfd, &teach, sizeof(struct teacher_disk));                         num_record++;
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
                   	write(sockfd, &ch, sizeof(int));
                   	switch (ch)
                   	{
                        case 1:
								printf("\n_______________________________________________________________________________\n\n");
								printf("INDEX.\tSR.\tSTUD_NAME\tCLASS\tADDRESS\t\tCONTACT\n\n");
								while(1) {
                                    n = read(sockfd, &display_data, sizeof(int));
                                    if (n < 0) {
                                        perror("Read from server failed");
                                        exit(1);
                                    }
                                    if (display_data == 0) {
                                        break;
                                    }
                                    n = read(sockfd, &stud, sizeof(struct student_disk));

									if (n > 0){
										printf("%d. ", index);
										printf("\t%d\t%s\t\t%s\t%s\t\t%d\n",  stud.id, stud.name, stud.class, stud.address, stud.contact);
										index++;
									}

								}
                        		break;
                        /*case 2: //display_teach();
								write(sockfd, &teach, sizeof(struct teacher_disk));
                        		break;*/
                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }
            		break;
            case 3:
					printf("\n\n\t---- DELETE FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to delete(1-3) : ");
                    scanf("\t %d", &ch);
                    write(sockfd, &ch, sizeof(int));
                    switch(ch)
                    {
                        case 1:
								printf("\n\n\tEnter Student id for Delete : ");
                                scanf("\t %d", &id);
								write(sockfd, &id, sizeof(int));
								printf("Delete Successful.....\n");
                                break;

                        case 2: printf("\n\n\tEnter Teacher id for Delete : ");
                                scanf("\t %d", &id);
								write(sockfd, &id, sizeof(int));
    				                    // delete_teach(teach.id);
                        		break;

                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

            case 4: printf("\n\n\t---- UPDATE FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to update(1-3) : ");
                    scanf("\t %d", &ch);
					write(sockfd, &ch, sizeof(int));
                    switch(ch)
                    {
                        case 1:
								printf("\n\n\tEnter Student ID for Update : ");
                                scanf("\t %d", &stud.id);
								printf("\n\tEnter Same ID : ");
			                    scanf("\t %d", &stud.id);
			                    printf("\n\tEnter New Name : ");
			                    scanf("\t %[^\n]%*c", stud.name);
			                    printf("\n\tEnter New Class : ");
			                    scanf("\t %s", stud.class);
			                    printf("\n\tEnter New Address : ");
			                    scanf("\t %s", stud.address);
			                    printf("\n\tEnter New Contact : ");
			                    scanf("\t %d", &stud.contact);
								write(sockfd, &stud, sizeof(struct student_disk));
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

  	        case 5: printf("\n\n\t---- SEARCH FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to search(1-3) : ");
                    scanf("\t %d", &ch);
					write(sockfd, &ch, sizeof(int));
                    switch(ch)
                    {
                        case 1:
								printf("\n\n\tEnter Student ID for Search : ");
                                scanf("\t%d", &id);
								write(sockfd, &id, sizeof(int));
								read(sockfd, &stud, sizeof(struct student_disk));
								printf("%d\t%d\t%s\t%s\t%s\t%d\n", stud.index, stud.id, stud.name, stud.class, stud.address, stud.contact);
                                break;
                        /*case 2: printf("\n\n\tEnter Teacher ID for Search : ");
                                scanf("\t%d", &id);
				                        search_teach(id);
                                break;*/
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
