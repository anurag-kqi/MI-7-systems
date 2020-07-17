/*School Mnagement Systems*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define size 9
//on disk structure
struct student_disk {
    int index;
    int id;
    char name[30];
    char class[10];
    char address[50];
    int contact;
};

//in memory structure
struct student {
    struct student_disk std;
    struct student *next;
    struct student *prev;
};

struct student *chain[size];
struct student_disk readStud;


int num_records;
//init array of list to NULL
void init_stud()
{
    int i;
    for(i = 0; i < size; i++) {
        chain[i] = NULL;
    }
}

//Read the student data
void read_stud() {
  num_records = 0;
  int fd;
  fd = open("Student.txt",O_RDWR | O_CREAT, 0644);
  if(fd < 0) {
     perror("read failed");
  }
  while (read(fd, (void *)&readStud, sizeof(struct student_disk))) {
    printf("%d %d %s %s %s %d\n", readStud.index, readStud.id, readStud.name, readStud.class, readStud.address, readStud.contact);
    insert_stud(readStud);
    num_records = ++num_records;
  }
  printf("num_records = %d\n", num_records);
  //readStud.index = num_records;
  close(fd);
}

//Write the student data
void write_stud(struct student_disk stud)
{
  int fd;

  fd = open("Student.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
  if (fd < 0) {
    perror("file open failed...");
  }
  write(fd, (void *)&stud, sizeof(struct student_disk));
  //num_records = num_records + 1;
  close(fd);
}

//Delete the Student
void delete_stud_file(stud_data)
{

    struct student_disk     temp;

    // stud_data.index
    // read the last record from the file
    // lseek (num_records - 1) * student_data
    // read the stud_data from that location into a new local variable
    read(fd, &temp, sizeof(struct stue...))
    temp.index = stud_data.index
    //lseek to temp.index * sizeof student_disk
    write(fd, &temp, ....) 

  printf("delete num_records = %d\n", num_records);
  struct student_disk readStud;
  int fd;
  fd = open("Student.txt", O_RDWR | O_TRUNC);
  lseek (fd, num_records * sizeof (readStud), 0);

  ftruncate(fd,  sizeof (struct student_disk));
  read_stud();

  // char buff;
  // read(fd, &buff, sizeof(buff));
  // if (buff == 1) {
  //   printf("delete if\n");
  //   int replace = 2;
  //   write(fd, &replace, 1);
  // }
  // while (read(fd, (void *)&readStud, sizeof(struct student_disk))) {
  //   printf("delete while\n");
  //   printf("%d\n%d\n%s\n%s\n%s\n%d\n\n", readStud.index, readStud.id, readStud.name, readStud.class, readStud.address, readStud.contact);
  //   insert_stud(readStud);
  //   num_records++;
  // }
  close(fd);
}

void update_stud_file(struct student_disk stu_data)
{
//   printf("update num_records = %d\n", num_records);
  int fd;
  fd = open("Student.txt", O_RDWR);
  lseek (fd, stu_data.index * sizeof (struct student_disk), 0);
  if (write(fd, &stu_data, sizeof(struct student_disk)) < 0) {
      perror("write failed");
      exit(1);
  }
  
  // while (read(fd, (void *)&readStud, sizeof(struct student_disk))) {
  //   printf("delete while\n");
  //   printf("%d\n%d\n%s\n%s\n%s\n%d\n\n", readStud.index, readStud.id, readStud.name, readStud.class, readStud.address, readStud.contact);
  //   insert_stud(readStud);
  //   num_records++;
  // }
  close(fd);
}


//insert values into STUDENT hash table
void insert_stud(struct student_disk readStud)
{
    //create a newnode with value
    struct student *newNode = malloc(sizeof(struct student));
    newNode->std.index = readStud.index;
    newNode->std.id = readStud.id;
    strcpy(newNode->std.name, readStud.name);
    strcpy(newNode->std.class, readStud.class);
    strcpy(newNode->std.address, readStud.address);
    newNode->std.contact = readStud.contact;
    newNode->next = NULL;
    newNode->prev = NULL;
    //calculate hash key
    int key = readStud.id % size;

    if (chain[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        chain[key] = newNode;
    } else {
        struct student *temp = chain[key];

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
}

//DELETE values from STUDENT hash table
void delete_stud(int id)
{
    int key = id % size;
    struct student *ptr = chain[key], *toDelete;

    if (ptr == NULL) {
        printf("\n\n\tList is Empty !!!\n");
    }
    else if (ptr->std.id == id) {
        chain[key] = chain[key]->next;
        chain[key]->prev = NULL;
        ptr->next = NULL;
        free(ptr);
	printf("\n\n\tFirst node deleted\n");
    } else {
	while (ptr->next != NULL) {
            if (ptr->next->std.id == id) {
                toDelete = ptr->next;
                if (toDelete->next == NULL) {
                    ptr->next = NULL;
                    free(toDelete);
		    printf("\n\n\tLast Node is deleted\n");
                    return;
                } else {
                    ptr->next = toDelete->next;
                    toDelete->next->prev = toDelete->prev;
                    printf("\n\n\tnode is deleted\n");
                    free(toDelete);
                }
            }
            ptr = ptr->next;
        }
    }
}

//DISPLAY data of STUDENT hash table
void display_stud()
{
    int i;
    for (i = 0; i < size; i++) {
        struct student *temp = chain[i];
        printf("\tchain[%d]-->", i);
        while (temp) {
            printf("%d %s %s %s %d -->", temp->std.id, temp->std.name, temp->std.class, temp->std.address, temp->std.contact);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

//SEARCH Student data from STUDENT hash table
void search_stud(int id)
{
    struct student *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = chain[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {


        while (ptr != NULL) {
            if (ptr->std.id == id) {
                printf("\n\n\tStudent id found at location %d ", i+1);
                printf("\n\n\tStudent Prev - %p\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d\n\tStudent next - %p", ptr->prev, ptr->std.id, ptr->std.name, ptr->std.class, ptr->std.address, ptr->std.contact, ptr->next);
                flag = 0;
                break;
            } else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if (flag==1) {
            printf("\n\n\tStudent id not found\n");
        }
    }
}


//UPDATE student data from STUDENT hash table
void update_stud(int id)
{
    struct student *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = chain[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {

        while (ptr != NULL) {
            if (ptr->std.id == id) {
                printf("\n\n\tStudent old Data !!!\n");
                printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d",
                       ptr->std.id, ptr->std.name, ptr->std.class, ptr->std.address, ptr->std.contact);

		        printf("\n\n\tStudent New Data !!!\n");

                int id, contact;
                    char name[30], class[10], address[50];

                printf("\n\tEnter Same ID : ");
                scanf("\t %d", &id);
                printf("\n\tEnter New Name : ");
                scanf("\t %[^\n]%*c", name);
                printf("\n\tEnter New Class : ");
                scanf("\t %s", class);
                printf("\n\tEnter New Address : ");
                scanf("\t %s", address);
                printf("\n\tEnter New Contact : ");
                scanf("\t %d", &contact);

    		    ptr->std.id = id;
    		    strcpy(ptr->std.name, name);
    		    strcpy(ptr->std.class, class);
    		    strcpy(ptr->std.address, address);
    		    ptr->std.contact = contact;

		        printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d",
                           ptr->std.id, ptr->std.name, ptr->std.class, ptr->std.address, ptr->std.contact);
		        printf("\n\n\tStudent Record Updated Successfully !!!\n");
                    flag = 0;

                update_stud_file(ptr->std);
                break;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr -> next;
        }

        if (flag == 1) {
            printf("\n\n\tStudent id not found\n");
        }
    }


}
