/*visitors data*/
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
struct visData readvis;
struct visData vis;
extern void insert_vis(struct visData);
struct visitor *arr2[size];
int num_records2;

/*init array of list to NULL*/
void init_vis() {
    int i;
    for(i = 0; i < size; i++) {
        arr2[i] = NULL;
    }
}

//read the visitor datafile
void read_vis(int newsockfd) {
    int fd2;
    num_records2 = 0;
    fd2 = open(VISITOR_DATAFILE, O_RDWR | O_CREAT, 0644);
    if (fd2 < 0) {
        perror("read failed");
    }
    while (read(fd2, (void *)&readvis, sizeof(struct visData))) {
        printf("%d.\t%s\t\t%d\t%d\t%d\t%d\n", readvis.index2, readvis.visitor_name, readvis.vehicle_num, readvis.visitor_contact, readvis.TimeIn, readvis.TimeOut);
        insert_vis(readvis);
        num_records2++;
    }
    printf("num records = %d\n", num_records2);
    close(fd2);
}

//write data into visitor datafile
void write_vis(struct visData vis) {
    int fd2;
    fd2 = open(VISITOR_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd2 < 0) {
        perror("file open failed...");
    }
    write(fd2, (void *)&vis, sizeof(struct visData));
    close(fd2);
}

//update visitor datafile
void update_vis_file(struct visData update) {
    int fd2;
    fd2 = open(VISITOR_DATAFILE, O_RDWR, 0644);
    lseek (fd2, update.index2 * sizeof (struct visData), SEEK_SET);
    if (write(fd2, &update, sizeof(struct visData)) < 0) {
        perror("write failed");
        exit(1);
    }
    close(fd2);
}

//delete record from datafile
void delete_vis_file(struct visData delete) {
    int fd2;
    struct visData temp2;
    fd2 = open(VISITOR_DATAFILE, O_RDWR);
    lseek (fd2, (num_records2 - 1) * sizeof (struct visData), SEEK_SET);
    read(fd2, &temp2, sizeof(struct visData));
    temp2.index2 = delete.index2;
    lseek(fd2, temp2.index2 * sizeof(struct visData), SEEK_SET);
    write(fd2, &temp2, sizeof(struct visData));
    num_records2 --;
    ftruncate(fd2, num_records2 * sizeof(struct visData));
    printf("\n\n\tdelete successful...\n");
    close(fd2);
}

//insert visitor data
void insert_vis(struct visData vis_data) {
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
    } else {
        struct visitor *temp2 = arr2[key2];
        while (temp2->next2 != NULL) {
            temp2 = temp2->next2;
        }
        temp2->next2 = newNode2;
        newNode2->prev2 = temp2;
    }
}

//display visitor data
void display_vis(int newsockfd) {
    int i;
    int index = 1;
    int display_data = 1;
    struct visitor *temp2;
    printf("\n==================================================================\n\n");
    printf("\t\tSOCIETY DATAFILE\n\n");
    printf("SR.\tVIS_NAME\tVIS_NO\t\tVIS_CONTACT\tTIMEIN\t\tTIMEOUT\n\n");
    for(i = 0; i < size; i++) {
        temp2 = arr2[i];
        while(temp2) {
            printf("%d. \t",index);
            printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", temp2->vd.visitor_name, temp2->vd.vehicle_num, temp2->vd.visitor_contact, temp2->vd.TimeIn, temp2->vd.TimeOut);
            strcpy(vis.visitor_name, temp2->vd.visitor_name);
            vis.vehicle_num = temp2->vd.vehicle_num;
            vis.visitor_contact = temp2->vd.visitor_contact;
            vis.TimeIn = temp2->vd.TimeIn;
            vis.TimeOut = temp2->vd.TimeOut;
            write(newsockfd, &display_data, sizeof(int));
            write(newsockfd, &vis, sizeof(struct visData));
            temp2 = temp2->next2;
            index++;
        }
    }
    display_data = 0;
    write(newsockfd, &display_data, sizeof(int));
}

//update visitor data
void update_vis(struct visData upvd) {
    struct visitor *ptr2;
    int i=0, flag;
    int key2 = upvd.vehicle_num % size;
    ptr2 = arr2[key2];
    if (ptr2 == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while (ptr2 != NULL) {
            if (ptr2->vd.vehicle_num == upvd.vehicle_num) {
                printf("\n==================================================================\n");
                printf("\n\n\tVisitor old Data");
                printf("\n\n\tvisitor_name\t - \t%s\n\tvehicle_num\t - \t%d\n\tvisitor_contact\t - \t%d\n\tTIMEIN\t - \t%d\n\tTIMEOUT\t - \t%d\n", ptr2->vd.visitor_name, ptr2->vd.vehicle_num, ptr2->vd.visitor_contact, ptr2->vd.TimeIn, ptr2->vd.TimeOut);

                int visitor_contact, TimeIn, TimeOut;
                char visitor_name[30];
            	strcpy(ptr2->vd.visitor_name, upvd.visitor_name);
          	    ptr2->vd.visitor_contact = upvd.visitor_contact;
                ptr2->vd.TimeIn = upvd.TimeIn;
                ptr2->vd.TimeOut = upvd.TimeOut;
                printf("\n    ====================================");
                printf("\n\n\t Visitor New Data");
                printf("\n\n\tvisitor_name\t - \t%s\n\tvisitor vehicle_num\t - \t%d\n\tvisitor_contact\t - \t%d\n\tTIMEIN\t - \t%d\n\tTIMEOUT\t - \t%d\n", ptr2->vd.visitor_name, ptr2->vd.vehicle_num, ptr2->vd.visitor_contact, ptr2->vd.TimeIn, ptr2->vd.TimeOut);
                printf("\n\n\tSociety Record Updated Successfully !!!\n");
                flag = 0;
                update_vis_file(ptr2->vd);
                break;
            } else {
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
void search_vis(int vehicle_num, int newsockfd) {
    struct visitor *ptr2;
    int flag;
    int key2 = vehicle_num % size;
    ptr2 = arr2[key2];
    if (ptr2 == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while (ptr2 != NULL) {
            if (ptr2->vd.vehicle_num == vehicle_num) {
                printf("\n==================================================================\n");
                printf("\n\t\t     SEARCH DATA");
                printf("\n\n\tvisitor_name\t - \t%s\n\tvehicle_num\t - \t%d\n\tvisitor_contact\t - \t%d\n\tVisitor TIMEIN\t - \t%d\n\tVisitor TIMEOUT\t - \t%d\n", ptr2->vd.visitor_name, ptr2->vd.vehicle_num, ptr2->vd.visitor_contact, ptr2->vd.TimeIn, ptr2->vd.TimeOut);
                strcpy(vis.visitor_name, ptr2->vd.visitor_name);
                vis.vehicle_num = ptr2->vd.vehicle_num;
          	    vis.visitor_contact = ptr2->vd.visitor_contact;
                vis.TimeIn = ptr2->vd.TimeIn;
                vis.TimeOut = ptr2->vd.TimeOut;
                write(newsockfd, &vis, sizeof(struct visData));
                flag = 0;
                break;
            } else {
                flag = 1;
            }
            ptr2 = ptr2 -> next2;
        }
        if (flag == 1) {
            printf("\n\n\tsociety flat number not found\n");
        }
    }
}

/*VISITORS DELETION*/
void delete_vis(int vehicle_num) {
    int key2 = vehicle_num % size;
    struct visitor *toDelete;
    struct visitor *ptr2 = arr2[key2];

    if(ptr2 == NULL) {
        printf("\n List is Empty");
    } else if (ptr2->vd.vehicle_num == vehicle_num) {
        delete_vis_file(ptr2->vd);
        ptr2 = NULL;
        arr2[key2] = NULL;
        free(ptr2);
    } else {
        delete_vis_file(ptr2->vd);
        while (ptr2->next2 != NULL) {
            if (ptr2->next2->vd.vehicle_num == vehicle_num) {
                ptr2 = NULL;
                toDelete = ptr2->next2;

                ptr2->next2 = toDelete->next2;
                toDelete->next2->prev2 = ptr2;
                free(toDelete);
            }
            ptr2 = ptr2->next2;
        }
    }
}
