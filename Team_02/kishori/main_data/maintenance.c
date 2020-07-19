
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "maint.h"
#define size 9

struct maintData readmaint;
extern void insert_maint(struct maintData);
struct maintenance *arr1[size];
int num_records;

//init array of list to NULL
void init_maint()
{
    int i;
    for(i = 1; i < size; i++) {
        arr1[i] = NULL;
    }
}

void read_maint() {
  int fd;
  num_records = 0;
  fd = open(MAINTENANCE_DATAFILE, O_RDWR | O_CREAT, 0644);
  if(fd < 0) {
     perror("read failed");
  }
  //printf("In the read_soc %s %d\n", __FILE__, __LINE__);

  while (read(fd, (void *)&readmaint, sizeof(struct maintData))) {
  //  printf("In the read_soc %d\n", __LINE__);

    //printf("%d. ", num_records);
    printf("%d.\t%d\t\t%d\t%d\n", readmaint.index, readmaint.flat_num1, readmaint.water_bill, readmaint.electricity_bill);
    insert_maint(readmaint);
    num_records++;
  }
  //printf("In the read_soc %d\n", __LINE__);

  close(fd);
}

//Write the student data
void write_maint(struct maintData maint)
{
  int fd;
  fd = open(MAINTENANCE_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
  if (fd < 0) {
    perror("file open failed...");
  }
  write(fd, (void *)&maint, sizeof(struct maintData));
  close(fd);
}


//update to file
void update_maint_file(struct maintData update)
{
  int fd;
  fd = open(MAINTENANCE_DATAFILE, O_RDWR, 0644);
  lseek (fd, update.index * sizeof (struct maintData), SEEK_SET);
  if (write(fd, &update, sizeof(struct maintData)) < 0) {
      perror("write failed");
      exit(1);
  }
  close(fd);
}

/*society insertion*/
void insert_maint(struct maintData maint_data)
{
      //create a newnode with value
      struct maintenance *newNode = (struct maintenance*)malloc(sizeof(struct maintenance));
      newNode->sd.index = maint_data.index;
      newNode->sd.flat_num1 = maint_data.flat_num1;
      newNode->sd.water_bill = maint_data.water_bill;
      newNode->sd.electricity_bill = maint_data.electricity_bill;
      newNode->next = NULL;
      newNode->prev = NULL;
      //calculate hash key
      int key = maint_data.flat_num1 % size;

      if (arr1[key] == NULL) {
          newNode->next = NULL;
          newNode->prev = NULL;
          arr1[key] = newNode;
      } else {
          struct maintenance *temp = arr1[key];

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
void display_maint()
{
  int i;
  //int index = 1;
  struct maintenance *temp;
  printf("\n==================================================================\n\n");
  printf("SR. FLAT_NO    WATER_BILL    ELECTRICITY_BILL\n\n");
  for(i = 0; i < size; i++) {
    temp = arr1[i];
    while(temp) {
        //printf("%d. ", index);
        printf("%d\t %d\t %d\t%d\n", temp->sd.index, temp->sd.flat_num1, temp->sd.water_bill, temp->sd.electricity_bill);
        temp = temp->next;
        //index++;
    }
  }
}

/*serch data*/
void search_maint(int flat_num1)
{
    struct maintenance *ptr;
    int i=0, flag;

    int key = flat_num1 % size;

    ptr = arr1[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {


        while (ptr != NULL) {
            if (ptr->sd.flat_num1 == flat_num1) {
                printf("\n\n\tmaintenance flat number found at location : %d ", key-1 );
                printf("\n\n\tflat_num1\t -\t %d\n\twater_bill\t -\t %d\n\telectricity_bill\t -\t %d\n", ptr->sd.flat_num1, ptr->sd.water_bill, ptr->sd.electricity_bill);
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
void update_maint(int flat_num1)
{
    struct maintenance *ptr;
    int i=0, flag;

    int key = flat_num1 % size;

    ptr = arr1[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {

        while (ptr != NULL) {
            if (ptr->sd.flat_num1 == flat_num1) {
                printf("\n\n\tmaintenance old Data !!!\n");
                printf("\n\n\tmaintenance Index - %d\n\tmaintenance flat_num1 - %d\n\tmaintenance water_bill - %d\n\tmaintenance electricity_bill -%d",
                       ptr->sd.index, ptr->sd.flat_num1, ptr->sd.water_bill, ptr->sd.electricity_bill);

            		printf("\n\n\tmaintenance New Data !!!\n");

            		int flat_num1, water_bill, electricity_bill, index;

                printf("\n\tEnter Same Index : ");
                scanf("\t %d", &index);
                printf("\n\tEnter Same flat number : ");
            		scanf("\t %d", &flat_num1);
                printf("\n\tEnter New water_bill : ");
            		scanf("\t %d", &water_bill);
                printf("\n\tEnter New electricity_bill :");
                scanf("\t %d", &electricity_bill);

                ptr->sd.index = index;
                ptr->sd.flat_num1 = flat_num1;
            		ptr->sd.water_bill = water_bill;
          	    ptr->sd.electricity_bill = electricity_bill;

          	    printf("\n\n\tsociety Index - %d\n\tmaintenance flat_num1- %d\n\tmaintenance water_bill - %d\n\tmaintenance electricity_bill - %d", ptr->sd.index, ptr->sd.flat_num1, ptr->sd.water_bill, ptr->sd.electricity_bill);
          	    printf("\n\n\tSociety Record Updated Successfully !!!\n");
                flag = 0;
                update_maint_file(ptr->sd);
            break;
          } else {
                    flag = 1;
              }
            i++;
            ptr = ptr -> next;
        }

        if (flag == 1) {
            printf("\n\n\tmaintenance flat_num not found\n");
        }
    }
}
