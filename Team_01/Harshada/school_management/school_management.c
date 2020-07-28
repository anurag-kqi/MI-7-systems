/*School Mnagement Systems*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    //init array of list to NULL
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

    //calling main menu function
    menus();

    return 0;
}
