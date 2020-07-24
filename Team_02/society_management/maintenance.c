//maintenance data
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "soc.h"
#define size 1000

struct maintData readmaint;
extern void insert_maint(struct maintData);
struct maintenance *arr1[size];
int num_records1;

//init array of list to NULL
void init_maint() {
    int i;
    for(i = 1; i < size; i++) {
        arr1[i] = NULL;
    }
}

//read maintenance datafile
void read_maint() {
    int fd1;
    num_records1 = 0;
    fd1 = open(MAINTENANCE_DATAFILE, O_RDWR | O_CREAT, 0644);
    if(fd1 < 0) {
        perror("read failed");
    }
    while (read(fd1, (void *)&readmaint, sizeof(struct maintData))) {
        printf("%d.\t%d\t\t%d\t%d\n", readmaint.index1, readmaint.flat_num1, readmaint.water_bill, readmaint.electricity_bill);
        insert_maint(readmaint);
        num_records1++;
    }
    close(fd1);
}

//Write to maintenance datafile
void write_maint(struct maintData maint) {
    int fd1;
    fd1 = open(MAINTENANCE_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd1 < 0) {
        perror("file open failed...");
    }
    write(fd1, (void *)&maint, sizeof(struct maintData));
    close(fd1);
}

//update to file
void update_maint_file(struct maintData update) {
    int fd1;
    fd1 = open(MAINTENANCE_DATAFILE, O_RDWR, 0644);
    lseek (fd1, update.index1 * sizeof (struct maintData), SEEK_SET);
    if (write(fd1, &update, sizeof(struct maintData)) < 0) {
        perror("write failed");
        exit(1);
    }
    close(fd1);
}

//delete record from maintenance datafile
void delete_maint_file(struct maintData delete) {
    int fd1;
    struct maintData temp2;
    fd1 = open(MAINTENANCE_DATAFILE, O_RDWR);
    lseek (fd1, (num_records1 - 1) * sizeof (struct maintData), SEEK_SET);
    read(fd1, &temp2, sizeof(struct maintData));
    temp2.index1 = delete.index1;
    lseek(fd1, temp2.index1 * sizeof(struct maintData), SEEK_SET);
    write(fd1, &temp2, sizeof(struct maintData));
    num_records1 --;
    ftruncate(fd1, num_records1 * sizeof(struct maintData));
    printf("\n\n\tdelete successful...\n");
    close(fd1);
}

/*maintenance insertion*/
void insert_maint(struct maintData maint_data) {
    struct maintenance *newNode1 = (struct maintenance*)malloc(sizeof(struct maintenance));
    newNode1->md.index1 = maint_data.index1;
    newNode1->md.flat_num1 = maint_data.flat_num1;
    newNode1->md.water_bill = maint_data.water_bill;
    newNode1->md.electricity_bill = maint_data.electricity_bill;
    newNode1->next1 = NULL;
    newNode1->prev1 = NULL;
    //calculate hash key
    int key1 = maint_data.flat_num1 % size;

    if (arr1[key1] == NULL) {
        newNode1->next1 = NULL;
        newNode1->prev1 = NULL;
        arr1[key1] = newNode1;
    } else {
        struct maintenance *temp1 = arr1[key1];

        while (temp1->next1 != NULL) {
            temp1 = temp1->next1;
        }
        temp1->next1 = newNode1;
        newNode1->prev1 = temp1;
    }
}

/*display data*/
void display_maint() {
    int i;
    int index = 0;;
    struct maintenance *temp1;
    printf("\n==================================================================\n\n");
    printf("SR. FLAT_NO    WATER_BILL    ELECTRICITY_BILL\n\n");
    for(i = 0; i < size; i++) {
        temp1 = arr1[i];
        while(temp1) {
            printf("%d. ",index);
            printf("\t%d\t\t%d\t%d\n", temp1->md.flat_num1, temp1->md.water_bill, temp1->md.electricity_bill);
            temp1 = temp1->next1;
            index++;
        }
    }
}

/*serch data*/
void search_maint(int flat_num1) {

    struct maintenance *ptr1;
    int flag;
    int key1 = flat_num1 % size;
    ptr1 = arr1[key1];
    if (ptr1 == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while (ptr1 != NULL) {
            if (ptr1->md.flat_num1 == flat_num1) {
                printf("\n\n\tflat_num\t -\t %d\n\twater_bill\t -\t %d\n\telectricity_bill\t -\t %d\n", ptr1->md.flat_num1, ptr1->md.water_bill, ptr1->md.electricity_bill);
                flag = 0;
                break;
            } else {
                flag=1;
            }            
            ptr1 = ptr1 -> next1;
        }
        if (flag==1) {
            printf("\n\n\tflat number not found\n");
        }
    }
}

/*updation maintenance data*/
void update_maint(int flat_num1) {

    struct maintenance *ptr1;
    int i=0, flag;
    int key1 = flat_num1 % size;
    ptr1 = arr1[key1];
    if (ptr1 == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while (ptr1 != NULL) {
            if (ptr1->md.flat_num1 == flat_num1) {
                printf("\n\n\tmaintenance old Data !!!\n");
                printf("\n\n\tmaintenance Index - %d\n\tmaintenance flat_num1 - %d\n\tmaintenance water_bill - %d\n\tmaintenance electricity_bill -%d", ptr1->md.index1, ptr1->md.flat_num1, ptr1->md.water_bill, ptr1->md.electricity_bill);
                printf("\n\n\tmaintenance New Data !!!\n");

                int flat_num1, water_bill, electricity_bill, index1;
                printf("\n\tEnter Same Index : ");
                scanf("\t %d", &index1);
                printf("\n\tEnter Same flat number : ");
          		scanf("\t %d", &flat_num1);
                printf("\n\tEnter New water_bill : ");
          		scanf("\t %d", &water_bill);
                printf("\n\tEnter New electricity_bill :");
                scanf("\t %d", &electricity_bill);

                ptr1->md.index1 = index1;
                ptr1->md.flat_num1 = flat_num1;
          		ptr1->md.water_bill = water_bill;
        	    ptr1->md.electricity_bill = electricity_bill;

        	    printf("\n\n\tsociety Index - %d\n\tmaintenance flat_num1- %d\n\tmaintenance water_bill - %d\n\tmaintenance electricity_bill - %d", ptr1->md.index1, ptr1->md.flat_num1, ptr1->md.water_bill, ptr1->md.electricity_bill);
        	    printf("\n\n\tSociety Record Updated Successfully !!!\n");
                flag = 0;
                update_maint_file(ptr1->md);
                break;
            } else {
                flag = 1;
            }
            i++;
            ptr1 = ptr1 -> next1;
        }
        if (flag == 1) {
            printf("\n\n\tmaintenance flat_num not found\n");
        }
    }
}

//delete maintenance data
void delete_maint(int flat_num1) {
    printf("\n-----%d flat_num1 \n", flat_num1);
    int key1 = flat_num1% size;
    struct maintenance *ptr1 = arr1[key1], *toDelete;
    if(ptr1 == NULL) {
        printf("\n List is Empty");
    } else if (ptr1->md.flat_num1 == flat_num1) {
        delete_maint_file(ptr1->md);
        ptr1 = NULL;
        arr1[key1] = NULL;
        free(ptr1);
    } else {
        delete_maint_file(ptr1->md);
    	while (ptr1->next1 != NULL) {
            if (ptr1->next1->md.flat_num1 == flat_num1) {
                ptr1 = NULL;
                toDelete = ptr1->next1;
            	ptr1->next1 = toDelete->next1;
            	toDelete->next1->prev1 = ptr1;
            	free(toDelete);
            }
            ptr1 = ptr1->next1;
        }
    }
}
