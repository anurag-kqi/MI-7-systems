<<<<<<< HEAD

=======
>>>>>>> 1809af629eccceded4b723fc319562b3d6bb446d
/*maintenance data*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define size 1000

struct maintenance_D
{
    int water_bill;
    int electricity_bill;
    int new_water_bill;
    int new_electricity_bill;
    int key;
    int flat_num1;
    struct maintenance_D *next1;
    struct maintenance_D *prev1;
};
struct maintenance_D *root1 = NULL;
int key1;
struct maintenance_D *temp1;
struct maintenance_D *next1;
struct maintenance_D *prev1;

struct maintenance_D *arr1[size];
<<<<<<< HEAD
void insert_maintenance_D(int flat_num1, int water_bill, int electricity_bill);
void display_maintenance_D();
void search_maintenance_D(int flat_num1);
void update_maintenance_D(int water_bill, int electricity_bill,int new_water_bill, int new_electricity_bill) ;
void delete_maintenance_D(int flat_num1);

/*File pointer*/
FILE *fp;
=======



extern void insert_maintenance_D(int flat_num1, int water_bill, int electricity_bill);

/*File pointer*/
FILE *fptr;
>>>>>>> 1809af629eccceded4b723fc319562b3d6bb446d

/*init array of list to NULL*/
void init_maintenance_D()
{
    int i;
    for(i = 0; i < size; i++) {
        arr1[i] = NULL;
    }
}

  /*MAINTENANCE INSERTION*/
  void insert_maintenance_D(int flat_num1, int water_bill, int electricity_bill)
  {
      FILE *fp;
      fp = fopen("maintenance.txt", "a+");
      struct maintenance_D* newNode = (struct maintenance_D*)malloc(sizeof(struct maintenance_D));
      newNode->flat_num1 = flat_num1;
      newNode->water_bill = water_bill;
      newNode->electricity_bill = electricity_bill;
      newNode->next1 = NULL;
      newNode->prev1 = next1;

      key1= flat_num1% size;
      newNode->next1 = NULL;
      newNode->prev1 = NULL;

      if(root1 == NULL) {
         root1 = newNode;
      }
      else {
          struct maintenance_D* temp1 = root1;

          while(temp1->next1 != NULL) {
              temp1 = temp1->next1;
          }
          temp1->next1 = newNode;
          newNode->prev1 = temp1;
      }
      printf("Node inserted\n");
      fprintf(fp, "flat_num1 = %d\n", flat_num1);
      fprintf(fp, "water_bill = %d\n", water_bill);
      fprintf(fp, "electricity_bill = %d\n", electricity_bill);
      fclose(fp);
  }

  /* MAINTENANCE DISPLAY*/
  void display_maintenance_D()
  {
<<<<<<< HEAD
    FILE *fp;
    fp = fopen("maintenance.txt", "r");
    struct maintenance_D *temp1;
=======
      struct maintenance_D *temp1;
>>>>>>> 1809af629eccceded4b723fc319562b3d6bb446d
      temp1 = root1;
      if(temp1!=NULL) {
        while(temp1) {
            printf("%d, %d %d", temp1->flat_num1, temp1->water_bill, temp1->electricity_bill);
            temp1 = temp1->next1;
        }
      }
<<<<<<< HEAD
      else {
        printf("maintenance data is empty or deleted");
      }
      fclose(fp);
=======
  else {
      printf("maintenance data is empty or deleted");
  }
>>>>>>> 1809af629eccceded4b723fc319562b3d6bb446d
  }

  /*MAINTENANCE SEARCH*/
  void search_maintenance_D(int flat_num1)
  {
      int pos = 0;
      if(root1==NULL) {
        printf("Linked List not initialized");
        return;
      }
      prev1 = root1;
      while(prev1!=NULL) {
          pos++;
          if(prev1->flat_num1== flat_num1) {
            printf("%d found at position %d\n", flat_num1, pos);
            printf("\n\twater_bill - %d\n\tflat_num1 - %d\n\telectricity_bill - %d",
                   root1->water_bill, root1->flat_num1,  root1->electricity_bill);
            return;
          }
          if(prev1->next1 != NULL) {
             prev1 = prev1->next1;
          }
<<<<<<< HEAD
      else {
           break;
      }
=======
        else {
           break;
        }
>>>>>>> 1809af629eccceded4b723fc319562b3d6bb446d
      }
  }

  /*MAINTENANCE UPDATION*/
  void update_maintenance_D(int water_bill, int electricity_bill,int new_water_bill, int new_electricity_bill)
  {
     int pos = 0;

     if(root1 == NULL) {
        printf("Linked List not initialized");
        return;
     }

     prev1 = root1;
     while(prev1!=NULL) {

        pos++;

        if(prev1->water_bill = water_bill, prev1->electricity_bill == electricity_bill) {
           prev1->water_bill = new_water_bill, prev1->electricity_bill = new_electricity_bill;
           printf("\n%d found at position %d, replaced with %d\n",water_bill, pos, new_water_bill);
           printf("\n%d found at position %d, replaced with %d\n",electricity_bill, pos, new_electricity_bill);
           return;
        }

        if(prev1->next1 != NULL) {
           prev1 = prev1->next1;
        }
        else {
           break;
        }
     }
     printf("%d %d does not exist in the list\n", water_bill, electricity_bill);
  }

  /*MAINTENANCE DELETION*/
  void delete_maintenance_D(int flat_num1)
  {
      int key1 = flat_num1% size;
      struct maintenance_D *toDelete;
      struct maintenance_D *temp1 = arr1[key1];
      if(root1 == NULL) {
          printf("\n List is Empty");
      }
       else if(root1->flat_num1 == flat_num1) {
          root1 = NULL;
          arr1[key1] = NULL;
          free(root1);
          printf("\nnode deleted\n");
      }
      else {
  	  while(root1->next1 != NULL) {
          if (root1->next1->flat_num1 == flat_num1) {
            root1 = NULL;
            toDelete = root1->next1;
          	root1->next1 = toDelete->next1;
          	toDelete->next1->prev1 = temp1;
          	free(toDelete);
          }
          root1 = root1->next1;
          }
          printf("\nnode deleted successfully\n");
      }
  }
