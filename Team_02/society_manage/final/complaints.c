/*complaints data*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "soc.h"

#define size 1000

/*struct complaints_D
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
struct complaints_D *prev3;*/

struct comData readcom;
struct complaint *arr3[size];
extern void insert_complaints_D(struct comData);
int num_records3;

/*init array of list to NULL*/
void init_complaints_D()
{
    int i;
    for(i = 1; i < size; i++) {
        arr3[i] = NULL;
    }
}

/*Read the complaints data*/
void read_complaints_D()
{
    int fd3;
    num_records3 = 0;
    fd3 = open(COMPLAINT_DATAFILE, O_RDWR | O_CREAT, 0644);
    if(fd3 < 0) {
       perror("read failed");
    }
      while (read(fd3, (void *)&readcom, sizeof(struct comData))) {
        printf("%d.\t%d\t\t%s\t%s\n", readcom.index3, readcom.flat_num3, readcom.complaints_name, readcom.suggestions_name);
        insert_complaints_D(readcom);
        num_records3++;
      }
      close(fd3);
}

/*write the complaints data*/
void write_complaints_D(struct comData com)
{
    int fd3;
    fd3 = open(COMPLAINT_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd3 < 0) {
      perror("file open failed...");
    }
      write(fd3, (void *)&com, sizeof(struct comData));
      close(fd3);
}

void update_com_file(struct comData update)
{
  int fd3;
  fd3 = open(COMPLAINT_DATAFILE, O_RDWR, 0644);
  lseek (fd3, update.index3 * sizeof (struct comData), SEEK_SET);
  if (write(fd3, &update, sizeof(struct comData)) < 0) {
      perror("write failed");
      exit(1);
  }
  close(fd3);
}


/*COMPLAINTS INSERTION*/
void insert_complaints_D(struct comData com_data)
{
    struct complaint* newNode3 = (struct complaint*)malloc(sizeof(struct complaint));
    newNode3->cd.index3 = com_data.index3;
    strcpy(newNode3->cd.complaints_name, com_data.complaints_name);
    strcpy(newNode3->cd.suggestions_name, com_data.suggestions_name);
    newNode3->cd.flat_num3 = com_data.flat_num3;
    newNode3->next3 = NULL;
    newNode3->prev3 = NULL;

    int key3 = com_data.flat_num3 % size;
    newNode3->next3 = NULL;
    newNode3->prev3 = NULL;

    if(arr3[key3] == NULL) {
      newNode3->next3 = NULL;
      newNode3->prev3 = NULL;
      arr3[key3] = newNode3;
    }
    else {
      struct complaint* temp3 = arr3[key3];
      while(temp3->next3 != NULL){
        temp3 = temp3->next3;
        }
        temp3->next3 = newNode3;
        newNode3->prev3 = temp3;
        //newNode->next = NULL;
    }
    //printf("Node inserted\n");
}

/* COMPLAINTS DISPLAY*/
void display_complaints_D()
{
  int i;
  struct complaint *temp3;
  printf("\n==================================================================\n\n");
  printf("\t\tCOMPLAINT DATAFILE\n\n");
  printf("SR.\tFLAT_NO\tCOMPLAINT\tSUGGESSTION\n\n");
  for(i =0; i < size; i++){
    temp3 = arr3[i];
    while(temp3) {
      printf("%d\t%d\t%s\t%s\n",temp3->cd.index3, temp3->cd.flat_num3, temp3->cd.complaints_name, temp3->cd.suggestions_name);
      temp3 = temp3->next3;
    }
  }
}

/*COMPLAINTS SEARCH*/
void search_complaints_D(int flat_num3)
{

  struct complaint *ptr3;
  int i=0, flag;
  int key3 = flat_num3 % size;
  ptr3 = arr3[key3];
  if (ptr3 == NULL) {
    printf("\n\n\tEmpty List\n");
  }
  else {
    while(ptr3 !=NULL) {
      if(ptr3->cd.flat_num3 == flat_num3) {
        printf("\n\n\tfound at position : %d", key3);
        printf("\n\n\tflat_number\t -\t %d\n\tcomplaints_name\t -\t %s\n\tsuggestions_name -\t %s\n",ptr3->cd.flat_num3, ptr3->cd.complaints_name, ptr3->cd.suggestions_name);
        flag = 0;
        break;
      }
      else {
        flag=1;
      }
      i++;
      ptr3 = ptr3 -> next3;
    }
    if (flag==1) {
      printf("\n\nflat number not found\n");
    }
  }
}

/*COMPLAINTS UPDATION*/
void update_complaints_D(int flat_num3)
{
  struct complaint *ptr3;
  int i=0, flag;
  int key3 = flat_num3 % size;
  ptr3 = arr3[key3];
  if (ptr3 == NULL) {
    printf("\n\n\tEmpty List\n");
  }
  else {
    while(ptr3 !=NULL) {
      if(ptr3->cd.flat_num3 == flat_num3) {
        printf("\n\n\tComplaints Old Data!!!");
        printf("\n\n\tcomplaint Index\t -\t %d\n\tflat_number\t -\t %d\n\tcomplaints_name\t -\t %s\n\tsuggestions_name -\t %s\n",ptr3->cd.index3, ptr3->cd.flat_num3, ptr3->cd.complaints_name, ptr3->cd.suggestions_name);

        printf("\n\n\tComplaints New Data !!!\n");

        int index3, flat_num3;
        char complaints_name[50], suggestions_name[50];
        printf("\n\tEnter Same Index : ");
        scanf("\t %d", &index3);
        printf("\n\tEnter Same flat number : ");
        scanf("\t %d", &flat_num3);
        printf("\n\tEnter New Complaint : ");
        scanf("\t %[^\n]%*c", complaints_name);
        printf("\n\tEnter New suggession : ");
        scanf("\t %[^\n]%*c", suggestions_name);

        ptr3->cd.index3 = index3;
        ptr3->cd.flat_num3 = flat_num3;
        strcpy(ptr3->cd.complaints_name, complaints_name);
        strcpy(ptr3->cd.suggestions_name, suggestions_name);
        printf("\n\n\tflat_number\t -\t %d\n\tcomplaints_name\t -\t %s\n\tsuggestions_name -\t %s\n",ptr3->cd.flat_num3, ptr3->cd.complaints_name, ptr3->cd.suggestions_name);
        printf("\n\n\tComplaint Record Updated Successfully !!!\n");
        flag = 0;
        update_com_file(ptr3->cd);
        break;
      } else {
        flag = 1;
        }

        i++;
        ptr3 = ptr3 -> next3;
    }

    if (flag == 1) {
      printf("\n\n\tComplaint flat_num not found\n");
    }
  }
}

/*COMPLAINTS DELETION*/
/*void delete_complaints_D(int flat_number)
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
}*/
