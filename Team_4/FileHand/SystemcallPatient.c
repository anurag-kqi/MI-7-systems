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
//void write_pat();


void init()
{
    int i;
    for(i = 0; i < size; i++) {
        index_pat[i] = NULL;

    }
}
void read_pat() {
    int fd, fd1;
    int id, age, contact;
    char name[30],address[50];
    fd = open("E:\Hash.txt", O_APPEND| O_RDWR);
  struct patient *p = malloc(sizeof(struct patient));


  int i = 0;
  int count1;
  do {

    count1 = read(fd, (void *)&index_pat[i], sizeof(struct patient));
    if(count1 < 0) {
       perror("read failed");
    }
    printf("%d %s %d %s %d\n", &id, name , &age, address, &contact);
    i++;

  } while ( count1 !=0 ) ;
  close(fd);

  fd1 = open("E:\Hash.txt", O_APPEND|O_RDWR|O_CREAT, 0666);
  int count;
  count = write(fd1, (void *)&p, sizeof(struct patient));
  if(count < 0) {
    perror ("write failed");
    _exit(1);
  } else {
    fprintf(stderr,"wrote %d bytes\n", count);
  }
  close(fd1);
}

void insert_pat(int id, char name[], int age, char address[], int contact)
{
    int n,fd;
	char buf[500];
    //FILE *fp;
    //fp = fopen("E:\Hash.txt", "a+");/*  open for writing */
    n= read(0, buf, 500);
    fd=open("E:\Hash.txt", O_WRONLY);


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
/*
  //fprintf(fp, "\n%d %s %d %s %d\n", id , name, age, address, contact);
    fprintf(fp, "ID    = %d\n", id);
	fprintf(fp, "Name    = %s\n", name);
	fprintf(fp, "Age    = %d\n", age);
	fprintf(fp, "Address    = %s\n", address);
	fprintf(fp, "Contact    = %d\n", contact);
    printf("\n\nNode inserted Successfully...!\n");

	fclose(fp);
    */
    write(fd, buf, n);
    write(1, buf, n);

    close(fd);
}



void display_pat()
{
    int i,id , age, contact;
    char name, address;


  // FILE *fp;

// fp = fopen("E:\Hash.txt", "r");

    for(i = 0; i < size; i++) {
       struct patient *temp = index_pat[i];
       //struct patient *temp = fopen("E:\Hash.txt", "r");

        printf("\nData_of _Patient[%d]-->",i);
       while(temp) {
            printf("%d %s %d %s %d -->",temp->id, temp->name, temp->age, temp->address, temp->contact);


      temp = temp->next;
    }


       // while (( fscanf(fp, "%d %[^\n]%*c %d %[^\n]%*c %d", &id, name, age, address, &contact)) != EOF) {
      //insert_pat(id, name, age, address, contact);
    //}
        printf("NULL\n");

    }
    //fscanf(fp, "%d %s %d %s %d", id, name, age, address, contact);
   // fclose(fp);
}



int
main()
{

    int ch, a, b, id, contact, age;
    char name[30], address[50];


 int n_char=0;
 char buf[80];
 int fd;
 fd = open("E:\Hash.txt",  O_APPEND|O_RDWR| O_CREAT, 0644);

        if (fd==-1)
        {
                exit(1);
        }

        close(fd);




 fd = open("E:\Hash.txt",  O_APPEND|O_RDONLY, 0644);


     if (fd==-1)
        {
                exit(1);
        }


        //Use the read system call to obtain 10 characters from inFile
        while( (n_char=read(fd, buf, 80))!=0)
        {
                //Display the characters read
                n_char=write(1 ,buf,n_char);

        }


        //printf(fd, "\n%d %s %d %s %d\n", id , name, age, address, contact);
        close (fd);

    init();
    read_pat();

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
                                    //printf("\nEnter ID, Name, Age, Address, Contact respectively : ");
                                    //scanf("%d %s %d %s %d", &id, &name, &age, &address, &contact);


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

                                    //write_pat(id, name, age, address, contact);
                                    break;

                            case 2: printf("\n---- DISPLAY PATIENT DATA ----");
                                    display_pat();
                                    break;

                            case 3: printf("\n---- DELETE PATIENT DATA ----");
                                    printf("Enter Patient ID for Delete : ");
                                    scanf("%d",&id);
                                    //delete_pat(id);
                                    break;

                            case 4: printf("\n---- UPDATE PATIENT DATA ----");
                                    printf("Enter Pateint id for Update : ");
                                    scanf("%d",&id);
                                    //update_pat(id);
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
