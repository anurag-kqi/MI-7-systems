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
    int id;
    int index;
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
//struct studDataa readStud;

int num_record = 0;
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
    struct student_disk std; // allocating memory on the stack or you might do malloc
    
    int i = 0;
    int fd;
    struct student *student;
    fd = open("Student.txt",O_RDWR | O_CREAT, 0644);
    if(fd < 0) {
        perror("read failed");
    }
    while (read(fd, &std, sizeof(struct student_disk))) {
        student = (struct student *)malloc(sizeof (struct student));
        student->std = std;
        student->next = NULL;
        student->prev = NULL;
        printf("%d %s %s %s %d\n", student->std.id, student->std.name, student->std.class, student->std.address, student->std.contact);
        insert_stud(student->std);
	num_record++;
    }
    //p = (struct student_disk *)malloc(num_record,sizeof(struct student_disk));
    
    close(fd);
}

//Write the student data
void write_stud(struct student stud)
{
   
   struct student *student;
   student->std.index = num_record;
   num_record++;
   int fd;
   fd = open("Student.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
   if (fd < 0) {
       perror("file open failed...");
   }
   write(fd, (void *)&student->std, sizeof(struct student_disk));
   
   close(fd);
}

//insert values into STUDENT hash table
void insert_stud(struct student_disk stud_data)
{
    //create a newnode with value
    struct student *newNode = malloc(sizeof(struct student));
    newNode->std.id = stud_data.id;
    strcpy(newNode->std.name, stud_data.name);
    strcpy(newNode->std.class, stud_data.class);
    strcpy(newNode->std.address, stud_data.address);
    newNode->std.contact = stud_data.contact;
    newNode->next = NULL;
    newNode->prev = NULL;
    //calculate hash key
    int key = stud_data.id % size;

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
