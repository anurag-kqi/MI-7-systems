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
extern void read_maintenance_D();
extern void read_visitors_D();
extern void read_complaints_D();

extern void write_society_D();
extern void write_maintenance_D();
extern void write_visitors_D();
extern void write_complaints_D();

int
main()
{
    /*init array of list to NULL*/
    init_society_D();
    init_maintenance_D();
    init_visitors_D();
    init_complaints_D();

    read_society_D();
    read_maintenance_D();
    read_visitors_D();
    read_complaints_D();

    //write_society_D();
    write_maintenance_D();
    write_visitors_D();
    write_complaints_D();

    /*calling main menu function*/
    void menu();

    //return 0;
}
