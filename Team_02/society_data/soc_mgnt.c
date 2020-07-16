#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main menus
extern void menus();

//init array of list to NULL
extern void init_soc();
//extern void init_teacher();
extern void read_soc();
extern void write_soc();
extern void insert_soc();
extern void display_soc();
//extern void delete_soc_file();
int
main()
{
    //init array of list to NULL
    init_soc();
    //init_teacher();
    read_soc();
    write_soc();
    insert_soc();
    display_soc();
    //delete_soc_file();
    //calling main menu function
    menus();

    return 0;
}
