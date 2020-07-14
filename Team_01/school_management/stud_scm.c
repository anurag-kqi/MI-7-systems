
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define size 9
struct student
{
    int id;
    char name[30];
    char class[10];
    char address[50];
    int contact;
    struct student *next;
    struct student *prev;
};

struct student *chain[size];

//init array of list to NULL
void init_stud()
{
    int i;
    for(i = 0; i < size; i++) {
        chain[i] = NULL;
    }
}

//Read the student data
void read_stud()
{
    int fd;

    //Reading file data using UNIX file descriptor
    fd = open("Student.txt", O_RDONLY | O_CREAT);
    if (fd < 0)
    {
       perror("Open failed");
    }
    struct stat st;
    stat("Student.txt", &st);
    int siz = st.st_size;

    char buff[siz];
    read(fd, buff, sizeof(buff));
    buff[siz-1] = '\0';
    printf("%s", buff);
    close(fd);
}

//Write the student data
void write_stud(int id, char name[], char class[], char address[], int contact)
{
    int fd;
    fd = open("Student.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0)
    {
       perror("file open failed...");
    }

    dprintf(fd, "%d", id);
    //write(fd, &id, sizeof(id));
    write(fd,"\n", strlen("\n"));
    write(fd,name, strlen(name));
    write(fd,"\n", strlen("\n"));
    write(fd,class, strlen(class));
    write(fd,"\n", strlen("\n"));
    write(fd,address, strlen(address));
    write(fd,"\n", strlen("\n"));
    dprintf(fd, "%d", contact);
    //write(fd, &contact, sizeof(contact));
    write(fd,"\n", strlen("\n"));

    close(fd);
}

=======
>>>>>>> 42c57357c02b1947489ddc920029e6514414924d
//insert values into STUDENT hash table
void insert_stud(struct student stud_data)
{
    //create a newnode with value
    struct student *newNode = malloc(sizeof(struct student));
    newNode->id = stud_data.id;
    strcpy(newNode->name, stud_data.name);
    strcpy(newNode->class, stud_data.class);
    strcpy(newNode->address, stud_data.address);
    newNode->contact = stud_data.contact;
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
    else if (ptr->id == id) {
        chain[key] = chain[key]->next;
        chain[key]->prev = NULL;
        ptr->next = NULL;
        free(ptr);
	printf("\n\n\tFirst node deleted\n");
    } else {
	while (ptr->next != NULL) {
            if (ptr->next->id == id) {
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
            printf("%d %s %s %s %d -->", temp->id, temp->name, temp->class, temp->address, temp->contact);
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
            if (ptr->id == id) {
                printf("\n\n\tStudent id found at location %d ", i+1);
                printf("\n\n\tStudent Prev - %p\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d\n\tStudent next - %p", ptr->prev, ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact, ptr->next);
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
            if (ptr->id == id) {
                printf("\n\n\tStudent old Data !!!\n");
                printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d",
                       ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact);

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

		    ptr->id = id;
    		    strcpy(ptr->name, name);
    		    strcpy(ptr->class, class);
    		    strcpy(ptr->address, address);
    		    ptr->contact = contact;

		    printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d",
                           ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact);
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
