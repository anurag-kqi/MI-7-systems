#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main menus
extern void menus();

//init array of list to NULL
extern void init_maint();
extern void read_maint();

int
main()
{
    //init array of list to NULL
    init_maint();
    read_maint();
    //calling main menu function
    menus();

    return 0;
}
