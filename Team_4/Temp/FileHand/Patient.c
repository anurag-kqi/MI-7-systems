#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define size 10
struct patient
{
    int id;
    char name[30];
    int age;
    char address[50];
    int contact;
    struct patient *next;
    struct patient *prev;

};
struct patient *index_pat[size];
void insert_pat(int id, char name[], int age, char address[], int contact);
void display_pat();
void read_pat();
void write_pat();


void init()
{
    struct patient *newNode = malloc(sizeof(struct patient));
    struct patient P1;
    int id, contact, age, data, count;
    char name[30], address[50], buf[100];
    int fd = open("Hash.txt", O_RDONLY );
    if(fd < 0){
        perror("open failed");
        exit(-1);
    }
    while(read(fd ,(void*)&P1, sizeof(struct patient))){
    printf("%d %s %d %s %d", P1.id, P1.name, P1.age, P1.address, P1.contact);
    }
    close(fd);

    int i;
    for(i = 0; i < size; i++) {
        index_pat[i] = NULL;

    }
}



void insert_pat(int id, char name[], int age, char address[], int contact)
{
    struct patient *newNode = malloc(sizeof(struct patient));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->age = age;
    strcpy(newNode->address, address);
    newNode->contact = contact;
    newNode->next = NULL;
    newNode->prev = NULL;


    int key = id % size;

    if(index_pat[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        index_pat[key] = newNode;
    }
    else {
        struct patient *temp = index_pat[key];

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
    int fd = open("Hash.txt", O_RDWR | O_CREAT | O_APPEND);
    if (fd < 0) {
            perror("file open failed");
            exit(1);
    }
    int count = write(fd, newNode ,sizeof(struct patient));
    if (count < 0) {
            perror("write failed");
            exit(1);
    }
    printf("\n\nNode inserted Successfully...!\n");
    close(fd);

}



void display_pat()
{
    int i,id , age, contact;
    char name, address;
    for(i = 0; i < size; i++) {
	struct patient *temp = index_pat[i];
        printf("\nData_of _Patient[%d]-->",i);
	while(temp) {
        	printf("%d %s %d %s %d -->",temp->id, temp->name, temp->age, temp->address, temp->contact);
		temp = temp->next;
	}
        printf("NULL\n");
    }
}



int
main()
{
	int ch, a, b, id, contact, age;
	char name[30], address[50];
	init();
        do
        {
        printf("\n\n---- HOSPITAL MANAGEMENT SYSTEM MENU ----");
        printf("\n1.PATIENT DATA\n2.DOCTOR DATA\n3.EXIT");
        printf("\nEnter your choice(1-3) : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                    do{
                        printf("\n----PATIENT DEPARTMENT----");
                        printf("\n\n1.INSERT DATA\n2.DISPLAY DATA\n3.DELETE DATA\n4.UPDATE DATA\n5.EXIT\n\n");
                        printf("\n\nEnter your choice to insert(1-5):");
                        scanf("%d", &a);
                        switch(a)

                        {
                            case 1: printf("\n---- INSERT IN TO PATIENT----\n");
                                    printf("\nEnter Patient ID:");
                                    scanf("%d",&id);
                                    printf("\nEnter Patient Name:");
                                    scanf("%s",name);
                                    printf("\nEnter Patient Age:");
                                    scanf("%d",&age);
                                    printf("\nEnter Patient Address:");
                                    scanf("%s",address);
                                    printf("\nEnter Patient Contact:");
                                    scanf("%d",&contact);
                                    insert_pat(id, name, age, address, contact);
                                    break;

                            case 2: printf("\n---- DISPLAY PATIENT DATA ----");
                                    display_pat();
                                    break;

                            case 3: printf("\n---- DELETE PATIENT DATA ----");
                                    printf("Enter Patient ID for Delete : ");
                                    scanf("%d",&id);
                                    delete_pat(id);
                                    break;

                            case 4: printf("\n---- UPDATE PATIENT DATA ----");
                                    printf("Enter Pateint id for Update : ");
                                    scanf("%d",&id);
                                    update_pat(id);
                                    break;

                                    // case 5: exit(0);


                            default: printf("Wrong Choice!!");
                                     break;
                        }
                    }while(a != -1 && a !=5);
                           // default: printf("Wrong Choice!!");
                    break;


       // case 3: exit(0);

	    default: printf("Wrong Choice!!");
        }
    }while(ch!= -1 && ch!= 3);

    return 0;
}
