//doctor data..
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "hosp.h"
#define size 1000

struct docData readdoc;
extern void insert_doc(struct docData doc_data);
struct doctor *arrr[size];
int num_record;

//init array of list to NULL
void init_doc() {
    int i;
    for(i = 1; i < size; i++) {
        arrr[i] = NULL;
    }
}

//readind doctor datafile
void read_doc() {
    int fd;
    num_record = 0;
    fd = open(DOCTOR_DATAFILE, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("read failed");
    }
    while (read(fd, (void *)&readdoc, sizeof(struct docData))) {
        printf("%d.\t%d\t%s\t%s\t%d\n", readdoc.index, readdoc.id, readdoc.name, readdoc.address, readdoc.contact);
        insert_doc(readdoc);
        num_record++;
    }
    close(fd);
}

//Write to doctor datafile
void write_doc(struct docData doc) {
    int fd;
    fd = open(DOCTOR_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("file open failed...");
    }
    write(fd, (void *)&doc, sizeof(struct docData));
    close(fd);
}

//update to file
void update_doc_file(struct docData update) {
    int fd;
    fd = open(DOCTOR_DATAFILE, O_RDWR, 0644);
    lseek (fd, update.index * sizeof (struct docData), SEEK_SET);
    if (write(fd, &update, sizeof(struct docData)) < 0) {
        perror("write failed");
        exit(1);
    }
    close(fd);
}

//delete from file
void delete_doc_file(struct docData delete) {
    int fd;
    struct docData temp;

    fd = open(DOCTOR_DATAFILE, O_RDWR);
    lseek (fd, (num_record - 1) * sizeof (struct docData), SEEK_SET);
    read(fd, &temp, sizeof(struct docData));
    temp.index = delete.index;
    lseek(fd, temp.index * sizeof(struct docData), SEEK_SET);
    write(fd, &temp, sizeof(struct docData));
    num_record --;
    ftruncate(fd, num_record * sizeof(struct docData));
    printf("\n\n\tdelete successful...\n");
    close(fd);
}

/*doctor insertion*/
void insert_doc(struct docData doc_data) {
    struct doctor *newNode = (struct doctor*)malloc(sizeof(struct doctor));
    newNode->docd.index = doc_data.index;
    newNode->docd.id = doc_data.id;
    strcpy(newNode->docd.name, doc_data.name);
    strcpy(newNode->docd.address, doc_data.address);
    newNode->docd.contact = doc_data.contact;
    newNode->next = NULL;
    newNode->prev = NULL;
    //calculate hash key
    int key = doc_data.id % size;
    //update_pat_file(key);
    if (arrr[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        arrr[key] = newNode;
    } else {
        struct doctor *temp = arrr[key];

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

/*display data*/
void display_doc() {
    int i;
    int index = 0;
    struct doctor *temp;
    printf("\n==================================================================\n\n");
    printf("\t\tDOCTOR DATAFILE\n\n");
    printf("SR.\tID\tNAME\tADDRESS\tCONTACT\n\n");
    for(i = 0; i < size; i++) {
        temp = arrr[i];
        while(temp) {
            printf("%d. ",index);
            printf("\t%d\t%s\t%s\t%d\n", temp->docd.id, temp->docd.name, temp->docd.address, temp->docd.contact);
            temp = temp->next;
            index++;
        }
    }
}

/*serch data*/
void search_doc(int id) {
    struct doctor *ptr;
    int i=0, flag;
    int key = id % size;
    ptr = arrr[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while (ptr != NULL) {
            if (ptr->docd.id == id) {
                printf("\n\n\tDoctor ID found at location : %d ", i+1);
                printf("\n\n\tID\t - \t %d\n\tName\t - \t %s\n\tAddress\t - \t %s\n\tContact\t - \t %d\n", ptr->docd.id, ptr->docd.name, ptr->docd.address, ptr->docd.contact);
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
            printf("\n\n\tDoctor ID not found\n");
        }
    }
}

/*updation*/
void update_doc(int id) {
    struct doctor *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = arrr[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while (ptr != NULL) {
            if (ptr->docd.id == id) {
                printf("\n\n\tDoctor old Data !!!\n");
                printf("\n\n\tID\t - \t %d\n\tName\t - \t %s\n\tAddress\t - \t %s\n\tContact\t - \t %d\n", ptr->docd.id, ptr->docd.name, ptr->docd.address, ptr->docd.contact);
        		printf("\n\n\tDoctor New Data !!!\n");

                //int index;
                struct docData doc;

                printf("\n\tEnter Same Index : ");
                scanf("\t %d", &doc.index);

                printf("\n\tEnter Same ID : ");
                scanf("\t\n%d", &doc.id);
                printf("\n\tEnter New Name : ");
                scanf("\t\n %[^\n]%*c", doc.name);
                printf("\n\tEnter New Address : ");
                scanf("\t\n %[^\n]%*c", doc.address);
                printf("\n\tEnter New Contact : ");
                scanf("\t\n %d", &doc.contact);

                ptr->docd.index = doc.index;
                ptr->docd.id = doc.id;
                strcpy(ptr->docd.name, doc.name);
                strcpy(ptr->docd.address, doc.address);
                ptr->docd.contact = doc.contact;

    		    printf("\n\n\tID\t - \t %d\n\tName\t - \t %s\n\tAddress\t - \t %s\n\tContact\t - \t %d\n", ptr->docd.id, ptr->docd.name, ptr->docd.address, ptr->docd.contact);
    		    printf("\n\n\tDoctor Record Updated Successfully !!!\n");
                flag = 0;
                update_doc_file(ptr->docd);
                break;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr -> next;
        }
        if (flag == 1) {
            printf("\n\n\tDoctor ID not found\n");
        }
    }
}

//delete operation
void delete_doc(int id) {
    int key = id % size;
    struct doctor *toDelete;
    struct doctor *ptr = arrr[key];

    if(ptr == NULL) {
        printf("\n List is Empty");
    } else if(ptr->docd.id == id) {
        delete_doc_file(ptr->docd);
        ptr = NULL;
        arrr[key] = NULL;
        free(ptr);
    } else {
        delete_doc_file(ptr->docd);
        while(ptr->next != NULL) {
            if (ptr->next->docd.id == id) {
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
