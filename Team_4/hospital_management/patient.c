//patient data..
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "hosp.h"
#define size 1000

struct patData readpat;
extern void insert_pat(struct patData pat_data);
struct patient *arr[size];
int num_records;

//init array of list to NULL
void init_pat() {
    int i;
    for(i = 1; i < size; i++) {
        arr[i] = NULL;
    }
}

//readind patient datafile
void read_pat() {
    int fd;
    num_records = 0;
    fd = open(PATIENT_DATAFILE, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("read failed");
    }
    while (read(fd, (void *)&readpat, sizeof(struct patData))) {
        printf("%d.\t%d\t%s\t%d\t%s\t%s\t%d\t%s\n", readpat.index, readpat.id, readpat.name, readpat.age, readpat.bloodgrp, readpat.address, readpat.contact, readpat.symptoms);
        insert_pat(readpat);
        num_records++;
    }
    close(fd);
}

//Write to patient datafile
void write_pat(struct patData pat) {
    int fd;
    fd = open(PATIENT_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("file open failed...");
    }
    write(fd, (void *)&pat, sizeof(struct patData));
    close(fd);
}

//update to file
void update_pat_file(struct patData update) {
    int fd;
    fd = open(PATIENT_DATAFILE, O_RDWR, 0644);
    lseek (fd, update.index * sizeof (struct patData), SEEK_SET);
    if (write(fd, &update, sizeof(struct patData)) < 0) {
        perror("write failed");
        exit(1);
    }
    close(fd);
}

//delete from file
void delete_pat_file(struct patData delete) {
    int fd;
    struct patData temp;

    fd = open(PATIENT_DATAFILE, O_RDWR);
    lseek (fd, (num_records - 1) * sizeof (struct patData), SEEK_SET);
    read(fd, &temp, sizeof(struct patData));
    temp.index = delete.index;
    lseek(fd, temp.index * sizeof(struct patData), SEEK_SET);
    write(fd, &temp, sizeof(struct patData));
    num_records --;
    ftruncate(fd, num_records * sizeof(struct patData));
    printf("\n\n\tdelete successful...\n");
    close(fd);
}

/*patient insertion*/
void insert_pat(struct patData pat_data) {
    struct patient *newNode = (struct patient*)malloc(sizeof(struct patient));
    newNode->patd.index = pat_data.index;
    newNode->patd.id = pat_data.id;
    strcpy(newNode->patd.name, pat_data.name);
    newNode->patd.age = pat_data.age;
    strcpy(newNode->patd.bloodgrp, pat_data.bloodgrp);
    strcpy(newNode->patd.address, pat_data.address);
    newNode->patd.contact = pat_data.contact;
    strcpy(newNode->patd.symptoms, pat_data.symptoms);
    newNode->next = NULL;
    newNode->prev = NULL;
    //calculate hash key
    int key = pat_data.id % size;
    //update_pat_file(key);
    if (arr[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        arr[key] = newNode;
    } else {
        struct patient *temp = arr[key];

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

/*display data*/
void display_pat() {
    int i;
    int index = 0;
    struct patient *temp;
    printf("\n==================================================================\n\n");
    printf("\t\tPATIENT DATAFILE\n\n");
    printf("SR.\tID\tNAME\tAGE\tBLOO_DGROUP\tADDRESS\tCONTACT\tSYMPTOMS\n\n");
    for(i = 0; i < size; i++) {
        temp = arr[i];
        while(temp) {
            printf("%d. ",index);
            printf("\t%d\t%s\t%d\t%s\t\t%s\t%d\t%s\n", temp->patd.id, temp->patd.name, temp->patd.age, temp->patd.bloodgrp, temp->patd.address, temp->patd.contact, temp->patd.symptoms);
            temp = temp->next;
            index++;
        }
    }
}

/*serch data*/
void search_pat(int id) {
    struct patient *ptr;
    int i=0, flag;
    int key = id % size;
    ptr = arr[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while (ptr != NULL) {
            if (ptr->patd.id == id) {
                printf("\n\n\tPatient ID found at location : %d ", i+1);
                printf("\n\n\tID\t - \t %d\n\tName\t - \t %s\n\tAge\t - \t %d\n\tBloodGrp - \t %s\n\tAddress\t - \t %s\n\tContact\t - \t %d\n\tSymptms\t - \t %s\n", ptr->patd.id, ptr->patd.name, ptr->patd.age, ptr->patd.bloodgrp, ptr->patd.address, ptr->patd.contact, ptr->patd.symptoms);
                flag = 0;
                break;
            }
            else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if (flag==1) {
            printf("\n\n\tPatient ID not found\n");
        }
    }
}

/*updation*/
void update_pat(int id) {
    struct patient *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = arr[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while (ptr != NULL) {
            if (ptr->patd.id == id) {
                printf("\n\n\tPatient old Data !!!\n");
                printf("\n\n\tID\t - \t %d\n\tName\t - \t %s\n\tAge\t - \t %d\n\tBloodGrp - \t %s\n\tAddress\t - \t %s\n\tContact\t - \t %d\n\tSymptms\t - \t %s\n", ptr->patd.id, ptr->patd.name, ptr->patd.age, ptr->patd.bloodgrp, ptr->patd.address, ptr->patd.contact, ptr->patd.symptoms);
        		printf("\n\n\tPatient New Data !!!\n");

                //int index;
                struct patData pat;

                printf("\n\tEnter Same Index : ");
                scanf("\t %d", &pat.index);

                printf("\n\tEnter Same ID : ");
                scanf("\t\n%d", &pat.id);
                printf("\n\tEnter New Name : ");
                scanf("\t\n %[^\n]%*c", pat.name);
                printf("\n\tEnter New Age : ");
                scanf("\t\n%d", &pat.age);
                printf("\n\tEnter New Blood Group : ");
                scanf("\t\n %[^\n]%*c", pat.bloodgrp);
                printf("\n\tEnter New Address : ");
                scanf("\t\n %[^\n]%*c", pat.address);
                printf("\n\tEnter New Contact : ");
                scanf("\t\n %d", &pat.contact);
                printf("\n\tEnter New Symptoms : ");
                scanf("\t\n %[^\n]%*c", pat.symptoms);

                ptr->patd.index = pat.index;
                ptr->patd.id = pat.id;
                strcpy(ptr->patd.name, pat.name);
                ptr->patd.age = pat.age;
                strcpy(ptr->patd.bloodgrp, pat.bloodgrp);
                strcpy(ptr->patd.address, pat.address);
                ptr->patd.contact = pat.contact;
                strcpy(ptr->patd.symptoms, pat.symptoms);

    		    printf("\n\n\tID\t - \t %d\n\tName\t - \t %s\n\tAge\t - \t %d\n\tBloodGrp - \t %s\n\tAddress\t - \t %s\n\tContact\t - \t %d\n\tSymptms\t - \t %s\n", ptr->patd.id, ptr->patd.name, ptr->patd.age, ptr->patd.bloodgrp, ptr->patd.address, ptr->patd.contact, ptr->patd.symptoms);
    		    printf("\n\n\tPatient Record Updated Successfully !!!\n");
                flag = 0;
                update_pat_file(ptr->patd);
                break;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr -> next;
        }
        if (flag == 1) {
            printf("\n\n\tPatient ID not found\n");
        }
    }
}

//delete operation
void delete_pat(int id) {
    int key = id % size;
    struct patient *toDelete;
    struct patient *ptr = arr[key];

    if(ptr == NULL) {
        printf("\n List is Empty");
    } else if(ptr->patd.id == id) {
        delete_pat_file(ptr->patd);
        ptr = NULL;
        arr[key] = NULL;
        free(ptr);
    } else {
        delete_pat_file(ptr->patd);
        while(ptr->next != NULL) {
            if (ptr->next->patd.id == id) {
                ptr = NULL;
                toDelete = ptr->next;

                ptr->next = toDelete->next;
                toDelete->next->prev = ptr;
                free(toDelete);
            }
            ptr = ptr->next;
        }
    }
}
