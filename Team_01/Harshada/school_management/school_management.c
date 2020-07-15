#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main menus
extern void menus();

//init array of list to NULL
extern void init_stud();
extern void init_teacher();
extern void read_stud();
extern void delete_stud_file();
int
main()
{
    //init array of list to NULL
    init_stud();
    init_teacher();
    delete_stud_file();
    read_stud();

    //calling main menu function
    menus();

    return 0;
}
