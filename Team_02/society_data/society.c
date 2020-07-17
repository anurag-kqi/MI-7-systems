
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "soc.h"
#define size 9
struct society
{
    int index;
    char owner_name[30];
    int flat_num;
    int owner_contact;
    struct society *temp;
    struct society *next;
    struct society *prev;
};

// struct society {
//     struct socityData ondisk;
//     struct society *next;
//     struct society *prev;

// }


struct society *arr[size];

//init array of list to NULL
void init_soc()
{
    int i;
    for(i = 0; i < size; i++) {
        arr[i] = NULL;
    }
}

/*society insertion*/
void insert_soc(struct socData soc_data)
{
      //create a newnode with value
      struct society *newNode = (struct society*)malloc(sizeof(struct society));
      newNode->index = soc_data.index;
      strcpy(newNode->owner_name, soc_data.owner_name);
      newNode->flat_num = soc_data.flat_num;
      newNode->owner_contact = soc_data.owner_contact;
      newNode->next = NULL;
      newNode->prev = NULL;
      //calculate hash key
      int key = soc_data.flat_num % size;

      if (arr[key] == NULL) {
          newNode->next = NULL;
          newNode->prev = NULL;
          arr[key] = newNode;
      } else {
          struct society *temp = arr[key];

          while (temp->next != NULL) {
              temp = temp->next;
          }
          temp->next = newNode;
          newNode->prev = temp;
        }
        //printf("Node inserted\n");
}

/*void delete_soc(int flat_num)
{
    int key = flat_num % size;
    struct society *ptr = arr[key], *toDelete;

    if (ptr == NULL) {
        printf("\n\n\tList is Empty !!!\n");
    }
    else if (ptr->flat_num == flat_num) {
        arr[key] = arr[key]->next;
        arr[key]->prev = NULL;//segmentation fault
        ptr->next = NULL;
        free(ptr);
	printf("\n\n\tFirst node deleted\n");
    } else {
	while (ptr->next != NULL) {
            if (ptr->next->flat_num == flat_num) {
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
}*/

/*display data*/
void display_soc()
{
  int i;
  struct society *temp;
  for(i = 0; i < size; i++) {
    temp = arr[i];
    while(temp) {
        printf("%d, %s, %d, %d \n", temp->index, temp->owner_name, temp->flat_num, temp->owner_contact);
        temp = temp->next;
    }
  }
}

/*serch data*/
void search_soc(int flat_num)
{
    struct society *ptr;
    int i=0, flag;

    int key = flat_num % size;

    ptr = arr[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {


        while (ptr != NULL) {
            if (ptr->flat_num == flat_num) {
                printf("\n\n\tSociety flat number found at location %d ", i+1);
                printf("\n\n\tsociety Prev - %p\n\tsociety owner_name - %s\n\tsociety flat_num - %d\n\tsociety owner_contact - %d\n\twrite_society next - %p", ptr->prev, ptr->owner_name, ptr->flat_num, ptr->owner_contact, ptr->next);
                flag = 0;
                break;
            } else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if (flag==1) {
            printf("\n\n\tsociety flat number not found\n");
        }
    }
}


/*updation*/
void update_soc(int flat_num)
{
    struct society *ptr;
    int i=0, flag;

    int key = flat_num % size;

    ptr = arr[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {

        while (ptr != NULL) {
            if (ptr->flat_num == flat_num) {
                printf("\n\n\tSociety old Data !!!\n");
                printf("\n\n\tsociety Index - %d\n\tsociety owner_name - %s\n\tsociety flat_num - %d\n\tsociety owner_contact - %d",
                       ptr->index, ptr->owner_name, ptr->flat_num, ptr->owner_contact);

		printf("\n\n\tSociety New Data !!!\n");

		int flat_num, owner_contact, index;
    char owner_name[30];

    printf("\n\tEnter Same Index : ");
    scanf("\t %d", &index);
		printf("\n\tEnter New owner Name : ");
		scanf("\t %[^\n]%*c", owner_name);
    printf("\n\tEnter Same flat number : ");
		scanf("\t %d", &flat_num);
    printf("\n\tEnter New Contact : ");
		scanf("\t %d", &owner_contact);

        ptr->index = index;
        ptr->flat_num = flat_num;
    		strcpy(ptr->owner_name, owner_name);
		    ptr->owner_contact = owner_contact;

		    printf("\n\n\tsociety Index - %d\n\tsociety owner_name- %s\n\tsociety flat_num- %d\n\tsociety owner_contact - %d",
                           ptr->index, ptr->owner_name, ptr->flat_num, ptr->owner_contact);
		    printf("\n\n\tSociety Record Updated Successfully !!!\n");
                    flag = 0;

                break;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr -> next;
        }

        if (flag == 1) {
            printf("\n\n\tsociety flat_num not found\n");
        }
    }
}
