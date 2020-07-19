
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "soc.h"
#define size 9

struct socData readsoc;
extern void insert_soc(struct socData);
struct society *arr[size];
int num_records;

//init array of list to NULL
void init_soc()
{
    int i;
    for(i = 1; i < size; i++) {
        arr[i] = NULL;
    }
}


void read_soc() {
  int fd;
  num_records = 0;
  fd = open(SOCIETY_DATAFILE, O_RDWR | O_CREAT, 0644);
  if(fd < 0) {
     perror("read failed");
  }
  while (read(fd, (void *)&readsoc, sizeof(struct socData))) {
    printf("%d.\t%s\t\t%d\t%d\n", readsoc.index, readsoc.owner_name, readsoc.flat_num, readsoc.owner_contact);
    insert_soc(readsoc);
    num_records++;
    }
    close(fd);
}

//Write the student data
void write_soc(struct socData soc)
{
  int fd;
  fd = open(SOCIETY_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
  if (fd < 0) {
    perror("file open failed...");
  }
  write(fd, (void *)&soc, sizeof(struct socData));
  close(fd);
}


//update to file
void update_soc_file(struct socData update)
{
  int fd;
  fd = open(SOCIETY_DATAFILE, O_RDWR, 0644);
  lseek (fd, update.index * sizeof (struct socData), SEEK_SET);
  if (write(fd, &update, sizeof(struct socData)) < 0) {
      perror("write failed");
      exit(1);
  }
  close(fd);
}


/*society insertion*/
void insert_soc(struct socData soc_data)
{
      //create a newnode with value
      struct society *newNode = (struct society*)malloc(sizeof(struct society));
      newNode->sd.index = soc_data.index;
      strcpy(newNode->sd.owner_name, soc_data.owner_name);
      newNode->sd.flat_num = soc_data.flat_num;
      newNode->sd.owner_contact = soc_data.owner_contact;
      newNode->next = NULL;
      newNode->prev = NULL;
      //calculate hash key
      int key = soc_data.flat_num % size;

      //update_stud_file(key);

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

/*void delete_soc(int flat_num){

      printf("running line %d", __LINE__);
      int key = flat_num % size;
      struct society *ptr;
      struct society *toDelete;;
      ptr = arr[key];

      if (ptr == NULL) {
        printf("\n\n\tList is Empty !!!\n");
      }
      printf("running line %d", __LINE__);

      else if (ptr->sd.flat_num == flat_num) {
        arr[key] = arr[key]->next;
        arr[key]->prev = NULL;//segmentation fault
        ptr->next = NULL;
        free(ptr);
        printf("\n\n\tFirst node deleted\n");
      }
      else {
        while (ptr->next != NULL) {
          if (ptr->next->sd.flat_num == flat_num) {
            toDelete = ptr->next;
            if (toDelete->next == NULL) {
              ptr->next = NULL;
              free(toDelete);
              printf("\n\n\tLast Node is deleted\n");
              return;
            }
            else {
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
  printf("\n==================================================================\n\n");
  printf("\t\tSOCIETY DATAFILE\n\n");
  printf("SR.\tOW_NAME\tFLAT_NO\tOW_CONTACT\n\n");
  for(i = 0; i < size; i++) {
    temp = arr[i];
    while(temp) {
      printf("%d\t %s\t %d\t%d\n", temp->sd.index, temp->sd.owner_name, temp->sd.flat_num, temp->sd.owner_contact);
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
            if (ptr->sd.flat_num == flat_num) {
                printf("\n\n\tSociety flat number found at location : %d ", key);
                printf("\n\n\towner_name\t -\t %s\n\tflat_num\t -\t %d\n\towner_contact\t -\t %d\n", ptr->sd.owner_name, ptr->sd.flat_num, ptr->sd.owner_contact);
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
            if (ptr->sd.flat_num == flat_num) {
                printf("\n\n\tSociety old Data !!!\n");
                printf("\n\n\tsociety Index - %d\n\tsociety owner_name - %s\n\tsociety flat_num - %d\n\tsociety owner_contact - %d",
                       ptr->sd.index, ptr->sd.owner_name, ptr->sd.flat_num, ptr->sd.owner_contact);

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

            ptr->sd.index = index;
            ptr->sd.flat_num = flat_num;
        		strcpy(ptr->sd.owner_name, owner_name);
    		    ptr->sd.owner_contact = owner_contact;

    		    printf("\n\n\tsociety Index - %d\n\tsociety owner_name- %s\n\tsociety flat_num- %d\n\tsociety owner_contact - %d",
                               ptr->sd.index, ptr->sd.owner_name, ptr->sd.flat_num, ptr->sd.owner_contact);
    		    printf("\n\n\tSociety Record Updated Successfully !!!\n");
                    flag = 0;
                    printf("AAA:%d index %s owner_name:", ptr->sd.index, ptr->sd.owner_name);
                update_soc_file(ptr->sd);
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
