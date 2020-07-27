#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main menus
extern void menus();

//init array of list to NULL
extern void init_soc();
extern void init_complaints_D();
extern void init_maint();
extern void init_vis();

extern void read_soc();
extern void read_complaints_D();
extern void read_maint();
extern void read_vis();

int
main()
{
    //init array of list to NULL
    init_soc();
    init_maint();
    init_complaints_D();
    init_vis();

    //reading society datafile
    printf("\n==================================================================\n");
    printf("\t\tSOCIETY DATAFILE\n\n");
    read_soc();

    //reading maintenamce datafile
    printf("\n==================================================================\n");
    printf("\t\tMAINTENANCE DATAFILE\n\n");
    read_maint();

    //reading visitor datafile
    printf("\n==================================================================\n");
    printf("\t\tVISITOR DATAFILE\n\n");
    read_vis();

    //reading complaint datafile
    printf("\n==================================================================\n");
    printf("\t\tCOMPLAINT DATAFILE\n\n");
    read_complaints_D();

    //calling main menu function
    menus();

    return 0;
}
