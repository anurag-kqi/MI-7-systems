/*School Mnagement Systems*/
#include <ctype.h>
#include "structure.h"
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/stat.h>


//main menus
extern void menus();

//init array of list to NULL
extern void init_stud();
extern void init_teacher();
extern void read_stud();
extern void read_teach();

int
main()
{
 
    int ch, id, index,contact,j,digit,alpha,s, flag;
    char name[30], address[50], class[10], department[30];



    //reading student datafile
    printf("\n_______________________________________________________________________________\n");
    printf("\t\tSTUDENT DATAFILE\n\n");
  //  read_stud();

    //reading teacher datafile
    printf("\n_______________________________________________________________________________\n");
    printf("\t\tTEACHER DATAFILE\n\n");
   // read_teach();

    //calling main menu function
    menus();

    return 0;
}
