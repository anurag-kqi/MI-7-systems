#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 1000
struct society_D
{
    char owner_name[30];
    int flat_num;
    int owner_contact;
    int key;
    struct society_D *next;
    struct society_D *prev;
};
struct society_D *root = NULL;
int key;
struct society_D *temp;
struct society_D *next;
struct society_D *prev;
struct society_D *current;

struct maintenance_D
{
    int water_bill;
    int electricity_bill;
    int key;
    struct maintenance_D *next1;
    struct maintenance_D *prev1;
};
struct maintenance_D *root1 = NULL;
int key1;
struct maintenance_D *temp1;
struct maintenance_D *next1;
struct maintenance_D *prev1;

struct visitors_D
{
    char visitor_name[30];
    int vehicle_num;
    int visitor_contact;
    int TimeIn;
    int TimeOut;
    int key;
    struct visitors_D *next2;
    struct visitors_D *prev2;
};
struct visitors_D *root2 = NULL;
int key2;
struct visitors_D *temp2;
struct visitors_D *next2;
struct visitors_D *prev2;

struct complaints_D
{
    char complaints_name[50];
    char suggestions_name[50];
    int key;
    struct complaints_D *next3;
    struct complaints_D *prev3;
};
struct complaints_D *root3 = NULL;
int key3;
struct complaints_D *temp3;
struct complaints_D *next3;
struct complaints_D *prev3;

/*SOCIETY DATA*/
  struct society_D* arr[1000];
    void insert_society_D(char owner_name[], int flat_num, int owner_contact);
    void display_society_D();
    void delete_society_D(int flat_num);
    void search_society_D(int flat_num);

/* MAINTENANCE DATA*/
  struct maintenance_D* arr1[1000];
    void insert_maintenance_D(int water_bill, int electricity_bill);
    void display_maintenance_D();

  /*VISITORS DATA*/
  struct visitors* arr2[1000];
    void insert_visitors_D(char visitor_name[], int vehicle_num, int visitor_contact, int TimeIn, int TimeOut);
    void display_visitors_D();
    //void delete_visitors(char visitor_name[], int vehicle_num, int visitor_contact, int TimeIn, int TimeOut);*/

/*COMPLAINTS DATA*/
  struct complaints_D* arr3[1000];
    void insert_complaints_D(char complaints_name[],char suggestions_name[]);
    void display_complaints_D();

  void init()
  {
    int i;
    for(i = 0; i < size; i++) {
      arr[i] = NULL;
      arr1[i] = NULL;
      arr2[i] = NULL;
      arr3[i] = NULL;
    }
 }

/*SOCIETY INSERTION*/
void insert_society_D(char owner_name[], int flat_num, int owner_contact)
{
    struct society_D* newNode = (struct society_D*)malloc(sizeof(struct society_D));
    strcpy(newNode->owner_name, owner_name);
    newNode->flat_num = flat_num;
    newNode->owner_contact = owner_contact;
    newNode->next = NULL;
    newNode->prev = next;

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
      }
    printf("Node inserted\n");
}

/*MAINTENANCE INSERTION*/
void insert_maintenance_D(int water_bill, int electricity_bill)
{
    struct maintenance_D* newNode = (struct maintenance_D*)malloc(sizeof(struct maintenance_D));
    newNode->water_bill = water_bill;
    newNode->electricity_bill = electricity_bill;
    newNode->next1 = NULL;
    newNode->prev1 = next1;

    key1= water_bill % size;
    key1 = electricity_bill % size;

    newNode->next1 = NULL;
    newNode->prev1 = NULL;

    if(root1 == NULL) {

        root1 = newNode;
    }
    else {
        struct maintenance_D* temp1 = root1;

        while(temp1->next1 != NULL){
            temp1 = temp1->next1;
        }
        temp1->next1 = newNode;
        newNode->prev1 = temp1;
      }
    printf("Node inserted\n");
}

/* VISITORS INSERTION*/
void insert_visitors_D(char visitor_name[], int vehicle_num, int visitor_contact, int TimeIn, int TimeOut)
{
    struct visitors_D* newNode = (struct visitors_D*)malloc(sizeof(struct visitors_D));
    strcpy(newNode->visitor_name, visitor_name);

    newNode-> vehicle_num = vehicle_num;
    newNode-> visitor_contact = visitor_contact;
    newNode-> TimeIn = TimeIn;
    newNode-> TimeOut = TimeOut;
    newNode-> next2 = NULL;
    newNode-> prev2 = next2;

    key = vehicle_num % size;
    newNode-> prev2 = NULL;
    newNode-> next2 = NULL;

    if(root2 == NULL)
    {
    root2 = newNode;
    }
    else
    {
        struct visitors_D *temp2 = root2;
        while (temp2-> next2 != NULL)
        {
            temp2 = temp2-> next2;
        }

        temp2-> next2 = newNode;
        newNode-> prev2 = temp2;
    }
    printf("Node inserted\n");
}

/* COMPLAINTS INSERTION*/
void insert_complaints_D(char complaints_name[],char suggestions_name[])
{
    struct complaints_D* newNode = (struct complaints_D*)malloc(sizeof(struct complaints_D));
    strcpy(newNode->complaints_name, complaints_name);
    strcpy(newNode->suggestions_name, suggestions_name);

    newNode->next3 = NULL;
    newNode->prev3 = next3;

    //key3 = complaints_name % size;

    newNode->next3 = NULL;
    newNode->prev3 = NULL;

    if(root3 == NULL) {

        root3 = newNode;
    }
    else {
        struct complaints_D* temp3 = root3;
        while(temp3->next3 != NULL){
            temp3 = temp3->next3;
        }
        temp3->next3 = newNode;
        newNode->prev3 = temp3;
        //newNode->next = NULL;
    }
    printf("Node inserted\n");
}

/* SOCIETY DISPLAY*/
void display_society_D()
{
    struct society_D *temp;
    temp = root;

      while(temp) {
          printf("%s, %d, %d ", temp->owner_name, temp->flat_num, temp->owner_contact);
          temp = temp->next;
      }
}

/* MAINTENANCE DISPLAY*/
void display_maintenance_D()
{
    struct maintenance_D *temp1;
    temp1 = root1;

      while(temp1) {
          printf("%d, %d ", temp1->water_bill, temp1->electricity_bill);
          temp1 = temp1->next1;
      }
}

/* VISITORS DISPLAY*/
void display_visitors_D()
{
    struct visitors_D *temp2;
    temp2 = root2;

    while(temp2) {
        printf("%s, %d, %d, %d, %d",temp2->visitor_name, temp2->vehicle_num, temp2->visitor_contact, temp2->TimeIn, temp2->TimeOut);

        temp2 = temp2 -> next2;
    }
}

/* COMPLAINTS DISPLAY*/
void display_complaints_D()
{
    struct complaints_D *temp3;
    temp3 = root3;

      while(temp3) {
          printf("%s,%s", temp3->complaints_name, temp3->suggestions_name);
          temp3 = temp3->next3;
      }
}

void search_society_D(int flat_num)
{
     int pos = 0;

   if(root==NULL) {
      printf("Linked List not initialized");
      return;
   }

   prev = root;
   while(prev!=NULL) {
      pos++;
      if(prev->flat_num == flat_num) {
         printf("%d found at position %d\n", flat_num, pos);
         return;
      }

      if(prev->next != NULL)
         prev = prev->next;
      else

         break;
   }
    //struct society_D *temp = arr[key];
    /*int i=0, flag;

    int key = flat_num % size;

    root = arr[key];
    if (root == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
            while (root != NULL) {
            if (root->flat_num == flat_num) {
                printf("\n\n\tflat_num found at location %d ", i+1);
                printf("owner_name - %s\n\tflat_num - %d\n\towner_contact - %d",
                       root->owner_name, root->flat_num, root->owner_contact);
                flag = 0;
                break;
            } else {
                flag=1;
            }
            i++;
            root = root -> next;
        }
        if (flag==1) {
            printf("\n\n\tflat_num not found\n");
        }*/
    }


void delete_society_D(int flat_num)
{
    int key = flat_num % size;
  //struct society_D *toDelete =  (struct society_D*)malloc(sizeof(struct society_D));
    struct society_D *toDelete;
    struct society_D *temp = arr[key];
    if(root == NULL) {
        printf("\n List is Empty");
    }
     else if(root->flat_num == flat_num) {
        root = NULL;
        arr[key] = NULL;
        free(root);
        printf("\nnode deleted\n");
    }
    else {
	  while(root->next != NULL) {
        if (root->next->flat_num == flat_num) {
          root = NULL;
          toDelete = root->next;
        	root->next = toDelete->next;
        	toDelete->next->prev = temp;
        	free(toDelete);
        }
          root = root->next;
        }
        printf("\nnode deleted successfully\n");
    }
}

int
main()
{
    char owner_name[30], complaints_name[50], suggestions_name[50], visitor_name[30];
    int flat_num, owner_contact, water_bill, electricity_bill, vehicle_num, visitor_contact, TimeIn, TimeOut, ch;
   //init array of list to NULL
    init();
    while(1) {

        printf("\n MANAGEMENT DATA");
        printf("\n1.insert data\n2.Display data\n3.search data\n4.delete data\n5.Exit");
        printf("\nEnter your choice(1-4) : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                    printf("\nINSERT IN TO");
                    printf("\n1.Society data\n2.Maintenance data\n3.visitor data\n4.complaints data\n5.Exit(0)");
                    printf("\n\nEnter your choice to insert(1-5):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter owner_name : ");
                                scanf("\t %s", owner_name);
                                printf("\n\tEnter flat_num : ");
                                scanf("\t %d", &flat_num);
                                printf("\n\tEnter owner_contact : ");
                                scanf("\t %d", &owner_contact);
                                insert_society_D(owner_name, flat_num, owner_contact);
                                break;

                        case 2: printf("\n\n\tEnter water_bill : ");
                                scanf("\t %d", &water_bill);
                                printf("\n\tEnter electricity_bill : ");
                                scanf("\t %d", &electricity_bill);
                                insert_maintenance_D(water_bill, electricity_bill);
                                break;

                        case 3:
                                printf("\n\n\tEnter Visitors Name: ");
              								  scanf("\t%s",visitor_name);
                                printf("\n\t Enter Vehicle Number: ");
              								  scanf("\t%d",&vehicle_num);
                                printf("\n\t Enter visitor contact: ");
              								  scanf("\t%d",&visitor_contact);
                                printf("\n\tEnter Visitor TimeIn: ");
                                scanf("\t%d",&TimeIn);
                                printf("\n\tEnter Visitor TimeOut: ");
                                scanf("\t%d",&TimeOut);
                                insert_visitors_D(visitor_name, vehicle_num, visitor_contact, TimeIn, TimeOut);
                                break;

                        case 4: printf("\n\n\t Enter the complaints_name : ");
                                scanf("\t %s", complaints_name);
                                printf("\n\n\t Enter the suggestions_name : ");
                                scanf("\t %s", suggestions_name);
                                insert_complaints_D(complaints_name, suggestions_name);
                               break;
                        case 5: exit(0);

                        default: printf("Wrong Choice!!");
                     }
                    break;

            case 2: printf("\nDISPLAY SOCIETY DATA");
                    printf("\n1.society data\n2.maintenance data\n3.visitor data\n4.complaint data\n5.Exit(0)");
                    printf("\n\nEnter your choice to display(1-4):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: display_society_D();
                                break;

                        case 2: display_maintenance_D();
                                break;
                        case 3: display_visitors_D();
                                break;
                        case 4: display_complaints_D();
                                break;
                        case 5: exit(0);

                        default: printf("Wrong Choice!!");
                    }
                    break;

            case 3: printf("\nSEARCH");
                    printf("\n1.Society DATA\n2.EXIT");
                    printf("\n\nEnter your choice to delete(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: //printf("Enter society data for Delete : ");
                                printf("enter flat_num for search:");
                                scanf("%d",&flat_num);
        				                search_society_D(flat_num);
                                break;
                        case 2: exit(0);


                        default: printf("Wrong Choice");
                        }

                        break;




            case 4: printf("\nDELETE FROM");
                    printf("\n1.Society DATA\n2.EXIT");
                    printf("\n\nEnter your choice to delete(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: //printf("Enter society data for Delete : ");
                                printf("enter flat_num for delete:");
                                scanf("%d",&flat_num);
				                        delete_society_D(flat_num);
                                break;
                        case 2: exit(0);


                        default: printf("Wrong Choice");
                    }

                    break;
            case 5: exit(0);

                  }


              };
             return 0;
            }
