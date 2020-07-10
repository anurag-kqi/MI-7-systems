/*Society data*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define size 1000

struct society_D
{
    char owner_name[30];
    int flat_num;
    int new_flat_num;
    int owner_contact;
    int key;
    struct society_D *next;
    struct society_D *prev;
};
struct society_D *root = NULL;
int key;
struct society_D *temp;
struct society_D *next;
struct society_D *prev;
struct society_D *current;

struct society_D *arr[size];
<<<<<<< HEAD
void insert_society_D(char owner_name[], int flat_num, int owner_contact);
void display_society_D();
void search_society_D(int flat_num);
void update_society_D(int flat_num, int new_flat_num);
void delete_society_D(int flat_num);
=======
extern void insert_society_D(char owner_name[], int flat_num, int owner_contact);

/*File pointer*/
FILE *fptr;
>>>>>>> 1809af629eccceded4b723fc319562b3d6bb446d

/*init array of list to NULL*/
void init_society_D()
{
    int i;
    for(i = 0; i < size; i++) {
        arr[i] = NULL;
    }

}
/*society insertion*/
void insert_society_D(char owner_name[], int flat_num, int owner_contact)
{
    FILE *fp;
    fp = fopen("society.txt", "a+");

    struct society_D* newNode = (struct society_D*)malloc(sizeof(struct society_D));
    strcpy(newNode->owner_name, owner_name);
    newNode->flat_num = flat_num;
    newNode->owner_contact = owner_contact;
    newNode->next = NULL;
    newNode->prev = next;

    key = flat_num % size;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(root == NULL) {
       root = newNode;
    }
    else {
        struct society_D* temp = root;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node inserted\n");
    fprintf(fp, "owner_name = %s\n", owner_name);
    fprintf(fp, "flat_num = %d\n", flat_num);
    fprintf(fp, "owner_contact = %d\n", owner_contact);
    fclose(fp);
}

/*society display*/
void display_society_D()
{
  FILE *fp;
  fp = fopen("society.txt", "r");

  struct society_D *temp;
    temp = root;
    if(temp!=NULL) {
      while(temp) {
          printf("%s, %d, %d ", temp->owner_name, temp->flat_num, temp->owner_contact);
          temp = temp->next;
      }
    }
<<<<<<< HEAD
    else {
    printf("society data is empty or deleted");
    }
=======
else {
    printf("society data is empty or deleted");
}
>>>>>>> 1809af629eccceded4b723fc319562b3d6bb446d
    fclose(fp);
}

/*society search*/
void search_society_D(int flat_num)
{
    int pos = 0;
    if(root==NULL) {
      printf("Linked List not initialized");
      return;
    }
    prev = root;
    while(prev!=NULL) {
        pos++;
        if(prev->flat_num == flat_num) {
          printf("%d found at position %d\n", flat_num, pos);
          printf("\n\towner_name - %s\n\tflat_num - %d\n\towner_contact - %d",
                 root->owner_name, root->flat_num,  root->owner_contact);
          return;
        }
        if(prev->next != NULL) {
           prev = prev->next;
        }
        else {
           break;
        }
    }
}

/*society updation*/
void update_society_D(int flat_num, int new_flat_num) {
   int pos = 0;

   if(root == NULL) {
      printf("Linked List not initialized");
      return;
   }

   prev = root;
   while(prev!=NULL) {
      pos++;

      if(prev->flat_num== flat_num) {
         prev->flat_num = new_flat_num;
         printf("\n%d found at position %d, replaced with %d\n", flat_num, pos, new_flat_num);
         return;
      }

      if(prev->next != NULL) {
         prev = prev->next;
      }
      else {
         break;
      }
   }
   printf("%d does not exist in the list\n", flat_num);
}

/*society deletion*/
void delete_society_D(int flat_num)
{
    int key = flat_num % size;
  //struct society_D *toDelete =  (struct society_D*)malloc(sizeof(struct society_D));
    struct society_D *toDelete;
    struct society_D *temp = arr[key];
    if(root == NULL) {
        printf("\n List is Empty");
    }
     else if(root->flat_num == flat_num) {
        root = NULL;
        arr[key] = NULL;
        free(root);
        printf("\nnode deleted\n");
    }
    else {
	  while(root->next != NULL) {
        if (root->next->flat_num == flat_num) {
          root = NULL;
          toDelete = root->next;
        	root->next = toDelete->next;
        	toDelete->next->prev = temp;
        	free(toDelete);
        }
          root = root->next;
        }
        printf("\nnode deleted successfully\n");
    }
}
