/*visitors data*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "soc.h"
#define size 9

struct visData readvis;
extern void insert_vis(struct visData);
extern void update_vis(int vehicle_num);
struct visitor *arr2[size];
int num_records2;

/*init array of list to NULL*/
void init_vis()
{
    int i;
    for(i = 0; i < size; i++) {
        arr2[i] = NULL;
    }
}

//read the visitor data
void read_vis() {
  int fd2;
  num_records2 = 0;
  fd2 = open(VISITOR_DATAFILE, O_RDWR | O_CREAT, 0644);
  if(fd2 < 0) {
     perror("read failed");
  }
  while (read(fd2, (void *)&readvis, sizeof(struct visData))) {
    printf("%d.\t%s\t\t%d\t%d\t%d\t%d\n", readvis.index2, readvis.visitor_name, readvis.vehicle_num, readvis.visitor_contact, readvis.TimeIn, readvis.TimeOut);
    insert_vis(readvis);
    num_records2++;
  }
  close(fd2);
}

//write data into visitor data
void write_vis(struct visData vis)
{
  int fd2;
  fd2 = open(VISITOR_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
  if (fd2 < 0) {
    perror("file open failed...");
  }
  write(fd2, (void *)&vis, sizeof(struct visData));
  close(fd2);
}

//update visitor data file
void update_vis_file(struct visData update)
{
  int fd2;
  fd2 = open(VISITOR_DATAFILE, O_RDWR, 0644);
  lseek (fd2, update.index2 * sizeof (struct visData), SEEK_SET);
  if (write(fd2, &update, sizeof(struct visData)) < 0) {
      perror("write failed");
      exit(1);
  }
  close(fd2);
}

//insert visitor data
void insert_vis(struct visData vis_data)
{
  struct visitor *newNode2 = (struct visitor*)malloc(sizeof(struct visitor));
  newNode2->vd.index2 = vis_data.index2;
  strcpy(newNode2->vd.visitor_name, vis_data.visitor_name);
  newNode2->vd.vehicle_num = vis_data.vehicle_num;
  newNode2->vd.visitor_contact = vis_data.visitor_contact;
  newNode2->vd.TimeIn = vis_data.TimeIn;
  newNode2->vd.TimeOut = vis_data.TimeOut;
  newNode2->next2 = NULL;
  newNode2->prev2 = NULL;
  //calculate hash key
  int key2 = vis_data.vehicle_num % size;
  if (arr2[key2] == NULL) {
    newNode2->next2 = NULL;
    newNode2->prev2 = NULL;
    arr2[key2] = newNode2;
  }
  else {
    struct visitor *temp2 = arr2[key2];
    while (temp2->next2 != NULL) {
      temp2 = temp2->next2;
    }
    temp2->next2 = newNode2;
    newNode2->prev2 = temp2;
  }
}

//display visitor data
void display_vis()
{
  int i;
  struct visitor *temp2;
  printf("\n==================================================================\n\n");
  printf("SR. VIS_NAME    VIS_NO    VIS_CONTACT   TIMEIN    TIMEOUT\n\n");
  for(i = 0; i < size; i++) {
    temp2 = arr2[i];
    while(temp2) {
      printf("%d\t%s\t%d\t\t%d\t%d\t%d\n", temp2->vd.index2, temp2->vd.visitor_name, temp2->vd.vehicle_num, temp2->vd.visitor_contact, temp2->vd.TimeIn, temp2->vd.TimeOut);
      temp2 = temp2->next2;
    }
  }
}

void update_vis(int vehicle_num)
{
  struct visitor *ptr2;
  int i=0, flag;
  int key2 = vehicle_num % size;
  ptr2 = arr2[key2];
  if (ptr2 == NULL) {
    printf("\n\n\tEmpty List\n");
  }
  else {
    while (ptr2 != NULL) {
      if (ptr2->vd.vehicle_num == vehicle_num) {
        printf("\n\n\tVisitor old Data !!!\n");
        printf("\n\n\tvisitor Index\t - \t%d\n\tvisitor_name\t - \t%s\n\tvisitor vehicle_num\t - \t%d\n\tvisitor_contact\t - \t%d\n\tvisitor TIMEIN\t - \t%d\n\tvisitor TimeOut\t - \t%d\n", ptr2->vd.index2, ptr2->vd.visitor_name, ptr2->vd.vehicle_num, ptr2->vd.visitor_contact, ptr2->vd.TimeIn, ptr2->vd.TimeOut);

        printf("\n\n\t Visitor New Data !!!\n");

        int vehicle_num, visitor_contact, TimeIn, TimeOut, index2;
        char visitor_name[30];
        printf("\n\tEnter Same Index : ");
        scanf("\t %d", &index2);
        printf("\n\tEnter Same visitor number : ");
    		scanf("\t %d", &vehicle_num);
    		printf("\n\tEnter New Visitor Name : ");
    		scanf("\t %[^\n]%*c", visitor_name);
        printf("\n\tEnter New Contact : ");
    		scanf("\t %d", &visitor_contact);
        printf("\n\tEnter New TimeIn : ");
    		scanf("\t %d", &TimeIn);
        printf("\n\tEnter New TimeOut : ");
    		scanf("\t %d", &TimeOut);

        ptr2->vd.index2 = index2;
        ptr2->vd.vehicle_num = vehicle_num;
    		strcpy(ptr2->vd.visitor_name, visitor_name);
  	    ptr2->vd.visitor_contact = visitor_contact;
        printf("\n\n\tvisitor Index\t - \t%d\n\tvisitor_name\t - \t%s\n\tvisitor vehicle_num\t - \t%d\n\tvisitor_contact\t - \t%d\n\tvisitor TIMEIN\t - \t%d\n\tvisitor TimeOut\t - \t%d\n", ptr2->vd.index2, ptr2->vd.visitor_name, ptr2->vd.vehicle_num, ptr2->vd.visitor_contact, ptr2->vd.TimeIn, ptr2->vd.TimeOut);
        printf("\n\n\tSociety Record Updated Successfully !!!\n");
        flag = 0;
        update_vis_file(ptr2->vd);
        break;
      }
      else {
        flag = 1;
      }
      i++;
      ptr2 = ptr2 -> next2;
    }
    if (flag == 1) {
      printf("\n\n\tvisitor vehicle_num not found\n");
    }
  }
}

//search visitor data
void search_vis(int vehicle_num)
{
  struct visitor *ptr2;
  int i=0, flag;
  int key2 = vehicle_num % size;
  ptr2 = arr2[key2];
  if (ptr2 == NULL) {
    printf("\n\n\tEmpty List\n");
  }
  else {
    while (ptr2 != NULL) {
      if (ptr2->vd.vehicle_num == vehicle_num) {
        printf("found at position : %d\n", key2);
        printf("\n\n\tvisitor Index\t - \t%d\n\tvisitor_name\t - \t%s\n\tvisitor vehicle_num\t - \t%d\n\tvisitor_contact\t - \t%d\n\tvisitor TIMEIN\t - \t%d\n\tvisitor TimeOut\t - \t%d\n", ptr2->vd.index2, ptr2->vd.visitor_name, ptr2->vd.vehicle_num, ptr2->vd.visitor_contact, ptr2->vd.TimeIn, ptr2->vd.TimeOut);
        flag = 0;
        break;
      }
      else {
        flag = 1;
      }
      i++;
      ptr2 = ptr2 -> next2;
    }
    if (flag == 1) {
      printf("\n\n\tsociety flat number not found\n");
    }
  }
}


/*VISITORS DELETION*/
//void delete_visitors_D(int vehicle_num)
/*{
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
}*/
