#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define size 10
struct patient
{
    int id;
    char name[20];
    int age;
    char bloodgrp[10];
    char address[50];
    int contact;
    char symptoms[40];
    struct patient *next;
    struct patient *prev;

};


    struct patient *index_pat[size];

void init_pat()
{
    int i;
    struct patient *newNode = malloc(sizeof(struct patient));
    struct patient P1;
    int id, contact, age, data, count;
    char name[30], address[50], buf[100];
    int fd = open("Hash.txt", O_RDONLY );
    if(fd < 0){
        perror("open failed");
        exit(-1);
    }
    while(read(fd ,(void*)&P1, sizeof(struct patient))){
    printf("%d %s %d %s %s %d %s", P1.id, P1.name, P1.age, P1.bloodgrp, P1.address, P1.contact, P1.symptoms);
    }
    close(fd);
    for(i = 0; i < size; i++) {
        index_pat[i] = NULL;
        //index_doc[i] = NULL;
    }
}


void insert_pat(int id, char name[], int age, char bloodgrp[], char address[], int contact, char symptoms[])
{
    //FILE *fp;
    //fp = fopen("Hash.txt", "a+");/*  open for writing */
    struct patient *newNode = malloc(sizeof(struct patient));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->age = age;
    strcpy(newNode->bloodgrp, bloodgrp);
    strcpy(newNode->address, address);
    newNode->contact = contact;
    strcpy(newNode->symptoms, symptoms);
    newNode->next = NULL;
    newNode->prev = NULL;

    int key = id % size;

    if(index_pat[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        index_pat[key] = newNode;
    }
    else {
        struct patient *temp = index_pat[key];

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
    int fd = open("Hash.txt", O_RDWR | O_CREAT | O_APPEND);
    if (fd < 0) {
            perror("file open failed");
            exit(1);
    }
    int count = write(fd, newNode ,sizeof(struct patient));
    if (count < 0) {
            perror("write failed");
            exit(1);
    }
    printf("\n\nNode inserted Successfully...!\n");
    close(fd);

   //fprintf(fp, "ID    = %d\n", id);
   //fprintf(fp, "Name    = %s\n", name);
   //fprintf(fp, "Age    = %d\n", age);
   //fprintf(fp, "BloodGroup    = %s\n", bloodgrp);
   //fprintf(fp, "Address    = %s\n", address);
   //fprintf(fp, "Contact    = %d\n", contact);
   //fprintf(fp, "symptoms    = %s\n", symptoms);
   //fclose(fp);

}


void display_pat()
{
    int i;
    for(i = 0; i < size; i++) {
        struct patient *temp = index_pat[i];
        printf("\nPatient Data[%d]->",i);
        while(temp) {
            printf("%d\t%s\t%d\t%s\t%s\t%d\t%s-->",temp->id, temp->name, temp->age, temp->bloodgrp, temp->address, temp->contact, temp->symptoms);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


void delete_pat(int id)
{
    int key = id % size;
    struct patient *ptr = index_pat[key], *toDelete;

    if (ptr == NULL) {
        printf("\n\n\tList is Empty !!!\n");
    }
    else if (ptr->id == id) {
        if (ptr->prev == NULL && ptr->next == NULL) {
            free(ptr);
            index_pat[key] = NULL;
        } else {
            index_pat[key] = ptr->next;
            index_pat[key]->prev = NULL;
            ptr->next = NULL;
            free(ptr);
            return ;
        }

    } else {
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



void update_pat(int id)
{
    struct patient *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = index_pat[key];
    if(ptr == NULL) {
        printf("\nEmpty List\n");
    } else {

        while (ptr != NULL) {
            if(ptr->id == id) {
                printf("\n Old Data !!!");
                printf("\n\nPatient Id - %d\nPatient Name - %s\n Age - %d\n Blood Group - %s\n Address - %s\n Contact - %d\n Symptoms - %s",
                       ptr->id, ptr->name, ptr->age, ptr->bloodgrp, ptr->address, ptr->contact, ptr->symptoms);

		printf("\nPatient New Data !!!");

		int id, contact, age;
    		char name[20], bloodgrp[10];
    		char address[50], symptoms[40];

		//printf("Enter ID, Name, Age, Address, Contact respectively : ");
		//scanf("%d %s %d %s %s %d", &id, &name, &age, &bloodgrp, &address, &contact);
		printf("\nEnter Patient ID:");
                scanf("%d",&id);
                printf("\nEnter Patient Name:");
                scanf("%s", name);
                printf("\nEnter Patient Age:");
                scanf("%d",&age);
                printf("\nEnter Patient Blood Group:");
                scanf("%s", bloodgrp);
          	printf("\nEnter Patient Address:");
                scanf("%s", address);
                printf("\nEnter Patient Contact:");
                scanf("%d",&contact);
                printf("\nEnter Disease Symptoms:");
                scanf("%s", symptoms);
            	ptr->id = id;
    		strcpy(ptr->name, name);
    		ptr->age = age;
    		strcpy(ptr->bloodgrp, bloodgrp);
    		strcpy(ptr->address, address);
    		ptr->contact = contact;
		strcpy(ptr->symptoms, symptoms);
           	printf("\n\nPatient Id - %d\nPatient Name - %s\nAge - %d\n Address - %s\n Contact - %d\n Symptoms - %s",ptr->id, ptr->name, ptr->age, ptr->address, ptr->contact, ptr->symptoms);
            	printf("\n Record Updated Successfully !!!");
                flag = 0;
                break;
            	}else {

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
