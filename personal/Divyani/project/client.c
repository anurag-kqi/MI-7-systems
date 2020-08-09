//client.c
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include "soc.h"

struct socData soc;
struct socData socd;
int ch, n, num_records = 0, flat_num;
extern void display_soc();

struct visData vis;
struct visData visd;
int num_records2 = 0, vehicle_num;
extern void display_vis();

void error(const char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int display_data;

    //char buffer[1024];
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


    //char owner_name[30], complaints_name[50], suggestions_name[50], visitor_name[30];
    //int flat_num, flat_num1, flat_num2, flat_num3, owner_contact, visitor_contact, TimeIn, TimeOut, water_bill, electricity_bill, new_water_bill, new_electricity_bill, vehicle_num, new_vehicle_num, ch;
    while(1) {
        printf("\n==================================================================");
        printf("\n\t\t MANAGEMENT DATA\n");
        printf("\n\t1. Insert Data\n\t2. Display Data\n\t3. Search Data\n\t4. Update Data\n\t5. Delete Data\n\t6. Exit");
        printf("\n\n\tEnter your choice(1-6) : ");
        scanf("%d", &ch);
        write(sockfd, &ch, sizeof(int));
        switch(ch) {
            case 1:
                    printf("\n==================================================================");
                    printf("\n\t\tINSERT IN TO\n");
                    printf("\n\t1. Society Data\n\t2. Maintenance Data\n\t3. Visitor Data\n\t4. Complaints Data\n\t5. Exit(0)");
                    printf("\n\n\tEnter your choice to insert(1-5):");
                    scanf("%d", &ch);
                    write(sockfd, &ch, sizeof(int));

                    switch(ch)
                    {
                        case 1:
                                printf("\n==================================================================");
                                printf("\n\t\tINSERT SOCIETY DATA\n");
                                printf("Index: %d", num_records);
                                soc.index = num_records;
                                printf("\n\tEnter owner_name : ");
                                scanf("\t\n %[^\n]%*c", soc.owner_name);
                                printf("\n\tEnter flat_num : ");
                                scanf("\t\n%d", &soc.flat_num);
                                printf("\n\tEnter owner_contact : ");
                                scanf("\t\n %d", &soc.owner_contact);

							    write(sockfd, &soc, sizeof(struct socData));
                                num_records++;
    			                break;

                        /*case 2:
                                printf("\n==================================================================");
                                printf("\n\t\tINSERT MAINTENANCE DATA\n");
                                printf("Index: %d", num_records1);
                                maint.index1 = num_records1;
                                printf("\n\tEnter flat_num : ");
                                scanf("\t\n %d", &maint.flat_num1);
                                printf("\n\tEnter water_bill : ");
                                scanf("\t\n %d", &maint.water_bill);
                                printf("\n\tEnter electricity_bill :");
                                scanf("\t\n %d", &maint.electricity_bill);
                                insert_maint(maint);
                                write_maint(maint);
                                num_records1++;
                                break;*/

                        case 3:
                                printf("\n==================================================================");
                                printf("\n\t\tINSERT VISITOR DATA\n");
                                printf("Index: %d", num_records2);
                                vis.index2 = num_records2;
                                printf("\n\tEnter visitor_name : ");
                                scanf("\t\n %[^\n]%*c", vis.visitor_name);
                                printf("\n\tEnter vehicle_num : ");
                                scanf("\t\n%d", &vis.vehicle_num);
                                printf("\n\tEnter visitor_contact : ");
                                scanf("\t\n %d", &vis.visitor_contact);
                                printf("\n\tEnter visitor TimeIn : ");
                                scanf("\t\n %d", &vis.TimeIn);
                                printf("\n\tEnter visitor TimeOut: ");
                                scanf("\t\n %d", &vis.TimeOut);
                                //insert_vis(vis);
                                //write_vis(vis);
																write(sockfd, &vis, sizeof(struct visData));
                                num_records2++;
                                break;

                        /*case 4:
                                printf("\n==================================================================");
                                printf("\n\t\tINSERT COMPLAINT DATA\n");
                                printf("Index: %d", num_records3);
                                com.index3 = num_records3;
                                printf("\n\tEnter complainter's flat_number : ");
                                scanf("\t %d", &com.flat_num3);
                                printf("\n\n\t Enter the complaints_name : ");
                                scanf("\t %[^\n]%*c", com.complaints_name);
                                printf("\n\n\t Enter the suggestions_name : ");
                                scanf("\t %[^\n]%*c", com.suggestions_name);
                                insert_complaints_D(com);
                                write_complaints_D(com);
                                num_records3++;
                                break;*/

                        case 5: exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

            case 2:
                    printf("\n==================================================================");
                    printf("\n\t\tDISPLAY DATA\n");
                    printf("\n\t1. Society Data\n\t2. Maintenance Data\n\t3. Visitor Data\n\t4. Complaint Data\n\t5. Exit(0)");
                    printf("\n\n\tEnter your choice to display(1-4):");
                    scanf("%d", &ch);
					write(sockfd, &ch, sizeof(int));
                    switch(ch)
                    {
                        case 1:
								printf("display...\n");
                                while(1) {
                                    n = read(sockfd, &display_data, sizeof(int));
                                    if (n < 0) {
                                        perror("Read from server failed");
                                        exit(1);
                                    }
                                    if (display_data == 0) {
                                        break;
                                    }
                                    n = read(sockfd, &socd, sizeof(struct socData));
									if (n > 0){
										printf("%s\t%d\t%d\n", socd.owner_name, socd.flat_num, socd.owner_contact);
									}

								}
								break;

                        /*case 2:
                                display_maint();
                                break;*/

                        case 3:
												printf("display...\n");
				                                while(1) {
				                                    n = read(sockfd, &display_data, sizeof(int));
				                                    if (n < 0) {
				                                        perror("Read from server failed");
				                                        exit(1);
				                                    }
				                                    if (display_data == 0) {
				                                        break;
				                                    }
				                                    n = read(sockfd, &socd, sizeof(struct visData));
													if (n > 0){
														printf("%s\t%d\t%d\%d\t%d\n", visd.visitor_name, visd.vehicle_num, visd.visitor_contact, visd.TimeIn,visd.TimeOut);
													}
												}
                                //display_vis();
                                break;

                        /*case 4:
                                display_complaints_D();
                                break;*/

                        case 5:
                                exit(0);

                        default: printf("Wrong Choice!!");
                    }
                    break;

            case 3:
                    printf("\n==================================================================");
                    printf("\n\t\tSEARCH DATA FROM\n");
                    printf("\n\t1. Society Data\n\t2. Maintenance Data\n\t3. Visitor Data\n\t4. Complaint Data\n\t5. Exit(0)");
                    printf("\n\n\tEnter your choice to search(1-3) : ");
                    scanf("\t %d", &ch);
					write(sockfd, &ch, sizeof(int));
                    switch(ch)
                    {
                        case 1:
                                printf("\n==================================================================");
                                printf("\n\n\tEnter flat number for Search : ");
                                scanf("\t%d", &flat_num);
								write(sockfd, &flat_num, sizeof(int));
								read(sockfd, &soc, sizeof(struct socData));
								printf("\n\n\towner_name\t -\t %s\n\tflat_num\t -\t %d\n\towner_contact\t -\t %d\n", soc.owner_name, soc.flat_num, soc.owner_contact);
                                // search_soc(flat_num);
                                break;

                        /*case 2:
                                printf("\n==================================================================");
                                printf("\n\n\tEnter flat number for Search : ");
                                scanf("\t%d", &flat_num1);
                                search_maint(flat_num1);
                                break;*/

                        case 3:
                                printf("\n==================================================================");
                                printf("\n\n\tEnter vehicle_num for search : ");
                                scanf("\t%d",&vehicle_num);
																write(sockfd, &vehicle_num, sizeof(int));
																read(sockfd, &soc, sizeof(struct visData));
																printf("\n\n\tvisitor_name\t -\t %s\n\tvehicle_num\t -\t %d\n\tvisitor_contact\t -\t %d\n\tTimeIn\t -\t %d\n\tTimeOut\t -\t %d\n", vis.visitor_name, vis.vehicle_num, vis.visitor_contact, vis.TimeIn, vis.TimeOut);

                                //search_vis(vehicle_num);
                                break;

                        /*case 4:
                                printf("\n==================================================================");
                                printf("\n\n\tEnter complainter's flat_number for search : ");
                                scanf("\t%d", &flat_num3);
                                search_complaints_D(flat_num3);
                                break;*/

                        case 5:
                                exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

            case 4:
                    printf("\n==================================================================");
                    printf("\n\t\tUPDATE DATA FROM\n");
                    printf("\n\t1. Society Data\n\t2. Maintenance Data\n\t3. Visitor Data\n\t4. Complaint Data\n\t5. Exit(0)");
                    printf("\n\n\tEnter your choice to update(1-5) : ");
                    scanf("\t %d", &ch);
					write(sockfd, &ch, sizeof(int));
                    switch(ch)
                    {
                        case 1:
                                printf("\n\n\tEnter flat number for Update : ");
                                scanf("\t %d", &soc.flat_num);
				        		printf("\n\tEnter New owner Name : ");
				        		scanf("\t %[^\n]%*c", soc.owner_name);
				                printf("\n\tEnter New Contact : ");
				        		scanf("\t %d", &soc.owner_contact);
								write(sockfd, &soc, sizeof(struct socData));
      				            // update_soc(flat_num);
                                break;

                        /*case 2:
                                printf("\n\n\tEnter flat number for Update : ");
                                scanf("\t %d", &flat_num1);
      				            update_maint(flat_num1);
                                break;*/

                        case 3:
                                printf("\n\n\tEnter vehicle number for Update : ");
                                scanf("\t %d", &vehicle_num);
																printf("\n\tEnter New visitor Name : ");
										        		scanf("\t %[^\n]%*c", vis.visitor_name);
										                printf("\n\tEnter New Contact : ");
										        		scanf("\t %d", &vis.visitor_contact);
														write(sockfd, &soc, sizeof(struct socData));
                                //update_vis(vehicle_num);
                                break;

                        /*case 4:
                                printf("\n\n\tEnter flat number for Update : ");
                                scanf("\t %d", &flat_num3);
      				            update_complaints_D(flat_num3);
                                break;*/

                        case 5:
                                exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                        break;

            case 5:
                    printf("\n==================================================================");
                    printf("\n\t\tDELETE DATA FROM\n");
                    printf("\n\t1. Society Data\n\t2. Maintenance Data\n\t3. Visitor Data\n\t4. Complaint Data\n\t5. Exit(0)");
                    printf("\n\n\tEnter your choice to delete(1-5) : ");
                    scanf("\t %d", &ch);
					write(sockfd, &ch, sizeof(int));
                    switch(ch)
                    {
                        case 1:
                                printf("\n\n\tEnter flat  number for Delete : ");
                                scanf("\t %d", &flat_num);
								write(sockfd, &flat_num, sizeof(int));
        				        // delete_soc(flat_num);
                                break;

                        /*case 2:
                                printf("\n\n\tEnter flat  number for Delete : ");
                                scanf("\t %d", &flat_num1);
                                delete_maint(flat_num1);
                                break;*/

                        case 3:
                                printf("\n\n\tEnter vechicle number for Delete : ");
                                scanf("\t %d", &vehicle_num);
																write(sockfd, &vehicle_num, sizeof(int));

                                //delete_vis(vehicle_num);
                                break;

                        /*case 4:
                                printf("\n\n\tEnter flat  number for Delete : ");
                                scanf("\t %d", &flat_num3);
                                delete_complaints_D(flat_num3);
                                break;*/

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
	close(sockfd);
	return 0;
}
