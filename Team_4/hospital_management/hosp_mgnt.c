#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main menus
extern void menus();

//init array of list to NULL
extern void init_pat();
extern void init_doc();

extern void read_pat();
extern void read_doc();

int
main()
{
    //init array of list to NULL
    init_pat();
    init_doc();

    //reading patient datafile
    printf("\n==================================================================\n");
    printf("\t\tPATIENT DATAFILE\n\n");
    read_pat();

    //reading doctor datafile
    printf("\n==================================================================\n");
    printf("\t\tDOCTOR DATAFILE\n\n");
    read_doc();

    //calling main menu function
    menus();

    return 0;
}
