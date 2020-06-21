#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10
struct patient
{
    int id;
    char name[20];
    int age;
    char bloodgrp[10];
    char address[50];
    int contact;
    char symptoms[40];
    struct patient *next;
    struct patient *prev;

};

struct doctor
{
    int id;
    char name[20];
    char address[50];
    int contact;
    struct doctor *next;
    struct doctor *prev;

};


    struct patient *index_pat[size];
    void insert_pat(int id, char name[], int age,char bloodgrp[], char address[], int contact, char symtoms[]);
    void display_pat();
    void delete_pat(int id);
    void update_pat(int id);

    struct doctor *index_doc[size];
    void insert_doc(int id, char name[], char address[], int contact);
    void display_doc();
    void delete_doc(int id);
    void update_doc(int id);


void init()
{
    int i;
    for(i = 0; i < size; i++) {
        index_pat[i] = NULL;
        index_doc[i] = NULL;
    }
}


void insert_pat(int id, char name[], int age, char bloodgrp[], char address[], int contact, char symptoms[])
{
    struct patient *newNode = malloc(sizeof(struct patient));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->age = age;
    strcpy(newNode->bloodgrp, bloodgrp);
    strcpy(newNode->address, address);
    newNode->contact = contact;
    strcpy(newNode->symptoms, symptoms);
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
    printf("\n\nNode inserted Successfully...!\n");
}


void insert_doc(int id, char name[], char address[], int contact)
{

    struct doctor *newNode = malloc(sizeof(struct doctor));
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    newNode->contact = contact;
    newNode->next = NULL;
    newNode->prev = NULL;


    int key = id % size;

    if(index_doc[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        index_doc[key] = newNode;
    }
    else {
        struct doctor *temp = index_doc[key];

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
    printf("\n\nNode inserted Successfully...!\n");
}

void delete_pat(int id)
{
    int key = id % size;
    struct patient *ptr = index_pat[key], *toDelete;

    if (ptr == NULL) {
        printf("\n\n\tList is Empty !!!\n");
    }
    else if (ptr->id == id) {
        if (ptr->prev == NULL && ptr->next == NULL) {
            free(ptr);
            index_pat[key] = NULL;
        } else {
            index_pat[key] = ptr->next;
            index_pat[key]->prev = NULL;
            ptr->next = NULL;
            free(ptr);
            return ;
        }

    } else {
	        while (ptr->next != NULL) {
              if (ptr->next->id == id) {
                  toDelete = ptr->next;
                  if (toDelete->next == NULL) {
                      ptr->next = NULL;
                      free(toDelete);
                      return ;
                  } else {
                        ptr->next = toDelete->next;
                        toDelete->next->prev = toDelete->prev;
                        free(toDelete);
                    }
              }
              ptr = ptr->next;
          }
          printf("\n\n\tnode not found\n");
      }
  }






void delete_doc(int id)
{
    int key = id % size;
    struct doctor *ptr = index_doc[key], *toDelete;

    if (ptr == NULL) {
        printf("\n\n\tList is Empty !!!\n");
    }
    else if (ptr->id == id) {
        if (ptr->prev == NULL && ptr->next == NULL) {
            free(ptr);
            index_doc[key] = NULL;
        } else {
            index_doc[key] = ptr->next;
            index_doc[key]->prev = NULL;
            ptr->next = NULL;
            free(ptr);
            return ;
        }

    } else {
	        while (ptr->next != NULL) {
              if (ptr->next->id == id) {
                  toDelete = ptr->next;
                  if (toDelete->next == NULL) {
                      ptr->next = NULL;
                      free(toDelete);
                      return ;
                  } else {
                        ptr->next = toDelete->next;
                        toDelete->next->prev = toDelete->prev;
                        free(toDelete);
                    }
              }
              ptr = ptr->next;
          }
          printf("\n\n\tnode not found\n");
      }
  }




void display_pat()
{
    int i;
    for(i = 0; i < size; i++) {
        struct patient *temp = index_pat[i];
        printf("\nPatient Data[%d]->",i);
        while(temp) {
            printf("%d %s %d %s %s %d %s-->",temp->id, temp->name, temp->age, temp->bloodgrp, temp->address, temp->contact, temp->symptoms);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void display_doc()
{
    int i;

    for(i = 0; i < size; i++) {
        struct doctor *temp = index_doc[i];
        //printf("\t\tID\tName\tAddress\tContact");
        printf("\nDoctor Data[%d]-->",i);
        while(temp) {
            printf("%d\t%s\t%s\t%d -->",temp->id, temp->name, temp->address, temp->contact);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void update_pat(int id)
{
    struct patient *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = index_pat[key];
    if(ptr == NULL) {
        printf("\nEmpty List\n");
    } else {

        while (ptr != NULL) {
            if(ptr->id == id) {
                printf("\n Old Data !!!");
                printf("\n\nPatient Id - %d\nPatient Name - %s\n Age - %d\n Blood Group - %s\n Address - %s\n Contact - %d\n Symptoms - %s",
                       ptr->id, ptr->name, ptr->age, ptr->bloodgrp, ptr->address, ptr->contact, ptr->symptoms);

		printf("\nPatient New Data !!!");

		int id, contact, age;
    		char name[20], bloodgrp[10];
    		char address[50], symptoms[40];

		//printf("Enter ID, Name, Age, Address, Contact respectively : ");
		//scanf("%d %s %d %s %s %d", &id, &name, &age, &bloodgrp, &address, &contact);
		printf("\nEnter Patient ID:");
                                 	scanf("%d",&id);
                                    	printf("\nEnter Patient Name:");
                                    	scanf("%s", name);
                                    	printf("\nEnter Patient Age:");
                                    	scanf("%d",&age);
                                    	printf("\nEnter Patient Blood Group:");
                                    	scanf("%s", bloodgrp);
                                        printf("\nEnter Patient Address:");
                                    	scanf("%s", address);
                                    	printf("\nEnter Patient Contact:");
                                    	scanf("%d",&contact);
                                    	printf("\nEnter Disease Symptoms:");
                                    	scanf("%s", symptoms);
            		ptr->id = id;
    		strcpy(ptr->name, name);
    		ptr->age = age;
    		strcpy(ptr->bloodgrp, bloodgrp);
    		strcpy(ptr->address, address);
    		ptr->contact = contact;
            strcpy(ptr->symptoms, symptoms);
            printf("\n\nPatient Id - %d\nPatient Name - %s\nAge - %d\n Address - %s\n Contact - %d\n Symptoms - %s",ptr->id, ptr->name, ptr->age, ptr->address, ptr->contact, ptr->symptoms);
            printf("\n Record Updated Successfully !!!");
                flag = 0;
                break;
            }
	    else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }

        if(flag==1) {
            printf("\nID not found\n");
        }
    }

}

void update_doc(int id)
{
    struct doctor *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = index_doc[key];
    if(ptr == NULL) {
        printf("\nEmpty List\n");
    } else {

        while (ptr != NULL) {
            if(ptr->id == id) {
                printf("\n Old Data !!!");
                printf("\n\nDoctor Id - %d\nDoctor Name - %s\n Address - %s\n Contact - %d",
                       ptr->id, ptr->name, ptr->address, ptr->contact);

		printf("\nDoctor New Data !!!");

		int id, contact;
        		char name[20], address[50];

		//printf("Enter ID, Name, Address, Contact respectively : ");
		//scanf("%d %s %s %d", &id, &name, &address, &contact);
		printf("\nEnter Doctor ID:");
                                    	scanf("%d",&id);
                                    	printf("\nEnter Doctor Name:");
                                    	scanf("%s", name);
                                    	printf("\nEnter Doctor Address:");
                                    	scanf("%s", address);
                                    	printf("\nEnter Doctor Contact:");
                                    	scanf("%d",&contact);

            		ptr->id = id;
    		strcpy(ptr->name, name);
    		strcpy(ptr->address, address);
    		ptr->contact = contact;

		printf("\n\ndoctor Id - %d\ndoctor Name - %s\n Address - %s\n Contact - %d",
                       ptr->id, ptr->name, ptr->address, ptr->contact);
		printf("\n Record Updated Successfully !!!");
                flag = 0;
                break;
            }
	    else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }

        if(flag==1) {
            printf("\nID not found\n");
        }
    }

}



int
main()
{
    int ch, a, b, id, contact, age;
    char name[20], address[50], bloodgrp[10], symptoms[40];


    init();

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



