#include "header.h"

struct patient_disk pat;
struct patient_disk pat_data;
struct doctor_disk doc;
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



    int ch, a, b, id, index = 0,contact,j,digit,alpha,display_data;
    char name[30], address[50], class[10], department[30];

    do{
        printf("\n==================================================================");
        printf("\n\n---- HOSPITAL MANAGEMENT SYSTEM MENU ----\n\n");
        printf("\n1.PATIENT DATA\n2.DOCTOR DATA\n3.EXIT");
        printf("\n\nEnter your choice(1-3) : ");
        scanf("%d", &ch);
	write(sockfd, &ch, sizeof(int));
        switch(ch){
            case 1:
                    do{
		        printf("\n==================================================================");
                        printf("\n----PATIENT DEPARTMENT----");
                        printf("\n\n1.INSERT DATA\n2.DISPLAY DATA\n3.SEARCH DATA\n4.UPDATE DATA\n5.DELETE DATA\n6.EXIT\n\n");
                        printf("\n\nEnter your choice to insert(1-6):");
                        scanf("%d", &a);
			write(sockfd, &a, sizeof(int));
                        switch(a){
                            case 1:
                            	    printf("\n==================================================================");
                                    printf("\n\t\tINSERT PATIENT DATA\n");
                                    printf("Index: %d", num_records);
                                    pat.index = num_records;
                                    printf("\n\tEnter ID : ");
                                    scanf("\t\n%d", &pat.id);
                                    printf("\n\tEnter Name : ");
                                    scanf("\t\n %[^\n]%*c", pat.name);
                                    printf("\n\tEnter Age : ");
                                    scanf("\t\n%d", &pat.age);
                                    printf("\n\tEnter Blood Group : ");
                                    scanf("\t\n %[^\n]%*c", pat.bloodgrp);
                                    printf("\n\tEnter Address : ");
                                    scanf("\t\n %[^\n]%*c", pat.address);
                                    printf("\n\tEnter Contact : ");
                                    scanf("\t\n %d", &pat.contact);
                                    printf("\n\tEnter Symptoms : ");
                                    scanf("\t\n %[^\n]%*c", pat.symptoms);
                                    //insert_pat(pat);
                                    //write_pat(pat);
				    write(sockfd, &pat, sizeof(struct patient_disk));
                                    num_records++;
    			            break;

                            case 2:
				    printf("\n==================================================================");
                    		    printf("\n---- DISPLAY PATIENT DATA ----\n");
				    //display_pat();
				    n = read(sockfd, &display_data, sizeof(int));
                                    if (n < 0) {
                                        perror("Read from server failed");
                                        exit(1);
                                    }
                                    if (display_data == 0) {
                                        break;
                                    }
                                    n = read(sockfd, &pat, sizeof(struct patient_disk));
				    printf("%d. ", index);
				    if (n > 0){
					printf("\t%d\t%s\t%d\t%s\t%s\t%d\t%s\n",  pat.id, pat.name, pat.age, pat.bloodgrp, pat.address, 					pat.contact, pat.symptoms);
					}
					index++;
				    }
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
      				    update_pat(id);
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
		close(sockfd);
		return 0;
}
