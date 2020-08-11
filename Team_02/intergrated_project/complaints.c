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

int newsockfd;
struct comData readcom;
struct comData com;
extern void insert_complaints_D(struct comData);
struct complaint *arr3[size];
int num_records3;

/*init array of list to NULL*/
void init_complaints_D() {
    int i;
    for(i = 1; i < size; i++) {
    arr3[i] = NULL;
    }
}

/*Read the complaints datafile*/
void read_complaints_D(int newsockfd) {
    int fd3;
    num_records3 = 0;
    fd3 = open(COMPLAINT_DATAFILE, O_RDWR | O_CREAT, 0644);
    if (fd3 < 0) {
        perror("read failed");
    }
    while (read(fd3, (void *)&readcom, sizeof(struct comData))) {
        printf("%d.\t%d\t\t%s\t%s\n", readcom.index3, readcom.flat_num3, readcom.complaints_name, readcom.suggestions_name);
        insert_complaints_D(readcom);
        num_records3 = num_records3 + 1;
    }
    printf("num records = %d\n", num_records3);
    close(fd3);
}

/*write to complaints datafile*/
void write_complaints_D(struct comData com) {
    int fd3;
    fd3 = open(COMPLAINT_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd3 < 0) {
        perror("file open failed...");
    }
    write(fd3, (void *)&com, sizeof(struct comData));
    close(fd3);
}

//update records from complaint datafile
void update_com_file(struct comData update) {
    int fd3;
    fd3 = open(COMPLAINT_DATAFILE, O_RDWR, 0644);
    lseek (fd3, update.index3 * sizeof (struct comData), SEEK_SET);
    if (write(fd3, &update, sizeof(struct comData)) < 0) {
        perror("write failed");
        exit(1);
    }
    close(fd3);
}

//delete record from complaint datafile
void delete_com_file(struct comData delete) {
    int fd3;
    struct comData temp3;
    fd3 = open (COMPLAINT_DATAFILE, O_RDWR);
    lseek (fd3, (num_records3 - 1) * sizeof (struct comData), SEEK_SET);
    read (fd3, &temp3, sizeof(struct comData));
    temp3.index3 = delete.index3;
    lseek (fd3, temp3.index3 * sizeof(struct comData), SEEK_SET);
    write (fd3, &temp3, sizeof(struct comData));
    num_records3 --;
    ftruncate (fd3, num_records3 * sizeof(struct comData));
    printf("\n\n\tdelete successful...\n");
    close(fd3);
}

/*COMPLAINTS INSERTION*/
void insert_complaints_D(struct comData com_data) {
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
    } else {
        struct complaint* temp3 = arr3[key3];
        while(temp3->next3 != NULL) {
            temp3 = temp3->next3;
        }
        temp3->next3 = newNode3;
        newNode3->prev3 = temp3;
    }
}

/* COMPLAINTS DISPLAY*/
void display_complaints_D(int newsockfd) {
    int i;
    int index = 1;
    int display_data = 1;
    struct complaint *temp3;
    printf("\n==================================================================\n\n");
    printf("\t\tCOMPLAINT DATAFILE\n\n");
    printf("SR.\tFLAT_NO\t\tCOMPLAINT\t\tSUGGESSTION\n\n");
    for(i =0; i < size; i++) {
        temp3 = arr3[i];
        while(temp3) {
            printf("%d. \t",index);
            printf("%d\t\t%s\t\t%s\n", temp3->cd.flat_num3, temp3->cd.complaints_name, temp3->cd.suggestions_name);
            com.flat_num3 = temp3->cd.flat_num3;
            strcpy(com.complaints_name, temp3->cd.complaints_name);
            strcpy(com.suggestions_name, temp3->cd.suggestions_name);
            write(newsockfd, &display_data, sizeof(int));
            write(newsockfd, &com, sizeof(struct comData));
            temp3 = temp3->next3;
            index++;
        }
    }
    display_data = 0;
    write(newsockfd, &display_data, sizeof(int));
}

/*COMPLAINTS SEARCH*/
void search_complaints_D(int flat_num3, int newsockfd) {
    struct complaint *ptr3;
    int flag;
    int key3 = flat_num3 % size;
    ptr3 = arr3[key3];
    if (ptr3 == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while(ptr3 !=NULL) {
            if(ptr3->cd.flat_num3 == flat_num3) {
                printf("\n==================================================================\n");
                printf("\n\t\t     SEARCH DATA");
                printf("\n\n\tFlat No.\t -\t %d\n\tComplaint\t -\t %s\n\tSuggestion\t -\t %s\n", ptr3->cd.flat_num3, ptr3->cd.complaints_name, ptr3->cd.suggestions_name);
                com.flat_num3 = ptr3->cd.flat_num3;
                strcpy(com.complaints_name, ptr3->cd.complaints_name);
                strcpy(com.suggestions_name, ptr3->cd.suggestions_name);
                write(newsockfd, &com, sizeof(struct comData));
                flag = 0;
                break;
            } else {
                flag=1;
            }
            ptr3 = ptr3 -> next3;
        }
        if (flag==1) {
            printf("\n\nflat number not found\n");
        }
    }
}

/*COMPLAINTS UPDATION*/
void update_complaints_D(struct comData upcd) {
    struct complaint *ptr3;
    int i=0, flag;
    int key3 = upcd.flat_num3 % size;
    ptr3 = arr3[key3];
    if (ptr3 == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while(ptr3 !=NULL) {
            if(ptr3->cd.flat_num3 == upcd.flat_num3) {
                printf("\n==================================================================\n");
                printf("\n\n\t\tComplaints Old Data");
                printf("\n\n\tflat_number\t -\t %d\n\tcomplaints_name\t -\t %s\n\tsuggestions_name -\t %s\n", ptr3->cd.flat_num3, ptr3->cd.complaints_name, ptr3->cd.suggestions_name);

                int flat_num3;
                char complaints_name[50], suggestions_name[50];
                strcpy(ptr3->cd.complaints_name, upcd.complaints_name);
                strcpy(ptr3->cd.suggestions_name, upcd.suggestions_name);
                printf("\n    ====================================");
                printf("\n\n\t\tComplaints New Data\n");
                printf("\n\n\tFlat No.\t -\t %d\n\tComplaint\t -\t %s\n\tSuggestion\t -\t %s\n",ptr3->cd.flat_num3, ptr3->cd.complaints_name, ptr3->cd.suggestions_name);
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
void delete_complaints_D(int flat_num3) {
    int key3 = flat_num3 % size;
    struct complaint *toDelete;
    struct complaint *ptr3 = arr3[key3];
    if(ptr3 == NULL) {
        printf("\n List is Empty");
    } else if(ptr3->cd.flat_num3 == flat_num3) {
        delete_com_file(ptr3->cd);
        ptr3 = NULL;
        arr3[key3] = NULL;
        free(ptr3);
    } else {
        delete_com_file(ptr3->cd);
        while(ptr3->next3 != NULL) {
            if (ptr3->next3->cd.flat_num3 == flat_num3) {
                ptr3 = NULL;
                toDelete = ptr3->next3;
                ptr3->next3 = toDelete->next3;
                toDelete->next3->prev3 = ptr3;
                free(toDelete);
            }
            ptr3 = ptr3->next3;
        }
    }
}
