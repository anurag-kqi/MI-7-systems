/*School Mnagement Systems*/
#include "header.h"

struct teacher *chaint[size];
struct teacher_disk readTeach;
struct teacher_disk td;

//file write functions
void read_teach();
void write_teach(struct teacher_disk teach);
void delete_teach_file(struct teacher_disk teach_data);
void update_teach_file(struct teacher_disk tea_data);
void insert_teach(struct teacher_disk readTeach);
void display_teach(int sockfd);
void search_teach(int id, int newsockfd);
void update_teach(struct teacher_disk uptd);
void delete_teach(int id);

int num_record;
int sockfd;
//init array of list to NULL
void init_teacher()
{
    int i;
    for(i = 0; i < size; i++) {
	chaint[i] = NULL;
    }
}

//Read the teachent data from teacher text file
void
read_teach()
{
    num_record = 0;
    int fd;
    fd = open(TEACHER_DATAFILE, O_RDWR | O_CREAT, 0644);
    if(fd < 0) {
        perror("read failed");
    }
    while (read(fd, (void *)&readTeach, sizeof(struct teacher_disk))) {
        printf("%d\t%d\t%s\t%s\t%d\n", readTeach.index, readTeach.id, readTeach.name, readTeach.department,readTeach.contact);
        insert_teach(readTeach);
        num_record = ++num_record;
    }
    printf("num_records = %d\n", num_record);
    close(fd);
}

//Write the teachent data into teachENT text file
void
write_teach(struct teacher_disk teach)
{
    int fd;

    fd = open(TEACHER_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("file open failed...");
    }
    write(fd, (void *)&teach, sizeof(struct teacher_disk));
    close(fd);
}


//insert values into TEACHER hash table
void insert_teach(struct teacher_disk readTeach)
{
    //create a newnode with value
    struct teacher *newNode = malloc(sizeof(struct teacher));
    newNode->tch.index = readTeach.index;
    newNode->tch.id = readTeach.id;
    strcpy(newNode->tch.name, readTeach.name);
    strcpy(newNode->tch.department, readTeach.department);
    newNode->tch.contact = readTeach.contact;
    newNode->next = NULL;
    newNode->prev = NULL;

    //calculate hash key
    int key = readTeach.id % size;

    if (chaint[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        chaint[key] = newNode;
    } else {
        struct teacher *temp = chaint[key];

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
}

//DISPLAY data of Teacher hash table
void
display_teach(int sockfd)
{
    int i;
    int index = 0;
    int display_data = 1;
    struct teacher *temp;
    printf("\n_______________________________________________________________________________\n\n");
    printf("INDEX.\tSR.\tTEACHER_NAME\tDEPARTMENT\tCONTACT\n\n");
    for(i = 0; i < size; i++) {
        temp = chaint[i];
        while(temp) {
            printf("%d. ", index);
            printf("\t%d\t%s\t\t%s\t%d\n", temp->tch.id, temp->tch.name, temp->tch.department, temp->tch.contact);
            td.id = temp->tch.id;
            strcpy(td.name, temp->tch.name);
            strcpy(td.department, temp->tch.department);
            td.contact = temp->tch.contact;
            write(sockfd, &display_data, sizeof(int));
            write(sockfd, &td, sizeof(struct teacher_disk));
            temp = temp->next;
            index++;
        }
    }
    display_data = 0;
    write(sockfd, &display_data, sizeof(int));
}

//DELETE values from Teacher text file
void
delete_teach_file(struct teacher_disk teach)
{
    int fd;
    struct teacher_disk temp;

    fd = open(TEACHER_DATAFILE, O_RDWR);

    lseek (fd, (num_record - 1) * sizeof (struct teacher_disk), SEEK_SET);
    read(fd, &temp, sizeof(struct teacher_disk));
    temp.index = teach.index;
    lseek(fd, temp.index * sizeof(struct teacher_disk), SEEK_SET);
    write(fd, &temp, sizeof(struct teacher_disk));
    num_record --;
    ftruncate(fd, num_record * sizeof(struct teacher_disk));
    printf("\n\n\tdelete successful\n");
    close(fd);

}

//DELETE values from TEACHER hash table
void
delete_teach(int id)
{
    int key = id % size;
    struct teacher *ptr = chaint[key], *toDelete;

    if (ptr == NULL) {
        printf("\n\n\tList is Empty !!!\n");
    }
    else if (ptr->tch.id == id) {
      delete_teach_file(ptr->tch);
        chaint[key] = chaint[key]->next;
        //chain[key]->prev = NULL;
        ptr->next = NULL;
        free(ptr);
    } else {
      delete_teach_file(ptr->next->tch);
      	  while (ptr->next != NULL) {
              if (ptr->next->tch.id == id) {
                  toDelete = ptr->next;
                  if (toDelete->next == NULL) {
                      ptr->next = NULL;
                      free(toDelete);
                      return;
                      } else {
                            ptr->next = toDelete->next;
                            toDelete->next->prev = toDelete->prev;
                            free(toDelete);
                        }
              }
              ptr = ptr->next;
          }
      }
}

//SEARCH teacher data from TEACHER hash table
void search_teach(int id, int newsockfd)
{
    struct teacher *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = chaint[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {


        while (ptr != NULL) {
            if (ptr->tch.id == id) {
                printf("\n\n\tTeacher id found at location %d ", i+1);
                printf("\n\n\tTeacher Id - %d\n\tTeacher Nmae - %s\n\tTeacher Department - %s\n\tTeacher Contact - %d",ptr->tch.id, ptr->tch.name, ptr->tch.department, ptr->tch.contact);
                td.id = ptr->tch.id;
                strcpy(td.name, ptr->tch.name);
                strcpy(td.department, ptr->tch.department);            td.contact = ptr->tch.contact;
                write(newsockfd, &td, sizeof(struct student_disk));
                flag = 0;
                break;
            } else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if (flag==1) {
            printf("\n\n\tTeacher id not found\n");
        }
    }
}

//UPDATE teacher data from TEACHER hash table
void update_teach(struct teacher_disk uptd)
{
    struct teacher *ptr;
    int i=0, flag;

    int key = uptd.id % size;

    ptr = chaint[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {

        while (ptr != NULL) {
            if (ptr->tch.id == uptd.id) {
                printf("\n\n\tTeacher old Data !!!\n");
                printf("\n\n\tTeacher Id - %d\n\tTeacher Nmae - %s\n\tTeacher Department - %s\n\tTeacher Contact - %d",
                       ptr->tch.id, ptr->tch.name, ptr->tch.department, ptr->tch.contact);

		        printf("\n\n\tTeacher New Data !!!\n");

		        int id, contact;
    		    char name[30], department[30];

                ptr->tch.id = uptd.id;
    		    strcpy(ptr->tch.name, uptd.name);
    		    strcpy(ptr->tch.department, uptd.department);
    		    ptr->tch.contact = uptd.contact;

		        printf("\n\n\tTeacher Id - %d\n\tTeacher Nmae - %s\n\tTeacher Department - %s\n\tTeacher Contact - %d",ptr->tch.id, ptr->tch.name, ptr->tch.department, ptr->tch.contact);
		        printf("\n\n\tTeacher Record Updated Successfully !!!\n");
                flag = 0;
                update_teach_file(ptr->tch);
                break;

            } else {
                flag = 1;
            }
            i++;
            ptr = ptr -> next;
        }

        if (flag == 1) {
            printf("\n\n\tTeacher id not found\n");
        }
    }
}


//update from TEACHER text file
void
update_teach_file(struct teacher_disk tea_data)
{
    int fd;
    fd = open(TEACHER_DATAFILE, O_RDWR , 0644);
    lseek (fd, tea_data.index * sizeof (struct teacher_disk), SEEK_SET);
    if (write(fd, &tea_data, sizeof(struct teacher_disk)) < 0) {
        perror("write failed");
        exit(1);
    }
    close(fd);
}
