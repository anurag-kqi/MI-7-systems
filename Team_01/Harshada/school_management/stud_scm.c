/*School Mnagement Systems*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
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

struct student *chain[size];

//file write functions
void write_stud();
extern void insert_stud(int id, char name[], char class[], char address[], int contact);

//File pointer
//FILE *fptr;
int fptr;
//init array of list to NULL
void init_stud()
{
    int i;
    for(i = 0; i < size; i++) {
        chain[i] = NULL;
    }
}

//Read the student data
// void read_stud()
// {
//     int id, contact;
//     char name[30], class [30], address[50];
//     fptr = fopen("Student.txt", "r");
//     while (( fscanf(fptr, "%d %[^\n]%*c %s %[^\n]%*c %d", &id, name, class, address, &contact)) != EOF) {
//       insert_stud(id, name, class, address, contact);
//       //printf("%d %s %s %s %d\n", id, name, class, address, contact);
//     }
//     fclose(fptr);
// }

//Write the student data
// void write_stud()
// {
//     int i;
//     fptr = (fopen("student.txt", "w+"));
//     for (i = 0; i < size; i++) {
//         struct student *temp = chain[i];
//         //fprintf(fptr,"\tchain[%d]-->", i);
//         while (temp) {
//             fprintf(fptr, " %d\n %s\n %s\n %s\n %d\n", temp->id, temp->name, temp->class, temp->address, temp->contact);
//             temp = temp->next;
//         }
//         //fprintf(fptr,"NULL\n");
//     }
//     fclose(fptr);
// }

//insert values into STUDENT hash table
void insert_stud(int id, char name[], char class[], char address[], int contact)
{
    //create a newnode with value
    fptr = open("Student.txt", O_RDONLY | O_CREAT);
    struct student *newNode = malloc(sizeof(struct student));
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->class, class);
    strcpy(newNode->address, address);
    newNode->contact = contact;
    newNode->next = NULL;
    newNode->prev = NULL;

    write(fptr, newNode, sizeof(newNode));
    close(fptr);

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
    //printf("\n\n\tNode inserted Successfully...!\n");
    //write_stud();
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
        chain[key] = chain[key]->next;
        chain[key]->prev = NULL;
        ptr->next = NULL;
        free(ptr);
	printf("\n\n\tFirst node deleted\n");
    } else {
	while (ptr->next != NULL) {
            if (ptr->next->id == id) {
                toDelete = ptr->next;
                if (toDelete->next == NULL) {
                    ptr->next = NULL;
                    free(toDelete);
		    printf("\n\n\tLast Node is deleted\n");
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
    }
}

//DISPLAY data of STUDENT hash table
void display_stud()
{
    int i;
    for (i = 0; i < size; i++) {
        struct student *temp = chain[i];
        printf("\tchain[%d]-->", i);
        while (temp) {
            printf("%d %s %s %s %d -->", temp->id, temp->name, temp->class, temp->address, temp->contact);
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
                printf("\n\n\tStudent Prev - %p\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d\n\tStudent next - %p", ptr->prev, ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact, ptr->next);
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


//UPDATE student data from STUDENT hash table
void update_stud(int id)
{
    struct student *ptr;
    int i=0, flag,j,digit,alpha;

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
		scanf("\t %[^\n]%*c", name);
		for (j=0; name[j]!= '\0'; j++)
    		{
       		    if (isalpha(name[j]) != 0)
            	        alpha++;

  	      	    else if (isdigit(name[j]) != 0)
            		digit++;
    		}
    		if(alpha == 0 && digit > 0)
    		{
		    printf("Enter characters only\n");
    		} else{
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
		}
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
