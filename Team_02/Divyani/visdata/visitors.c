/*visitors data*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "vis.h"
#define size 9



/*struct visitors_D
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

struct visitors_D *arr2[size];*/


//extern void insert_visitors_D(char visitor_name[], int vehicle_num, int visitor_contact, int TimeIn, int TimeOut);
struct visData readvis;
extern void insert_vis(struct visData);
extern void update_vis(int vehicle_num);
struct visitor *arr2[size];
int num_records;

/*File pointer*/
FILE *fptr;

/*init array of list to NULL*/
void init_vis()
{
    int i;
    for(i = 0; i < size; i++) {
        arr2[i] = NULL;
    }
}

void read_vis() {
  int fd;
  num_records = 0;
  fd = open(SOCIETY_DATAFILE, O_RDWR | O_CREAT, 0644);
  if(fd < 0) {
     perror("read failed");
  }

  while (read(fd, (void *)&readvis, sizeof(struct visData))) {
  //  printf("In the read_soc %d\n", __LINE__);

    //printf("%d. ", num_records);
    printf("%d.\t%s\t\t%d\t%d\n%d\n%d\n", readvis.index, readvis.visitor_name, readvis.vehicle_num, readvis.visitor_contact, readvis.TimeIn, readvis.TimeOut);
    insert_vis(readvis);
    num_records++;
  }
  //printf("In the read_soc %d\n", __LINE__);

  close(fd);
  }

  void write_vis(struct visData vis)
  {
    int fd;
    fd = open(SOCIETY_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
      perror("file open failed...");
    }
    write(fd, (void *)&vis, sizeof(struct visData));
    close(fd);
  }


  void update_vis_file(struct visData update)
  {
    int fd;
    fd = open(SOCIETY_DATAFILE, O_RDWR, 0644);
    lseek (fd, update.index * sizeof (struct visData), SEEK_SET);
    if (write(fd, &update, sizeof(struct visData)) < 0) {
        perror("write failed");
        exit(1);
    }
    close(fd);
  }

  /* VISITORS INSERTION*/
  void insert_vis(struct visData vis_data)
  {
      //FILE *fp;
      //fp = fopen("visitor.txt", "a+");
      /*struct visitor* newNode = (struct visitor*)malloc(sizeof(struct visitor));
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
      fclose(fp);*/
      struct visitor *newNode = (struct visitor*)malloc(sizeof(struct visitor));
      newNode->vd.index = vis_data.index;
      strcpy(newNode->vd.visitor_name, vis_data.visitor_name);
      newNode->vd.vehicle_num = vis_data.vehicle_num;
     newNode->vd.visitor_contact = vis_data.visitor_contact;
     newNode->vd.TimeIn = vis_data.TimeIn;
      newNode->vd.TimeOut = vis_data.TimeOut;
      newNode->next = NULL;
      newNode->prev = NULL;
      //calculate hash key
      int key = vis_data.vehicle_num % size;

      if (arr2[key] == NULL) {
          newNode->next = NULL;
          newNode->prev = NULL;
          arr2[key] = newNode;
      } else {
          struct visitor *temp = arr2[key];

          while (temp->next != NULL) {
              temp = temp->next;
          }
          temp->next = newNode;
          newNode->prev = temp;
        }
  }

  /* VISITORS DISPLAY*/
  /*void display_visitors_D()
  {
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
}*/

void display_vis()
{
  int i;
  //int index = 1;
  struct visitor *temp;
  printf("\n==================================================================\n\n");
  printf("SR. VIS_NAME    VIS_NO  VIS_CONTACT  TIMEIN  TIMEOUT\n\n");
  for(i = 0; i < size; i++) {
    temp = arr2[i];
    while(temp) {
        //printf("%d. ", index);
        printf("%d\t %s\t %d\t%d %d\t %d \n", temp->vd.index, temp->vd.visitor_name, temp->vd.vehicle_num, temp->vd.visitor_contact, temp->vd.TimeIn, temp->vd.TimeOut);
        temp = temp->next;
        //index++;
    }
  }
}

void update_vis(int vehicle_num)
{
    struct visitor *ptr;
    int i=0, flag;

    int key = vehicle_num % size;

    ptr = arr2[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {

        while (ptr != NULL) {
            if (ptr->vd.vehicle_num == vehicle_num) {
                printf("\n\n\t Visitor old Data !!!\n");
                printf("\n\n\t visitor Index - %d\n\t visitor visitor_name - %s\n\t visitor vehicle_num - %d\n\t visitor visitor_contact - %d\n\t visitor TIMEIN - %d\n\t visitor TimeOut - %d",
                       ptr->vd.index, ptr->vd.visitor_name, ptr->vd.vehicle_num, ptr->vd.visitor_contact, ptr->vd.TimeIn, ptr->vd.TimeOut);

            		printf("\n\n\t Visitor New Data !!!\n");

            		int vehicle_num, visitor_contact, TimeIn, TimeOut, index;
                char visitor_name[30];

                printf("\n\tEnter Same Index : ");
                scanf("\t %d", &index);
            		printf("\n\tEnter New Visitor Name : ");
            		scanf("\t %[^\n]%*c", visitor_name);
                printf("\n\tEnter Same visitor number : ");
            		scanf("\t %d", &vehicle_num);
                printf("\n\tEnter New Contact : ");
            		scanf("\t %d", &visitor_contact);
                printf("\n\tEnter New TimeIn : ");
            		scanf("\t %d", &TimeIn);
                printf("\n\tEnter New TimeOut : ");
            		scanf("\t %d", &TimeOut);

                ptr->vd.index = index;
                ptr->vd.vehicle_num = vehicle_num;
            		strcpy(ptr->vd.visitor_name, visitor_name);
          	    ptr->vd.visitor_contact = visitor_contact;

          	    printf("\n\n\tvisitor Index - %d\n\tvisitor visitor_name- %s\n\tvisitor vehicle_num- %d\n\tvisitor visitor_contact - %d\n\tvisitor TimeIn - %d\n\tvisitor TimeOut - %d", ptr->vd.index, ptr->vd.visitor_name, ptr->vd.vehicle_num, ptr->vd.visitor_contact, ptr->vd.TimeIn, ptr->vd.TimeOut);
          	    printf("\n\n\tSociety Record Updated Successfully !!!\n");
                flag = 0;
                update_vis_file(ptr->vd);
            break;
          } else {
                    flag = 1;
              }
            i++;
            ptr = ptr -> next;
        }

        if (flag == 1) {
            printf("\n\n\tvisitor vehicle_num not found\n");
        }
    }
}



  /*VISITORS SEARCH*/
  /*void search_visitors_D(int vehicle_num)
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
  /*void update_visitors_D(int vehicle_num, int new_vehicle_num)
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
  }*/

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
