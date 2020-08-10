//society data..
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
struct socData readsoc;
struct socData soc;
extern void insert_soc(struct socData);
struct society *arr[size];
int num_records;
extern void update_soc(struct socData upsd);


//init array of list to NULL
void init_soc() {
    int i;
    for(i = 1; i < size; i++) {
        arr[i] = NULL;
    }
}

//readind society datafile
void read_soc(int newsockfd) {
    int fd;
    num_records = 0;
    fd = open(SOCIETY_DATAFILE, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("read failed");
    }
    while (read(fd, (void *)&readsoc, sizeof(struct socData))) {
        printf("%d.\t%s\t\t%d\t\t%d\n", readsoc.index, readsoc.owner_name, readsoc.flat_num, readsoc.owner_contact);
        insert_soc(readsoc);
        num_records = num_records + 1;
    }
    printf("num records = %d\n", num_records);
    close(fd);
}

//Write to student datafile
void write_soc(struct socData soc) {
    int fd;
    fd = open(SOCIETY_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("file open failed...");
    }
    write(fd, (void *)&soc, sizeof(struct socData));
    close(fd);
}

//update to file
void update_soc_file(struct socData update) {
    int fd;
    fd = open(SOCIETY_DATAFILE, O_RDWR, 0644);
    lseek (fd, update.index * sizeof (struct socData), SEEK_SET);
    if (write(fd, &update, sizeof(struct socData)) < 0) {
        perror("write failed");
        exit(1);
    }
    close(fd);
}

//delete from file
void delete_soc_file(struct socData delete) {
    int fd;
    struct socData temp;
    fd = open(SOCIETY_DATAFILE, O_RDWR);
    lseek (fd, (num_records - 1) * sizeof (struct socData), SEEK_SET);
    read(fd, &temp, sizeof(struct socData));
    temp.index = delete.index;
    lseek(fd, temp.index * sizeof(struct socData), SEEK_SET);
    write(fd, &temp, sizeof(struct socData));
    num_records --;
    ftruncate(fd, num_records * sizeof(struct socData));
    printf("\n\n\tdelete successful...\n");
    close(fd);
}

/*society insertion*/
void insert_soc(struct socData soc_data) {
    struct society *newNode = (struct society*)malloc(sizeof(struct society));
    newNode->sd.index = soc_data.index;
    strcpy(newNode->sd.owner_name, soc_data.owner_name);
    newNode->sd.flat_num = soc_data.flat_num;
    newNode->sd.owner_contact = soc_data.owner_contact;
    newNode->next = NULL;
    newNode->prev = NULL;
    //calculate hash key
    int key = soc_data.flat_num % size;
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
}

/*display data*/
void display_soc(int newsockfd) {
    int i;
    int index = 1;
    int display_data = 1;
    struct society *temp;
    printf("\n==================================================================\n\n");
    printf("\t\tSOCIETY DATAFILE\n\n");
    printf("SR.\tOW_NAME\t\tFLAT_NO\t\tOW_CONTACT\n\n");
    for(i = 0; i < size; i++) {
        temp = arr[i];
        while(temp) {
            printf("%d. \t",index);
            printf("%s\t\t %d\t\t%d\n", temp->sd.owner_name, temp->sd.flat_num, temp->sd.owner_contact);
            strcpy(soc.owner_name, temp->sd.owner_name);
            soc.flat_num = temp->sd.flat_num;
            soc.owner_contact = temp->sd.owner_contact;
            write(newsockfd, &display_data, sizeof(int));
            write(newsockfd, &soc, sizeof(struct socData));
            temp = temp->next;
            index++;
        }
    }
    display_data = 0;
    write(newsockfd, &display_data, sizeof(int));
}

/*serch data*/
void search_soc(int flat_num, int newsockfd) {
    struct society *ptr;
    int flag;
    int key = flat_num % size;
    ptr = arr[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while (ptr != NULL) {
            if (ptr->sd.flat_num == flat_num) {
                printf("\n==================================================================\n");
                printf("\n\t\t     SEARCH DATA");
                printf("\n\n\tOwner Name\t -\t %s\n\tFlat No.\t -\t %d\n\tOwner Contact\t -\t %d\n", ptr->sd.owner_name, ptr->sd.flat_num, ptr->sd.owner_contact);
                strcpy(soc.owner_name, ptr->sd.owner_name);
                soc.flat_num = ptr->sd.flat_num;
                soc.owner_contact = ptr->sd.owner_contact;
                write(newsockfd, &soc, sizeof(struct socData));
                flag = 0;
                break;
            } else {
                flag=1;
            }
            ptr = ptr -> next;
        }
        if (flag==1) {
            printf("\n\n\tsociety flat number not found\n");
        }
    }
}


/*updation*/
void update_soc(struct socData upsd) {
    struct society *ptr;
    int i=0, flag;
    int key = upsd.flat_num % size;
    ptr = arr[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
        while (ptr != NULL) {
            if (ptr->sd.flat_num == upsd.flat_num) {
                printf("\n==================================================================\n");
                printf("\n\n\t\tSociety old Data");
                printf("\n\n\tOwner Name\t -\t %s\n\tFlat No.\t -\t %d\n\tOwner Contact\t -\t %d\n", ptr->sd.owner_name, ptr->sd.flat_num, ptr->sd.owner_contact);

        		int owner_contact;
                char owner_name[30];
        		strcpy(ptr->sd.owner_name, upsd.owner_name);
    		    ptr->sd.owner_contact = upsd.owner_contact;
                printf("\n    ====================================");
                printf("\n\n\t\tSociety New Data");
    		    printf("\n\n\tOwner Name\t - \t%s\n\tOwner Contact\t - \t%d", ptr->sd.owner_name, ptr->sd.owner_contact);
    		    printf("\n\n\tRecord Updated Successfully !!!\n");
                flag = 0;
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

//delete operation
void delete_soc(int flat_num) {
    int key = flat_num % size;
    struct society *toDelete;
    struct society *ptr = arr[key];

    if(ptr == NULL) {
        printf("\n List is Empty");
    } else if(ptr->sd.flat_num == flat_num) {
        delete_soc_file(ptr->sd);
        ptr = NULL;
        arr[key] = NULL;
        free(ptr);
    } else {
        delete_soc_file(ptr->sd);
        while(ptr->next != NULL) {
            if (ptr->next->sd.flat_num == flat_num) {
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
