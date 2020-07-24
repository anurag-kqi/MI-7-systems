#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define size 10
struct doctor
{
    int id;
    char name[20];
    char address[50];
    int contact;
    struct doctor *next;
    struct doctor *prev;

};

    struct doctor *index_doc[size];
    void insert_doc(int id, char name[], char address[], int contact);
    void display_doc();
    void delete_doc(int id);
    void update_doc(int id);

void init_doc()
{
    int i;
    struct doctor *newNode = malloc(sizeof(struct doctor));
    struct doctor D1;
    int id, contact, count;
    char name[30], address[50], buf[100];
    int fd = open("Doc.txt", O_RDONLY );
    if(fd < 0){
        perror("open failed");
        exit(-1);
    }
    while(read(fd ,(void*)&D1, sizeof(struct doctor))){
    printf("\n%d %s %s %d\n", D1.id, D1.name, D1.address, D1.contact);
    }
    close(fd);
    for(i = 0; i < size; i++) {
        //index_pat[i] = NULL;
        index_doc[i] = NULL;
    }
}


void insert_doc(int id, char name[], char address[], int contact)
{

    struct doctor *newNode = malloc(sizeof(struct doctor));
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    newNode->contact = contact;
    newNode->next = NULL;
    newNode->prev = NULL;


    int key = id % size;

    if(index_doc[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        index_doc[key] = newNode;
    }
    else {
        struct doctor *temp = index_doc[key];

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
    int fd = open("Doc.txt", O_RDWR | O_CREAT | O_APPEND);
    if (fd < 0) {
            perror("file open failed");
            exit(1);
    }
    int count = write(fd, newNode ,sizeof(struct doctor));
    if (count < 0) {
            perror("write failed");
            exit(1);
    }
    printf("\n\nNode inserted Successfully...!\n");
    close(fd);
}

void display_doc()
{
    int i;

    for(i = 0; i < size; i++) {
        struct doctor *temp = index_doc[i];
        //printf("\t\tID\tName\tAddress\tContact");
        printf("\nDoctor Data[%d]-->",i);
        while(temp) {
            printf("%d\t%s\t%s\t%d -->",temp->id, temp->name, temp->address, temp->contact);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void delete_doc(int id)
{
    int key = id % size;
    struct doctor *ptr = index_doc[key], *toDelete;

    if (ptr == NULL) {
        printf("\n\n\tList is Empty !!!\n");
    }
    else if (ptr->id == id) {
        if (ptr->prev == NULL && ptr->next == NULL) {
            free(ptr);
            index_doc[key] = NULL;
        } else {
            index_doc[key] = ptr->next;
            index_doc[key]->prev = NULL;
            ptr->next = NULL;
            free(ptr);
            return ;
        }

    } 
 else {
	        while (ptr->next != NULL) {
              if (ptr->next->id == id) {
                  toDelete = ptr->next;
                  if (toDelete->next == NULL) {
                      ptr->next = NULL;
                      free(toDelete);
                      return ;
                  } else {
                        ptr->next = toDelete->next;
                        toDelete->next->prev = toDelete->prev;
                        free(toDelete);
                    }
              }
              ptr = ptr->next;
          }
          printf("\n\n\tnode not found\n");
      }
  }

void update_doc(int id)
{
    struct doctor *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = index_doc[key];
    if(ptr == NULL) {
        printf("\nEmpty List\n");
    } else {

        while (ptr != NULL) {
            if(ptr->id == id) {
                printf("\n Old Data !!!");
                printf("\n\nDoctor Id - %d\nDoctor Name - %s\n Address - %s\n Contact - %d",
                       ptr->id, ptr->name, ptr->address, ptr->contact);

		printf("\nDoctor New Data !!!");

		int id, contact;
        		char name[20], address[50];

		//printf("Enter ID, Name, Address, Contact respectively : ");
		//scanf("%d %s %s %d", &id, &name, &address, &contact);
		printf("\nEnter Doctor ID:");
                                    	scanf("%d",&id);
                                    	printf("\nEnter Doctor Name:");
                                    	scanf("%s", name);
                                    	printf("\nEnter Doctor Address:");
                                    	scanf("%s", address);
                                    	printf("\nEnter Doctor Contact:");
                                    	scanf("%d",&contact);

            		ptr->id = id;
    		strcpy(ptr->name, name);
    		strcpy(ptr->address, address);
    		ptr->contact = contact;

		printf("\n\ndoctor Id - %d\ndoctor Name - %s\n Address - %s\n Contact - %d",
                       ptr->id, ptr->name, ptr->address, ptr->contact);
		printf("\n Record Updated Successfully !!!");
                flag = 0;
                break;
            }
	    else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }

        if(flag==1) {
            printf("\nID not found\n");
        }
    }

}




