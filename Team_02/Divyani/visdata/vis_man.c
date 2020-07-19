#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main menus
extern void menus();

//init array of list to NULL
extern void init_vis();
extern void read_vis();

int
main()
{
    //init array of list to NULL
    init_vis();
    read_vis();
    //calling main menu function
    menus();

    return 0;
}
