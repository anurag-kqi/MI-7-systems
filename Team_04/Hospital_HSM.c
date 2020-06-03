#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

struct doctor
{
    int id;
    char name[30];
    char address[50];
    int contact;
    struct doctor *next;
    struct doctor *prev;
   
};


    struct patient *index[size];
    void insert_pat(int id, char name[], int age, char address[], int contact);
    void display_pat();
    void delete_pat(int id);
    void update_pat(int id);
    
    struct doctor *index1[size];
    void insert_doc(int id, char name[], char address[], int contact);
    void display_doc();
    void delete_doc(int id);
    void update_doc(int id);
    
void init()
{
    int i;
    for(i = 0; i < size; i++) {
        index[i] = NULL;
        index1[i] = NULL;
    }
}

void insert_pat(int id, char name[], int age, char address[], int contact)
{
    //create a newnode with value
    struct patient *newNode = malloc(sizeof(struct patient));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->age = age;
    strcpy(newNode->address, address);
    newNode->contact = contact;
    newNode->next = NULL;
    newNode->prev = NULL;

    //calculate hash key
    int key = id % size;

    if(index[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        index[key] = newNode;
    }
    else {
        struct patient *temp = index[key];

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
    //create a newnode with value
    struct doctor *newNode = malloc(sizeof(struct doctor));
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    newNode->contact = contact;
    newNode->next = NULL;
    newNode->prev = NULL;

    //calculate hash key
    int key = id % size;

    if(index1[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        index1[key] = newNode;
    }
    else {
        struct doctor *temp = index1[key];

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
    struct patient *ptr = index[key], *toDelete;

    if (ptr == NULL) {
        printf("\n\n\tThis ID does not exist !!!\n");
    }
    else if (ptr->id == id && ptr->next == NULL) {
        ptr = NULL;
        free(ptr);
        printf("\n\n\tId Deleted !\n");
    } else {
	while (ptr->next != NULL) {
            if (ptr->next->id == id) {
                toDelete = ptr->next;
                ptr->next = toDelete->next;
                toDelete->next->prev = ptr;
                free(toDelete);
            }
            ptr = ptr->next;
        }
        printf("\n\n\tID Deleted successfully!!!!\n");
    }

}




void display_pat()
{
    int i;

    for(i = 0; i < size; i++) {
        struct patient *temp = index[i];
        printf("index[%d]-->",i);
        while(temp) {
            printf("%d %s %d %s %d -->",temp->id, temp->name, temp->age, temp->address, temp->contact);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void display_doc()
{
    int i;

    for(i = 0; i < size; i++) {
        struct doctor *temp = index1[i];
        printf("index1[%d]-->",i);
        while(temp) {
            printf("%d %s %s %d -->",temp->id, temp->name, temp->address, temp->contact);
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

    ptr = index[key];
    if(ptr == NULL) {
        printf("\nEmpty List\n");
    } else {

        while (ptr != NULL) {
            if(ptr->id == id) {
                printf("\n Old Data !!!");
                printf("\n\nPatient Id - %d\nPatient Name - %s\n Age - %d\n Address - %s\n Contact - %d",
                       ptr->id, ptr->name, ptr->age, ptr->address, ptr->contact);

		printf("\nPatient New Data !!!");

		int id, contact, age;
    		char name[30], address[50];

		printf("Enter ID, Name, Age, Address, Contact respectively : ");
		scanf("%d %s %d %s %d", &id, &name, &age, &address, &contact);

		ptr->id = id;
    		strcpy(ptr->name, name);
    		ptr->age = age;
    		strcpy(ptr->address, address);
    		ptr->contact = contact;

		printf("\n\nPatient Id - %d\nPatient Name - %s\nAge - %d\n Address - %s\n Contact - %d",
                       ptr->id, ptr->name, ptr->age, ptr->address, ptr->contact);
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
            printf("\nItem not found\n");
        }
    }

}

void update_doc(int id)
{
    struct doctor *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = index1[key];
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
        char name[30], address[50];

		printf("Enter ID, Name, Address, Contact respectively : ");
		scanf("%d %s %s %d", &id, &name, &address, &contact);

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
            printf("\nItem not found\n");
        }
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
                                    printf("\nEnter ID, Name, Age, Address, Contact respectively : ");
                                    scanf("%d %s %d %s %d", &id, &name, &age, &address, &contact);
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
          case 2:
                    do{
                        printf("\n----DOCTOR DEPARTMENT----");
                        printf("\n\n1.INSERT DATA\n2.DISPLAY DATA\n3.DELETE DATA\n4.UPDATE DATA\n5.EXIT\n\n");
                        printf("\n\nEnter your choice to insert(1-5):");
                        scanf("%d", &b);
                        switch(b)

                        {
                            case 1: printf("\n---- INSERT IN TO DOCTOR----\n");
                                    printf("\nEnter ID, Name, Clinic Address, Contact respectively : ");
                                    scanf("%d %s %s %d", &id, &name, &address, &contact);
                                    insert_doc(id, name, address, contact);
                                    break;

                            case 2: printf("\n---- DISPLAY DOCTOR DATA ----");
                                    display_doc();
                                    break;

                            case 3: printf("\n---- DELETE DOCTOR DATA ----");
                                    printf("Enter Doctor ID for Delete : ");
                                    scanf("%d",&id);
                                    //delete_doc(id);
                                    break;

                            case 4: printf("\n---- UPDATE DOCTOR DATA ----");
                                    printf("Enter Doctor id for Update : ");
                                    scanf("%d",&id);
                                    update_doc(id);
                                    break;

                            //case 5: exit(0);
                            default: printf("Wrong Choice!!");
                                     break;
                        }
                    }while(b != -1 && b != 5);

                break;

       // case 3: exit(0);

	    default: printf("Wrong Choice!!");
        }
    }while(ch!= -1 && ch!= 3);
    return 0;
}
