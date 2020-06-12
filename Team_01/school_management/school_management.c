/*School Mnagement Systems*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 9
	
//student operations.
extern void insert_stud(int id, char name[], char class[], char address[], int contact);
extern void display_stud();
extern void delete_stud(int id);
extern void update_stud(int id);
extern void search_stud(int id);

//teacher operations
extern void insert_teacher(int id, char name[], char department[], int contact);
void display_teacher();
//extern delete_teacher();
extern void update_teacher(int id);
extern void search_teacher(int id);

//init array of list to NULL
extern void init_stud();
extern void init_teacher();

int 
main()
{
    int ch, id, contact;
    char name[30], address[50], class[10], department[30];

    //init array of list to NULL
    init_stud();
    init_teacher();

    while (1) {
	printf("\n_______________________________________________________________________________");
        printf("\n\n\t---- SCHOOL MANAGEMENT SYSTEM MENU ----");
        printf("\n\n\t1.ADD ENTRY\n\t2.DISPLAY DATA\n\t3.DELETE ENTRY\n\t4.UPDATE ENTRY\n\t5.SEARCH ENTRY\n\t6.EXIT\n\n");
        printf("\n\tEnter your choice(1-6) : ");
        scanf("\t %d", &ch);
	printf("\n_______________________________________________________________________________");
        switch (ch) {
            case 1:
                    printf("\n\n\t---- INSERT IN TO ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to insert(1-3) : ");
                    scanf("\t %d", &ch);
 
                    switch (ch)
                    {
                        case 1: printf("\n\n\tEnter ID : ");
				scanf("\t %d", &id);
				printf("\n\tEnter Name : ");
				scanf("\t %s", name);
				printf("\n\tEnter Class : ");
				scanf("\t %s", class);
				printf("\n\tEnter Address : ");
				scanf("\t %s", address);
				printf("\n\tEnter Contact : ");
				scanf("\t %d", &contact);
				insert_stud(id, name, class, address, contact);
                                break;

                        case 2: printf("\n\n\tEnter ID : ");
				scanf("\t %d", &id);
				printf("\n\tEnter Name : ");
				scanf("\t %s", name);
				printf("\n\tEnter Department : ");
				scanf("\t %s", department);
				printf("\n\tEnter Contact : ");
				scanf("\t %d", &contact);
				insert_teacher(id, name, department, contact);
                                break;

                        case 3: exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;
 
            case 2: printf("\n\n\t---- DISPLAY DATA ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to display(1-3) : ");
                    scanf("\t%d", &ch);
 
                    switch (ch)
                    {
                        case 1: display_stud();
                                break;

                        case 2: display_teacher();
                                break;

                        case 3: exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;
 
            case 3: printf("\n\n\t---- DELETE FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to delete(1-3) : ");
                    scanf("\t %d", &ch);
 
                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter Student ID for Delete : ");
                                scanf("\t %d", &id);
				delete_stud(id);
                                break;
                        //case 2: delete_teacher();
                                //break;
                        case 3: exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

           case 4: printf("\n\n\t---- UPDATE FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to update(1-3) : ");
                    scanf("\t %d", &ch);
 
                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter Student ID for Update : ");
                                scanf("\t %d", &id);
				update_stud(id);
                                break;

                        case 2: printf("\n\n\tEnter Teacher ID for Update : ");
                                scanf("\t %d", &id);
				update_teacher(id);
                                break;
                        case 3: exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

	    case 5: printf("\n\n\t---- SEARCH FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to search(1-3) : ");
                    scanf("\t %d", &ch);
 
                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter Student ID for Search : ");
                                scanf("\t%d", &id);
				search_stud(id);
                                break;

                        case 2: printf("\n\n\tEnter Teacher ID for Search : ");
                                scanf("\t%d", &id);
				search_teacher(id);
                                break;
                        case 3: exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

            case 6: exit(0);
                    
	    default: printf("\n\n\tWrong Choice!!\n");
        }
    }
    return 0;
}
