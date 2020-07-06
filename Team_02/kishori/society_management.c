/*Society Mnagement Systems*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*main menus*/
extern void menu();
extern void init_society_D();
extern void init_maintenance_D();
extern void init_visitors_D();
extern void init_complaints_D();
extern void read_society_D();
extern void write_society_D();
int
main()
{
    /*init array of list to NULL*/
    init_society_D();
    init_maintenance_D();
    init_visitors_D();
    init_complaints_D();

    read_society_D();
    write_society_D();

    /*calling main menu function*/
    void menu();

    return 0;
}
