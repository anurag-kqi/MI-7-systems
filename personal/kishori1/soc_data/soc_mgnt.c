#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main menus
extern void menus();

//init array of list to NULL
extern void init_soc();
extern void read_soc();

int
main()
{
    //init array of list to NULL
    init_soc();
    read_soc();
    //calling main menu function
    menus();

    return 0;
}
