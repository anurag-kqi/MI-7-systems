//maintenance data..
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "soc.h"
#define size 1000

int newsockfd;
struct maintData readmaint;
struct maintData maint;
extern void insert_maint(struct maintData);
struct maintenance *arr11[size];
int num_records;
extern void display1_maint(struct maintData maintd);
extern void update_maint(struct maintData upmd);


//init arr1ay of list to NULL
void init_maint() {
    int i;
    for(i = 1; i < size; i++) {
        arr11[i] = NULL;
    }
}

//readind maintenance datafile
void read_maint() {
    int fd;
    num_records = 0;
    fd = open(MAINTENANCE_DATAFILE, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("read failed");
    }
    while (read(fd, (void *)&readmaint, sizeof(struct maintData))) {
        printf("%d.\t%d\t\t%d\t%d\n", readmaint.index, readmaint.flat_num1, readmaint.water_bill, readmaint.electricity_bill);
        insert_maint(readmaint);
        num_records++;
    }
    close(fd);
}

//Write to student datafile
void write_maint(struct maintData maint) {
    int fd;
    fd = open(MAINTENANCE_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("file open failed...");
    }
    write(fd, (void *)&maint, sizeof(struct maintData));
    close(fd);
}

//update to file
void update_maint_file(struct maintData update) {
    int fd;
    fd = open(MAINTENANCE_DATAFILE, O_RDWR, 0644);
    lseek (fd, update.index * sizeof (struct maintData), SEEK_SET);
    if (write(fd, &update, sizeof(struct maintData)) < 0) {
        perror("write failed");
        exit(1);
    }
    close(fd);
}

//delete from file
void delete_maint_file(struct maintData delete) {
    int fd;
    struct maintData temp1;

    fd = open(MAINTENANCE_DATAFILE, O_RDWR);
    lseek (fd, (num_records - 1) * sizeof (struct maintData), SEEK_SET);
    read(fd, &temp1, sizeof(struct maintData));
    temp1.index = delete.index;
    lseek(fd, temp1.index * sizeof(struct maintData), SEEK_SET);
    write(fd, &temp1, sizeof(struct maintData));
    num_records --;
    ftruncate(fd, num_records * sizeof(struct maintData));
    printf("\n\n\tdelete successful...\n");
    close(fd);
}

/*maintenance insertion*/
void insert_maint(struct maintData maint_data) {
    struct maintenance *newNode = (struct maintenance*)malloc(sizeof(struct maintenance));
    newNode->md.index = maint_data.index;
    newNode->md.flat_num1 = maint_data.flat_num1;
    newNode->md.water_bill = maint_data.water_bill;
    newNode->md.electricity_bill = maint_data.electricity_bill;
    newNode->next1 = NULL;
    newNode->prev1 = NULL;
    //calculate hash key
    int key = maint_data.flat_num1 % size;
    //update_stud_file(key);
    if (arr1[key] == NULL) {
        newNode->next1 = NULL;
        newNode->prev1 = NULL;
        arr1[key] = newNode;
    } else {
        struct maintenance *temp1 = arr1[key];

        while (temp1->next1 != NULL) {
            temp1 = temp1->next1;
        }
        temp1->next1 = newNode;
        newNode->prev1 = temp1;
    }
}

/*display data*/
void display_maint(int newsockfd) {
    int i;
    int index = 0;
    int display_data = 1;
    struct maintenance *temp1;
    printf("\n==================================================================\n\n");
    printf("\t\tmaintenance DATAFILE\n\n");
    printf("SR.\tOW_NAME\tFLAT_NO\tOW_CONTACT\n\n");
    for(i = 0; i < size; i++) {
        temp1 = arr1[i];
        while(temp1) {
            printf("%d. ",index);
            printf("%s\t %d\t%d\n", temp1->md.flat_num1, temp1->md.water_bill, temp1->md.electricity_bill);
            maint.flat_num1 = temp1->md.flat_num1;
            maint.water_bill = temp1->md.water_bill;
            maint.electricity_bill = temp1->md.electricity_bill;
            write(newsockfd, &display_data, sizeof(int));
            write(newsockfd, &maint, sizeof(struct maintData));
            temp1 = temp1->next1;
            index++;
            // display1_maint(maint);
        }
    }
    display_data = 0;
    write(newsockfd, &display_data, sizeof(int));
}

/*serch data*/
void search_maint(int flat_num1, int newsockfd) {
    struct maintenance *ptr;
    int flag;
    int key = flat_num1 % size;
    ptr = arr1[key];
    if (ptr == NULL) {
        printf("\n\n\tempty List\n");
    } else {
        while (ptr != NULL) {
            if (ptr->md.flat_num1 == flat_num1) {
                printf("\n\tflat_num1\t -\t %d\n\twater_bill\t -\t %d\n\telectricity_bill\t - \t %d", ptr->md.flat_num1, ptr->md.water_bill, ptr electricity_bill);
                maint.flat_num1 = ptr->md.flat_num1;
                maint.water_bill = ptr->md.water_bill;
                maint.electricity_bill = ptr->md.electricity_bill;
                write(newsockfd, &maint, sizeof(struct maintData));
                flag = 0;
                break;
            } else {
                flag=1;
            }
            ptr = ptr -> next1;
        }
        if (flag==1) {
            printf("\n\n\tmaintenance flat number not found\n");
        }
    }
}


/*updation*/
void update_maint(struct maintData upmd) {
    struct maintenance *ptr;
    int i=0, flag;

    int key = upmd.flat_num1 % size;

    ptr = arr1[key];
    if (ptr == NULL) {
        printf("\n\n\temp1ty List\n");
    } else {
        while (ptr != NULL) {
            if (ptr->md.flat_num1 == upmd.flat_num1) {
                printf("\n\n\tmaintenance old Data !!!\n");
                printf("\n\n\tmaintenance Index - %d\n\tmaintenance flat_num1 - %d\n\tmaintenance water_bill - %d\n\telectricity_bill - %d", ptr->md.index, ptr->md.flat_num1, ptr->md.water_bill, ptr->md.electricity_bill);
        		printf("\n\n\tmaintenance New Data !!!\n");

        		int flat_num1, water_bill, index, electricity_bill;
    		    ptr->md.water_bill = upmd.water_bill;
            ptr->md.electricity_bill = upmd.electricity_bill
    		    printf("\n\n\tmaintenance water_bill - %d\n\tmaintenance electricity_bill - %d", ptr->md.water_bill, ptr->md.electricity_bill);
    		    printf("\n\n\tmaintenance Record Updated Successfully !!!\n");
                flag = 0;
                update_maint_file(ptr->md);
                break;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr -> next1;
        }
        if (flag == 1) {
            printf("\n\n\tmaintenance flat_num1 not found\n");
        }
    }
}

//delete operation
void delete_maint(int flat_num1) {
    int key = flat_num1 % size;
    struct maintenance *toDelete;
    struct maintenance *ptr = arr1[key];

    if(ptr == NULL) {
        printf("\n List is Empty");
    } else if(ptr->md.flat_num1 == flat_num1) {
        delete_maint_file(ptr->md);
        ptr = NULL;
        arr1[key] = NULL;
        free(ptr);
    } else {
        delete_maint_file(ptr->md);
        while(ptr->next1 != NULL) {
            if (ptr->next1->md.flat_num1 == flat_num1) {
                ptr = NULL;
                toDelete = ptr->next1;

                ptr->next1 = toDelete->next1;
                toDelete->next1->prev1 = ptr;
                free(toDelete);
            }
            ptr = ptr->next1;
        }
    }
}
