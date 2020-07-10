/*visitors data*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define size 1000

struct visitors_D
{
    char visitor_name[30];
    int vehicle_num;
    int new_vehicle_num;
    int visitor_contact;
    int TimeIn;
    int TimeOut;
    int key;
    struct visitors_D *next2;
    struct visitors_D *prev2;
};
struct visitors_D *root2 = NULL;
int key2;
struct visitors_D *temp2;
struct visitors_D *next2;
struct visitors_D *prev2;

struct visitors_D *arr2[size];
void insert_visitors_D(char visitor_name[], int vehicle_num, int visitor_contact, int TimeIn, int TimeOut);
void display_visitors_D();
void search_visitors_D(int vehicle_num);
void update_visitors_D(int vehicle_num, int new_vehicle_num);
void delete_visitors(int vehicle_num);

/*init array of list to NULL*/
void init_visitors_D()
{
    int i;
    for(i = 0; i < size; i++) {
        arr2[i] = NULL;
    }
}

  /* VISITORS INSERTION*/
  void insert_visitors_D(char visitor_name[], int vehicle_num, int visitor_contact, int TimeIn, int TimeOut)
  {
      FILE *fp;
      fp = fopen("visitors.txt", "a+");
      struct visitors_D* newNode = (struct visitors_D*)malloc(sizeof(struct visitors_D));
      strcpy(newNode->visitor_name, visitor_name);

      newNode-> vehicle_num = vehicle_num;
      newNode-> visitor_contact = visitor_contact;
      newNode-> TimeIn = TimeIn;
      newNode-> TimeOut = TimeOut;
      newNode-> next2 = NULL;
      newNode-> prev2 = next2;

      key2 = vehicle_num % size;
      newNode-> prev2 = NULL;
      newNode-> next2 = NULL;

      if(root2 == NULL) {
      root2 = newNode;
      }
      else {
          struct visitors_D *temp2 = root2;
          while (temp2-> next2 != NULL) {
              temp2 = temp2-> next2;
          }
          temp2-> next2 = newNode;
          newNode-> prev2 = temp2;
      }
      printf("Node inserted\n");
      fprintf(fp, "visitor_name = %s\n", visitor_name);
      fprintf(fp, "vehicle_num = %d\n", vehicle_num);
      fprintf(fp, "visitor_contact = %d\n", visitor_contact);
      fprintf(fp, "TimeInIN = %d\n", TimeIn);
      fprintf(fp, "TimeOut = %d\n", TimeOut);
      fclose(fp);
  }

  /* VISITORS DISPLAY*/
  void display_visitors_D()
  {
    FILE *fp;
    fp = fopen("visitors.txt", "r");
    struct visitors_D *temp2;
      temp2 = root2;
      if(temp2!=NULL) {
      while(temp2) {
          printf("%s, %d, %d, %d, %d",temp2->visitor_name, temp2->vehicle_num, temp2->visitor_contact, temp2->TimeIn, temp2->TimeOut);

          temp2 = temp2-> next2;
      }
      }
      else {
        printf("visitors data is empty or deleted");
      }
      fclose(fp);
 }

  /*VISITORS SEARCH*/
  void search_visitors_D(int vehicle_num)
  {
      int pos = 0;
      if(root2==NULL) {
        printf("Linked List not initialized");
        return;
      }
      prev2 = root2;
      while(prev2!=NULL) {
          pos++;
          if(prev2->vehicle_num == vehicle_num) {
            printf("%d found at position %d\n", vehicle_num, pos);
            printf("\n\tvisitor_name - %s\n\tvehicle_num - %d\n\tvisitor_contact - %d\n\tTimeIn -%d\n\tTimeOut - %d",
                  root2->visitor_name, root2->vehicle_num, root2->visitor_contact, root2->TimeIn, root2->TimeOut);

            return;
          }
          if(prev2->next2 != NULL) {
             prev2 = prev2->next2;
          }
        else {
           break;
        }
    }
  }

  /*VISITORS UPDATION*/
  void update_visitors_D(int vehicle_num, int new_vehicle_num)
  {
    int pos = 0;

    if(root2 == NULL) {
       printf("Linked List not initialized");
       return;
    }

    prev2 = root2;
    while(prev2!=NULL) {

       pos++;

       if(prev2->vehicle_num == vehicle_num) {
          prev2->vehicle_num = new_vehicle_num;
          printf("\n%d found at position %d, replaced with %d\n",vehicle_num, pos, new_vehicle_num);
          return;
       }

       if(prev2->next2 != NULL)
          prev2 = prev2->next2;
       else
          break;
    }
    printf("%d does not exist in the list\n", vehicle_num);
  }

  /*VISITORS DELETION*/
  void delete_visitors_D(int vehicle_num)
  {
      int key = vehicle_num % size;
      struct visitors_D *toDelete;
      struct visitors_D *temp2 = arr2[key];
      if(root2 == NULL) {
          printf("\n List is Empty");
      }
       else if(root2->vehicle_num == vehicle_num) {
          root2 = NULL;
          arr2[key2] = NULL;
          free(root2);
          printf("\nnode deleted\n");
      }
      else {
  	  while(root2->next2 != NULL) {
          if (root2->next2->vehicle_num == vehicle_num) {
            root2 = NULL;
            toDelete = root2->next2;
          	root2->next2 = toDelete->next2;
            toDelete->next2->prev2 = temp2;
          	free(toDelete);
          }
            root2 = root2->next2;
          }
          printf("\nnode deleted successfully\n");
      }
  }
