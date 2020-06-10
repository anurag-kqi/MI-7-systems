/*School Mnagement Systems*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 9

struct student
{
    int id;
    char name[30];
    char class[10];
    char address[50];
    int contact;
    struct student *next;
    struct student *prev;
};

struct teacher
{
    int id;
    char name[30];
    char department[30];
    int contact;
    struct teacher *next;
    struct teacher *prev;
};

struct student *chain[size];
struct teacher *chaint[size];

//student operations
void insert_stud(int id, char name[], char class[], char address[], int contact);
void display_stud();
void delete_stud(int id);
void update_stud(int id);
void search_stud(int id);

//teacher operations
void insert_teacher(int id, char name[], char department[], int contact);
void display_teacher();
//delete_teacher();
void update_teacher(int id);
void search_teacher(int id);

//init array of list to NULL
void init()
{
    int i;
    for(i = 0; i < size; i++) {
        chain[i] = NULL;
	chaint[i] = NULL;
    }
}

//insert values into STUDENT hash table
void insert_stud(int id, char name[], char class[], char address[], int contact)
{
    //create a newnode with value
    struct student *newNode = malloc(sizeof(struct student));
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->class, class);
    strcpy(newNode->address, address);
    newNode->contact = contact;
    newNode->next = NULL;
    newNode->prev = NULL;

    //calculate hash key
    int key = id % size;

    if (chain[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        chain[key] = newNode;
    } else {
        struct student *temp = chain[key];

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
    printf("\n\n\tNode inserted Successfully...!\n");
}

//insert values into TEACHER hash table
void insert_teacher(int id, char name[], char department[], int contact)
{
    //create a newnode with value
    struct teacher *newNode = malloc(sizeof(struct teacher));
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->department, department);
    newNode->contact = contact;
    newNode->next = NULL;
    newNode->prev = NULL;

    //calculate hash key
    int key = id % size;

    if (chaint[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        chaint[key] = newNode;
    } else {
        struct teacher *temp = chaint[key];

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
    printf("\n\n\tNode inserted Successfully...!\n");
}

//DELETE values from STUDENT hash table
void delete_stud(int id)
{
    int key = id % size;
    struct student *ptr = chain[key], *toDelete;

    if (ptr == NULL) {
        printf("\n\n\tList is Empty !!!\n");
    }
    else if (ptr->id == id) {
<<<<<<< HEAD
        if (ptr->prev == NULL && ptr->next == NULL) {
            free(ptr);
            chain[key] = NULL;
            printf("\n\n\tFirst node id deleted\n");
        } else {
            chain[key] = ptr->next;
            chain[key]->prev = NULL;
            ptr->next = NULL;
            free(ptr);
            printf("\n\n\tFirst node deleted\n");
            return ;
        }

    } else {
	        while (ptr->next != NULL) {
              if (ptr->next->id == id) {
                  toDelete = ptr->next;
                  if (toDelete->next == NULL) {
                      ptr->next = NULL;
                      printf("\n\n\tnode is deleted\n");
                      free(toDelete);
                      return ;
                  } else {
                        ptr->next = toDelete->next;
                        toDelete->next->prev = toDelete->prev;
                        printf("\n\n\tnode is deleted\n");
                        free(toDelete);
                    }
              }
              ptr = ptr->next;
          }
          printf("\n\n\tnode not found\n");
      }
  }
=======
        printf("\n\n\tFirst node deleted\n");
        chain[key] = chain[key]->next;

    } else {
	        while (ptr->next != NULL) {
              if (ptr->next->id == id) {
                printf("node is deleted\n");
                ptr->next = ptr->next->next;
                return;

        chain[key]->prev = NULL;
        ptr->next = NULL;
        free(ptr);
    } else {
	        while (ptr->next != NULL) {
              if (ptr->next->id == id) {
                toDelete = ptr->next;
                if (toDelete->next == NULL) {
                    printf("if loop\n");
                    ptr->next = NULL;
                    printf("\n\n\tnode is deleted\n");
                    free(toDelete);
                    return;
                } else {
                  ptr->next = toDelete->next;
                  toDelete->next->prev = toDelete->prev;
                  printf("\n\n\tnode is deleted\n");
                  free(toDelete);
                }


            }
            ptr = ptr->next;
        }
        printf("\n\n\tnode not found\n");
    }
}



// void delete_stud(int id)
// {
//     int key = id % size;
//     struct student *ptr = chain[key], *toDelete;
//
//     if (ptr == NULL) {
//         printf("\n\n\tList is Empty !!!\n");
//     }
//     else if (ptr->id == id && ptr->next == NULL) {
//
//         ptr = NULL;
//         free(ptr);
//         printf("\n\n\tnode deleted\n");
//     } else {
// 	while (ptr->next != NULL) {
//             if (ptr->next->id == id) {
//
//                 toDelete = ptr->next;
//         	ptr->next = toDelete->next;
//         	toDelete->next->prev = ptr;
//         	free(toDelete);
//             }
//             ptr = ptr->next;
//         }
//         printf("\n\n\tnode deleted successfully\n");
//     }
// }
>>>>>>> 829a4cb5c170660044a3ea72639e2cb382a1c58e


//DISPLAY data of STUDENT hash table
void display_stud()
{
    int i;

    for (i = 0; i < size; i++) {
        struct student *temp = chain[i];
        printf("\tchain[%d]-->",i);
        while (temp) {
            printf("%d %s %s %s %d -->",temp->id, temp->name, temp->class, temp->address, temp->contact);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

//DISPLAY data of TEACHER hash table
void display_teacher()
{
    int i;

    for (i = 0; i < size; i++) {
        struct teacher *temp = chaint[i];
        printf("\tchaint[%d]-->",i);
        while (temp) {
            printf("%d %s %s %d -->",temp->id, temp->name, temp->department, temp->contact);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

//SEARCH Student data from STUDENT hash table
void search_stud(int id)
{
    struct student *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = chain[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {


        while (ptr != NULL) {
            if (ptr->id == id) {
                printf("\n\n\tStudent id found at location %d ", i+1);
                printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d",
                       ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact);
                flag = 0;
                break;
            } else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if (flag==1) {
            printf("\n\n\tStudent id not found\n");
        }
    }
}

//SEARCH teacher data from TEACHER hash table
void search_teacher(int id)
{
    struct teacher *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = chaint[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {


        while (ptr != NULL) {
            if (ptr->id == id) {
                printf("\n\n\tTeacher id found at location %d ", i+1);
                printf("\n\n\tTeacher Id - %d\n\tTeacher Nmae - %s\n\tTeacher Department - %s\n\tTeacher Contact - %d",
                       ptr->id, ptr->name, ptr->department, ptr->contact);
                flag = 0;
                break;
            } else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if (flag==1) {
            printf("\n\n\tTeacher id not found\n");
        }
    }
}

//UPDATE student data from STUDENT hash table
void update_stud(int id)
{
    struct student *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = chain[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {

        while (ptr != NULL) {
            if (ptr->id == id) {
                printf("\n\n\tStudent old Data !!!\n");
                printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d",
                       ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact);

		printf("\n\n\tStudent New Data !!!\n");

		int id, contact;
    		char name[30], class[10], address[50];

		printf("\n\tEnter Same ID : ");
		scanf("\t %d", &id);
		printf("\n\tEnter New Name : ");
		scanf("\t %s", name);
		printf("\n\tEnter New Class : ");
		scanf("\t %s", class);
		printf("\n\tEnter New Address : ");
		scanf("\t %s", address);
		printf("\n\tEnter New Contact : ");
		scanf("\t %d", &contact);

		ptr->id = id;
    		strcpy(ptr->name, name);
    		strcpy(ptr->class, class);
    		strcpy(ptr->address, address);
    		ptr->contact = contact;

		printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d",
                       ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact);
		printf("\n\n\tStudent Record Updated Successfully !!!\n");
                flag = 0;
                break;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr -> next;
        }

        if (flag == 1) {
            printf("\n\n\tStudent id not found\n");
        }
    }
}

//UPDATE teacher data from TEACHER hash table
void update_teacher(int id)
{
    struct teacher *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = chaint[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {

        while (ptr != NULL) {
            if (ptr->id == id) {
                printf("\n\n\tTeacher old Data !!!\n");
                printf("\n\n\tTeacher Id - %d\n\tTeacher Nmae - %s\n\tTeacher Department - %s\n\tTeacher Contact - %d",
                       ptr->id, ptr->name, ptr->department, ptr->contact);

		printf("\n\n\tTeacher New Data !!!\n");

		int id, contact;
    		char name[30], department[30];

		printf("\n\tEnter Same ID : ");
		scanf("\t %d", &id);
		printf("\n\tEnter New Name : ");
		scanf("\t %s", name);
		printf("\n\tEnter New Department : ");
		scanf("\t %s", department);
		printf("\n\tEnter New Contact : ");
		scanf("\t %d", &contact);

		ptr->id = id;
    		strcpy(ptr->name, name);
    		strcpy(ptr->department, department);
    		ptr->contact = contact;

		printf("\n\n\tTeacher Id - %d\n\tTeacher Nmae - %s\n\tTeacher Department - %s\n\tTeacher Contact - %d",
                       ptr->id, ptr->name, ptr->department, ptr->contact);
		printf("\n\n\tTeacher Record Updated Successfully !!!\n");
                flag = 0;
                break;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr -> next;
        }

        if (flag == 1) {
            printf("\n\n\tTeacher id not found\n");
        }
    }

}

int
main()
{
    int ch, id, contact;
    char name[30], address[50], class[10], department[30];

    //init array of list to NULL
    init();

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
