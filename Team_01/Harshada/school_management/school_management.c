/*School Mnagement Systems*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

//main menus
extern void menus();

//init array of list to NULL
extern void init_stud();
extern void init_teacher();

int
main()
{
    //init array of list to NULL
    init_stud();

    init_teacher();

    //calling main menu function
    menus();

    return 0;
}
