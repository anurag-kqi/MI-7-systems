#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

struct patient_disk pat;
void write_pat(struct patient_disk pat);
void insert_pat(struct patient_disk);

struct doctor_disk ;
extern void write_doc(struct doctor_disk doc);
extern void insert_doc(struct teacher_disk doc);
extern void delete_pat(int id);
extern void delete_doc(int id);
extern void search_pat(int id, int newsockfd);

//main menus
//extern void menus();
extern void display_stud(int sockfd);



//main menus
extern void menus();

//init array of list to NULL
extern void init_pat();
extern void init_doc();

extern void read_pat();
extern void read_doc();
extern int num_record;
extern int num_records;
extern void update_pat(struct patient_disk upsd);
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
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
           error("ERROR on binding");
  listen(sockfd,5);
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
  if (newsockfd < 0)
       error("ERROR on accept");
    //init array of list to NULL
    init_pat();
    //init_doc();

    //reading patient datafile
    printf("\n==================================================================\n");
    printf("\t\tPATIENT DATAFILE\n\n");
    read_pat();

    //reading doctor datafile
    printf("\n==================================================================\n");
    printf("\t\tDOCTOR DATAFILE\n\n");
    read_doc();

    int ch, id, index,contact,j,digit,alpha;
    char name[30], address[50], class[10], department[30];

    do{
            //printf("\n==================================================================");
            //printf("\n\n---- HOSPITAL MANAGEMENT SYSTEM MENU ----\n\n");
            //printf("\n1.PATIENT DATA\n2.DOCTOR DATA\n3.EXIT");
            //printf("\n\nEnter your choice(1-3) : ");
            //scanf("%d", &ch);
            read(newsockfd, &ch, sizeof(int));
            switch(ch){
                case 1:
                        do{
    		                    //printf("\n==================================================================");
                            //printf("\n----PATIENT DEPARTMENT----");
                            //printf("\n\n1.INSERT DATA\n2.DISPLAY DATA\n3.SEARCH DATA\n4.UPDATE DATA\n5.DELETE DATA\n6.EXIT\n\n");
                            //printf("\n\nEnter your choice to insert(1-6):");
                            //scanf("%d", &a);
                            read(newsockfd, &a, sizeof(int));
                            switch(a){
                                case 1:
                                	      //printf("\n==================================================================");
                                        //printf("\n\t\tINSERT PATIENT DATA\n");
                                        read(newsockfd, &pat, sizeof(struct patient_disk));
                                        insert_pat(pat);
                                        write_pat(pat);
                                        num_records++;
        			                          break;

                                case 2:
    				                            printf("\n==================================================================");
                        		            printf("\n---- DISPLAY PATIENT DATA ----\n");
    				                            display_pat(newsockfd);
    				                            break;
                                case 3:
    				                            printf("\n==================================================================");
    				                            printf("\n---- SEARCH PATIENT DATA ----\n");
                                        printf("\n\n\tEnter Patient ID for Search : ");
                                        scanf("\t%d", &id);
                                        search_pat(id);
                                        break;
    			                      case 4:
                                        printf("\n==================================================================");
    				                            printf("\n---- UPDATE PATIENT DATA ----\n");
    		 		                            printf("\n\n\tEnter Patient ID for Update : ");
                                        scanf("\t %d", &id);
                                        read(newsockfd, &pat, sizeof(struct patient_disk));
          				                      update_pat(pat);
                                        break;
    			    case 5:
    				    printf("\n==================================================================");
    				    printf("\n---- DELETE PATIENT DATA ----\n");
    				    printf("\n\n\tEnter Patient ID for  Delete : ");
                                        scanf("\t %d", &id);
            		 	    delete_pat(id);
                                        break;
    				 }
                            }while(a != -1 && a !=6);
    			break;

                case 2:
    		    do{
                            printf("\n----DOCTOR DEPARTMENT----");
                            printf("\n\n1.INSERT DATA\n2.DISPLAY DATA\n3.SEARCH DATA\n4.UPDATE DATA\n5.DELETE DATA\n6.EXIT\n\n");
                            printf("\n\nEnter your choice to insert(1-6):");
                            scanf("%d", &b);
                            switch(b){
    			    case 1:
                                        printf("\n==================================================================");
                                        printf("\n\t\tINSERT DOCTOR DATA\n");
                                        printf("Index: %d", num_record);
                                        doc.index = num_record;
                                        printf("\n\tEnter ID : ");
                                        scanf("\t\n%d", &doc.id);
                                        printf("\n\tEnter Name : ");
                                        scanf("\t\n %[^\n]%*c", doc.name);
                                        printf("\n\tEnter Address : ");
                                        scanf("\t\n %[^\n]%*c", doc.address);
                                        printf("\n\tEnter Contact : ");
                                        scanf("\t\n %d", &doc.contact);
                                        insert_doc(doc);
                                        write_doc(doc);
                                        num_record++;
                                        break;
    			    case 2:
    				    printf("\n==================================================================");
                        		    printf("\n---- DISPLAY PATIENT DATA ----\n");
    				    display_doc();
    				    break;

    			    case 3:
    				    printf("\n==================================================================");
    				    printf("\n---- SEARCH DOCTOR DATA ----\n");
                                        printf("\n\n\tEnter Doctor ID for Search : ");
                                        scanf("\t%d", &id);
                                        search_doc(id);
                                        break;
    			    case 4:
                                        printf("\n==================================================================");
    				    printf("\n---- UPDATE DOCTOR DATA ----\n");
    		 		    printf("\n\n\tEnter Doctor ID for Update : ");
                                        scanf("\t %d", &id);
          				    update_doc(id);
                                        break;
    			    case 5:
    				    printf("\n==================================================================");
    				    printf("\n---- DELETE DOCTOR DATA ----\n");
    				    printf("\n\n\tEnter Doctor ID for  Delete : ");
                                        scanf("\t %d", &id);
            		 	    delete_doc(id);
                                        break;
    				 }
                          }while(b != -1 && b != 6);
    			break;
            }
          }while(ch!= -1 && ch!= 3);


    close(newsockfd);
    close(sockfd);
    return 0;
}
