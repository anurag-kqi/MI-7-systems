#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define size 1000

struct complaints_D
{
    char complaints_name[50];
    char suggestions_name[50];
    int flat_number;
    int new_flat_number;
    int key;
    struct complaints_D *next3;
    struct complaints_D *prev3;
};
struct complaints_D *root3 = NULL;
int key3;
struct complaints_D *temp3;
struct complaints_D *next3;
struct complaints_D *prev3;

struct complaints_D *arr3[size];

/*file write functions*/
void write_complaintss_D();
extern void insert_complaints_D(int flat_number, char complaints_name[],char suggestions_name[]);

/*File pointer*/
FILE *fptr;

/*init array of list to NULL*/
void init_complaints_D()
{
    int i;
    for(i = 0; i < size; i++) {
        arr3[i] = NULL;
    }
}

/*Read the complaints data*/
void read_complaints_D()
{
    int flat_number;
    char complaints_name[50], suggestions_name[50];
    fptr = fopen("complaints_D.txt", "r");
      while((fscanf(fptr, "%d %[^\n]%*c %[^\n]%*c", &flat_number, complaints_name, suggestions_name) != EOF)) {
        insert_complaints_D(flat_number, complaints_name, suggestions_name);
      }
      fclose(fptr);
}

/*write the complaints data*/
void write_complaints_D()
{
    int i;
    fptr = (fopen("complaints_D.txt", "a+"));
    for (i = 0; i < size; i++) {
        struct complaints_D *temp3 = arr3[i];
        /*fprintf(fptr,"\tchain[%d]-->", i);*/
        while(temp3) {
            fprintf(fptr, "%d %s %s", temp3->flat_number, temp3->complaints_name, temp3->suggestions_name);
            temp3 = temp3->next3;
        }
    }
    fclose(fptr);
}

/*COMPLAINTS INSERTION*/
void insert_complaints_D(int flat_number, char complaints_name[] ,char suggestions_name[])
{
    struct complaints_D* newNode = (struct complaints_D*)malloc(sizeof(struct complaints_D));
    strcpy(newNode->complaints_name, complaints_name);
    strcpy(newNode->suggestions_name, suggestions_name);
    newNode->flat_number = flat_number;

    newNode->next3 = NULL;
    newNode->prev3 = next3;

    key3 = flat_number % size;
    newNode->next3 = NULL;
    newNode->prev3 = NULL;

    if(root3 == NULL) {

        root3 = newNode;
    }
    else {
        struct complaints_D* temp3 = root3;
        while(temp3->next3 != NULL){
            temp3 = temp3->next3;
        }
        temp3->next3 = newNode;
        newNode->prev3 = temp3;
        //newNode->next = NULL;
    }
    printf("Node inserted\n");
}

/* COMPLAINTS DISPLAY*/
void display_complaints_D()
{
    struct complaints_D *temp3;
    temp3 = root3;
    if(temp3!=NULL) {
      while(temp3) {
          printf("%d,%s,%s",temp3->flat_number, temp3->complaints_name, temp3->suggestions_name);
          temp3 = temp3->next3;
      }
}
else {
    printf("complaints data is empty or deleted");
}
}

/*COMPLAINTS SEARCH*/
void search_complaints_D(int flat_number)
{
    int pos = 0;
    if(root3==NULL) {
      printf("Linked List not initialized");
      return;
    }
    prev3 = root3;
    while(prev3!=NULL) {
        pos++;
        if(prev3->flat_number == flat_number) {
          printf("%d found at position %d\n", flat_number, pos);
          printf("\n\tflat_number - %d\n\tcomplaints_name - %s\n\tsuggestions_name - %s",
                 root3->flat_number, root3->complaints_name, root3->suggestions_name);
          return;
        }
        if(prev3->next3 != NULL) {
           prev3 = prev3->next3;
        }
      else {
         break;
      }
    }
}

/*COMPLAINTS UPDATION*/
void update_complaints_D(int flat_number, int new_flat_number)
{
  int pos = 0;

  if(root3 == NULL) {
     printf("Linked List not initialized");
     return;
  }

  prev3 = root3;
  while(prev3 !=NULL) {

     pos++;

     if(prev3->flat_number == flat_number) {
        prev3->flat_number = new_flat_number;
        printf("\n%d found at position %d, replaced with %d\n",flat_number, pos, new_flat_number);
        return;
     }

     if(prev3->next3 != NULL) {
        prev3 = prev3->next3;
     }
     else {
        break;
     }
  }
  printf("%d does not exist in the list\n", flat_number);
}

/*COMPLAINTS DELETION*/
void delete_complaints_D(int flat_number)
{
    int key3 = flat_number % size;
    struct complaints_D *toDelete;
    struct complaints_D *temp3 = arr3[key3];
    if(root3 == NULL) {
        printf("\n List is Empty");
    }
     else if(root3->flat_number == flat_number) {
        root3 = NULL;
       arr3[key3] = NULL;
        free(root3);
        printf("\nnode deleted\n");
    }
    else {
	  while(root3->next3 != NULL) {
        if (root3->next3->flat_number == flat_number) {
          root3 = NULL;
          toDelete = root3->next3;
        	root3->next3 = toDelete->next3;
        	toDelete->next3->prev3 = temp3;
          free(toDelete);
        }
          root3 = root3->next3;
        }
        printf("\nnode deleted successfully\n");
    }
}
