#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define size 10



extern void insert_pat(int id, char name[], int age,char bloodgrp[], char address[], int contact, char symtoms[]);
extern void display_pat();
extern void delete_pat(int id);
extern void update_pat(int id);

 
extern void insert_doc(int id, char name[], char address[], int contact);
extern void display_doc();
extern void delete_doc(int id);
extern void update_doc(int id);


extern void init_pat();
extern void init_doc();



int main()
{
    int ch, a, b, id, contact, age;
    char name[20], address[50], bloodgrp[10], symptoms[40];
    int fd;
    int n_char=0;
    char buffer[80];
    fd = open("Hash.txt",  O_APPEND|O_RDWR| O_CREAT, 0644);
     if (fd==-1){
                exit(1);
        }
	//Use the read system call to obtain 80 characters from File
        while( (n_char=read(fd, buffer, 80))!=0){
                //Display the characters read
                n_char=write(1,buffer,n_char);

        }
  close (fd);
  init_pat();
  init_doc();

        do
        {
        printf("\n\n---- HOSPITAL MANAGEMENT SYSTEM MENU ----\n\n");
        printf("\n1.PATIENT DATA\n2.DOCTOR DATA\n3.EXIT");
        printf("\n\nEnter your choice(1-3) : ");
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
                                    printf("\nEnter Patient ID:");
                                    scanf("%d",&id);
                                    printf("\nEnter Patient Name:");
                                    scanf("%s",name);
                                    printf("\nEnter Patient Age:");
                                    scanf("%d",&age);
                                    printf("\nEnter Patient Blood Group:");
                                    scanf("%s",bloodgrp);
                                    printf("\nEnter Patient Address:");
                                    scanf("%s",address);
                                    printf("\nEnter Patient Contact:");
                                    scanf("%d",&contact);
                                    printf("\nEnter Disease Symptoms:");
                                    scanf("%s",symptoms);
                                    //scanf("%d %s %d %s %d", &id, &name, &age, &address, &contact);
                                    insert_pat(id, name, age, bloodgrp, address, contact, symptoms);
                                    break;

                            case 2: printf("\n---- DISPLAY PATIENT DATA ----\n");
                                    printf("\t\tID\tName\tAge\tBlood Group\tAddress\tContact\tSymptoms");
                                    display_pat();
                                    break;

                            case 3: printf("\n---- DELETE PATIENT DATA ----\n");
                                    printf("\nEnter Patient ID for Delete : ");
                                    scanf("%d",&id);
                                    delete_pat(id);
                                    break;

                            case 4: printf("\n---- UPDATE PATIENT DATA ----\n");
                                    printf("\nEnter Patient id for Update : ");
                                    scanf("%d",&id);
                                    update_pat(id);
                                    break;

                           // case 5: exit(0);


                            //default: printf("Wrong Choice!!");
                                     break;
                        }
                    }while(a != -1 && a !=5);
                           // default: printf("Wrong Choice!!");
                    break;
          case 2:
                    do{
                        printf("\n----DOCTOR DEPARTMENT----");
                        printf("\n\n1.INSERT DATA\n2.DISPLAY DATA\n3.DELETE DATA\n4.UPDATE DATA\n5.EXIT\n\n");
                        printf("\n\nEnter your choice to insert(1-5):");
                        scanf("%d", &b);
                        switch(b)

                        {
                            case 1: printf("\n---- INSERT IN TO DOCTOR----\n");
                                   // printf("\nEnter ID, Name, Clinic Address, Contact respectively : ");
                                    printf("\nEnter Doctor ID:");
                                    scanf("%d",&id);
                                    printf("\nEnter Doctor Name:");
                                    scanf("%s",name);
                                    printf("\nEnter Doctor Address:");
                                    scanf("%s",address);
                                    printf("\nEnter Doctor Contact:");
                                    scanf("%d",&contact);
                                    //scanf("%d %s %s %d", &id, name, address, &contact);
                                    insert_doc(id, name, address, contact);
                                    break;

                            case 2: printf("\n---- DISPLAY DOCTOR DATA ----\n\n");
                                    printf("\t\tID\tName\tAddress\tContact");
                                    display_doc();
                                    break;

                            case 3: printf("\n---- DELETE DOCTOR DATA ----\n");
                                    printf("\nEnter Doctor ID for Delete : ");
                                    scanf("%d",&id);
                                    delete_doc(id);
                                    break;

                            case 4: printf("\n---- UPDATE DOCTOR DATA ----\n");
                                    printf("\nEnter Doctor id for Update : ");
                                    scanf("%d",&id);
                                    update_doc(id);
                                    break;

                            //case 5: exit(0);
                            //default: printf("Wrong Choice!!");
                                     break;
                        }
                    }while(b != -1 && b != 5);

                break;

       // case 3: exit(0);

	    //default: printf("Wrong Choice!!");
        }
    }while(ch!= -1 && ch!= 3);
    return 0;
}

