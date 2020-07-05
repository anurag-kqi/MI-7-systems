#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10
struct society_D
{
    char owner_name[30];
    int flat_num;
    int owner_contact;
    int key;
    int value;
    struct society_D *next;
    struct society_D *prev;


};
struct society_D* root = NULL;
int key;
struct society_D* temp;
struct society_D *next;
struct society_D *prev;

/*struct Maintenance
{
     int water_bill;
     int electricity_bill;
    struct maintenance *next;
    struct maintenance *prev;
};
struct visitors
{
    char visitor_name[30];
    int vehicle_num;
    int visitor_contact;
    struct visitors *next;
    struct visitors *prev;
};*/
struct Complaints_D
{
    char complaints_name[50];
    char suggestions_name[50];
    struct complaints*next;
    struct complaints *prev;
};

struct complaints_D* root1 = NULL;
int key;
struct complaints_D* temp1;
struct complaints_D *next1;
struct complaints_D *prev1;


 struct society_D* arr[10];
    void insert_society_D(char owner_name[], int flat_num, int owner_contact);
    void display_society_D();
    void delete_society_D(int key, int flat_num);
    void insert_complaints_D(char complaints_name[],char suggesions_name[])
    void display_complaints_D();
    
void init()
{
    int i;
    for(i = 0; i < size; i++) {
        arr[i] = NULL;
    }
}
void insert_society_D(char owner_name[], int flat_num, int owner_contact)
{
    //create a newnode with value
    //int key;
    struct society_D* newNode = (struct society_D*)malloc(sizeof(struct society_D));
    strcpy(newNode->owner_name, owner_name);
    //newNode->owner_name = owner_name;
    newNode->flat_num = flat_num;
    newNode->owner_contact = owner_contact;
    newNode->next = NULL;
    newNode->prev = next;

    //calculate hash key
    key = flat_num % size;

    newNode->next = NULL;
    newNode->prev = NULL;

    if(root == NULL) {

        root = newNode;
    }

    else {
        struct society_D* temp = root;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        //newNode->next = NULL;
    }
    printf("Node inserted\n");
}

void insert_complaints_D(char complaints_name[],char suggesions_name[])
{
    struct complaints_D* newNode = (struct complaints_D*)malloc(sizeof(struct complaints_D));
    strcpy(newNode->complaints_name, complaints_name);
     strcpy(newNode->suggesions_name, suggesions_name);
    //newNode->owner_name = owner_name;
    
    
    newNode->next1 = NULL;
    newNode->prev1 = next1;

    //calculate hash key
  //  key = flat_num % size;

    newNode->next1 = NULL;
    newNode->prev1 = NULL;

    if(root1 == NULL) {

        root1 = newNode;
    }

    else {
        struct complaints_D* temp1 = root1;

        while(temp1->next1 != NULL){
            temp1 = temp1->next1;
        }
        temp1->next1 = newNode;
        newNode->prev1 = temp1;
        //newNode->next = NULL;
    }
    printf("Node inserted\n");
             
}

void display_complaints_D();
{
    //int key;
    struct complaints_D *temp1;
    temp1 = root1;
    /*if (temp == NULL)
    {
      printf("list is empty :");
    }
    else{*/
      while(temp1) {
          printf("%s,%s", temp1->complaints_name, temp1->suggesions_name);
          temp1 = temp1->next1;
      }
        /*for(int i = 0; i < size; i++) {
        struct society_D *temp = arr[i];
        printf("arr[%d]->",i);*/

        //printf("NULL\n");
}    

void display_society_D()
{
    //int key;
    struct society_D *temp;
    temp = root;
    /*if (temp == NULL)
    {
      printf("list is empty :");
    }
    else{*/
      while(temp) {
          printf("%s, %d, %d -->", temp->owner_name, temp->flat_num, temp->owner_contact);
          temp = temp->next;
      }
        /*for(int i = 0; i < size; i++) {
        struct society_D *temp = arr[i];
        printf("arr[%d]->",i);*/

        //printf("NULL\n");
    }

void delete_society_D(int key, int flat_num)
{
    key = flat_num % size;
    //struct society_D *ptr = arr[key], *toDelete;
    struct society_D *ptr = arr[key];
    struct society_D *toDelete;

    if(ptr == NULL) {
        printf("\n List is Empty");
    }
     else if(ptr->flat_num == key && ptr->next == NULL) {
        ptr = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
    else {
	while(ptr->next != NULL) {
            if(ptr->next->flat_num == key) {

                toDelete = ptr->next;
        	ptr->next = toDelete->next;
        	toDelete->next->prev = ptr;
        	free(toDelete);
            }
            ptr = ptr->next;
        }
        printf("\nnode deleted successfully\n");
    }
}


int
main()
{
    char owner_name[10],complaints_name[20],suggesions_name[20];
    int flat_num, owner_contact,ch;
   //init array of list to NULL
    init();
    while(1) {

        printf("\nSociety Data");
        printf("\n1.insert_society_D\n2.Display data\n3.delete data\n4.Exit\n");
        printf("\nEnter your choice(1-6) : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                    printf("\nINSERT IN TO");
                    printf("\n1.Society data\n2.complaints data\n3.Exit(0)");
                    printf("\n\nEnter your choice to insert(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter owner_name : ");
                                          scanf("\t %s", &owner_name);
                                          printf("\n\tEnter flat_num : ");
                                          scanf("\t %d", &flat_num);
                                          printf("\n\tEnter owner_contact : ");
                                          scanf("\t %d", &owner_contact);
                                          insert_society_D(owner_name, flat_num, owner_contact);

                                break;
                                
                         case 2: printf("\n\n\t Enter the complaints : ");
                                 scanf("\t %s", &complaints_name);
                                 printf("\n\n\t Enter the suggesions : ");
                                 scanf("\t %d", &suggesions_name);
                                 			    
                                 			                    insert_complaints_D(complaints_name,suggesions_name);
                               break;  			                 
                                        
                        case 3: exit(0);

                        default: printf("Wrong Choice!!");
                     }
                    break;

            case 2: printf("\nDISPLAY SOCIETY DATA");
                    printf("\n1.society data\n2.complaints data\n3.Exit(0)");
                    printf("\n\nEnter your choice to display(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: display_society_D();
                                break;
                                
                        case 2: display_complaints_D();
                                 break;

                        case 3: exit(0);

                        default: printf("Wrong Choice!!");
                    }
                    break;


          case 3: printf("\nDELETE FROM");
                    printf("\n1.Society DATA\n3.EXIT");
                    printf("\n\nEnter your choice to delete(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: printf("Enter society data for Delete : ");
                                printf("enter flat_num for delete:\n");
                                scanf("%d",&flat_num);
				                        delete_society_D(key, flat_num);
                                break;


                        default: printf("Wrong Choice");
                    }

                    break;
                  }
              };

              return 0;
            }


