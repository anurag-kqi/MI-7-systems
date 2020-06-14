/*School Mnagement Systems...*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 9

struct teacher
{
    int id;
    char name[30];
    char department[30];
    int contact;
    struct teacher *next;
    struct teacher *prev; 
};

struct teacher *chaint[size];

//init array of list to NULL
void init_teacher()
{
    int i;
    for(i = 0; i < size; i++) {
	chaint[i] = NULL;
    }
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


