/*School Mnagement Systems*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "structure.h"

struct student_disk stud;
void write_stud(struct student_disk stud);
void insert_stud(struct student_disk);

struct teacher_disk teach;
extern void write_teach(struct teacher_disk teach);
extern void insert_teach(struct teacher_disk teach);
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

    read(newsockfd, &stud, sizeof(struct student_disk));
    printf("%d\t%d\t%s\t%s\t%s\t%d\n", stud.index, stud.id, stud.name, stud.class, stud.address, stud.contact);
    insert_stud(stud);
    write_stud(stud);
    num_records++;

    read(newsockfd, &teach, sizeof(struct teacher_disk));
		printf("%d\t%d\t%s\t%s\t%d\n", teach.index, teach.id, teach.name, teach.department,teach.contact);
		insert_teach(teach);
    write_teach(teach);
    num_record++;

    close(newsockfd);
    close(sockfd);
    return 0;
}
