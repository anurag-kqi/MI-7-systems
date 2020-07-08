
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define size 1000
struct society_D
{
    char owner_name[30];
    int flat_num;
    int new_flat_num;
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
    int new_water_bill;
    int new_electricity_bill;
    int key;
    int flat_num1;
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
    int new_vehicle_num;
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
    int flat_number;
    int new_flat_number;
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
    void search_society_D(int flat_num);
    void update_society_D(int flat_num, int new_flat_num);
    void delete_society_D(int flat_num);

/* MAINTENANCE DATA*/
  struct maintenance_D* arr1[1000];
    void insert_maintenance_D(int flat_num1, int water_bill, int electricity_bill);
    void display_maintenance_D();
    void search_maintenance_D(int flat_num1);
    void update_maintenance_D(int water_bill, int electricity_bill,int new_water_bill, int new_electricity_bill) ;
    void delete_maintenance_D(int flat_num1);

  /*VISITORS DATA*/
  struct visitors_D* arr2[1000];
    void insert_visitors_D(char visitor_name[], int vehicle_num, int visitor_contact, int TimeIn, int TimeOut);
    void display_visitors_D();
    void search_visitors_D(int vehicle_num);
    void update_visitors_D(int vehicle_num, int new_vehicle_num);
    void delete_visitors(int vehicle_num);

/*COMPLAINTS DATA*/
  struct complaints_D* arr3[1000];
    void insert_complaints_D(int flat_number, char complaints_name[],char suggestions_name[]);
    void display_complaints_D();
    void search_complaints_D(int flat_number);
    void update_complaints_D(int flat_number, int new_flat_number);
    void delete_complaints_D(int flat_number);

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
    FILE *fp;
    fp = fopen("society.txt", "a+");
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
    fprintf(fp, "owner_name = %s\n", owner_name);
    fprintf(fp, "flat_num = %d\n", flat_num);
    fprintf(fp, "owner_contact = %d\n", owner_contact);
    fclose(fp);
}

/*MAINTENANCE INSERTION*/
void insert_maintenance_D(int flat_num1, int water_bill, int electricity_bill)
{
    FILE *fp;
    fp = fopen("maintenance.txt", "a+");
    struct maintenance_D* newNode = (struct maintenance_D*)malloc(sizeof(struct maintenance_D));
    newNode->flat_num1 = flat_num1;
    newNode->water_bill = water_bill;
    newNode->electricity_bill = electricity_bill;
    newNode->next1 = NULL;
    newNode->prev1 = next1;

    key1= flat_num1 % size;
    newNode->next1 = NULL;
    newNode->prev1 = NULL;

    if(root1 == NULL) {
       root1 = newNode;
    }
    else {
        struct maintenance_D* temp1 = root1;

        while(temp1->next1 != NULL) {
            temp1 = temp1->next1;
        }
        temp1->next1 = newNode;
        newNode->prev1 = temp1;
    }
    printf("Node inserted\n");
    fprintf(fp, "flat_num1 = %d\n", flat_num1);
    fprintf(fp, "water_bill = %d\n", water_bill);
    fprintf(fp, "electricity_bill = %d\n", electricity_bill);
    fclose(fp);
}

/* VISITORS INSERTION*/
void insert_visitors_D(char visitor_name[], int vehicle_num, int visitor_contact, int TimeIn, int TimeOut)
{
    FILE *fp;
    fp = fopen("visitors.txt", "a+");
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

    if(root2 == NULL) {
    root2 = newNode;
    }
    else {
        struct visitors_D *temp2 = root2;
        while (temp2-> next2 != NULL) {
            temp2 = temp2-> next2;
        }
        temp2-> next2 = newNode;
        newNode-> prev2 = temp2;
    }
    printf("Node inserted\n");
    fprintf(fp, "visitor_name = %s\n", visitor_name);
    fprintf(fp, "vehicle_num = %d\n", vehicle_num);
    fprintf(fp, "visitor_contact = %d\n", visitor_contact);
    fprintf(fp, "TimeInIN = %d\n", TimeIn);
    fprintf(fp, "TimeOut = %d\n", TimeOut);
    fclose(fp);
}

/* COMPLAINTS INSERTION*/
void insert_complaints_D(int flat_number, char complaints_name[] ,char suggestions_name[])
{
    FILE *fp;
    fp = fopen("complaints.txt", "a+");
    struct complaints_D* newNode = (struct complaints_D*)malloc(sizeof(struct complaints_D));
    strcpy(newNode->complaints_name, complaints_name);
    strcpy(newNode->suggestions_name, suggestions_name);
    newNode->flat_number = flat_number;

    newNode->next3 = NULL;
    newNode->prev3 = next3;

    key3 = flat_number % size;
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
    fprintf(fp, "flat_number = %d\n", flat_number);
    fprintf(fp, "complaints_name = %s\n", complaints_name);
    fprintf(fp, "suggestions_name = %s\n", suggestions_name);
    fclose(fp);
}

/* SOCIETY DISPLAY*/
void display_society_D()
{
    FILE *fp;
    fp = fopen("society.txt", "r");
    struct society_D *temp;
    temp = root;
    if(temp!=NULL) {
      while(temp) {
          printf("%s, %d, %d ", temp->owner_name, temp->flat_num, temp->owner_contact);
          temp = temp->next;
      }
    }
else {
    printf("society data is empty or deleted");
}
    fclose(fp);
}

/* MAINTENANCE DISPLAY*/
void display_maintenance_D()
{
    struct maintenance_D *temp1;
    temp1 = root1;
    if(temp1!=NULL) {
      while(temp1) {
          printf("%d, %d %d", temp1->flat_num1, temp1->water_bill, temp1->electricity_bill);
          temp1 = temp1->next1;
      }
    }
else {
    printf("maintenance data is empty or deleted");
}
}

/* VISITORS DISPLAY*/
void display_visitors_D()
{
    struct visitors_D *temp2;
    temp2 = root2;
    if(temp2!=NULL) {
    while(temp2) {
        printf("%s, %d, %d, %d, %d",temp2->visitor_name, temp2->vehicle_num, temp2->visitor_contact, temp2->TimeIn, temp2->TimeOut);

        temp2 = temp2-> next2;
    }
}
else {
    printf("visitors data is empty or deleted");
}
}

/* COMPLAINTS DISPLAY*/
void display_complaints_D()
{
    struct complaints_D *temp3;
    temp3 = root3;
    if(temp3!=NULL) {
      while(temp3) {
          printf("%d,%s,%s",temp3->flat_number, temp3->complaints_name, temp3->suggestions_name);
          temp3 = temp3->next3;
      }
}
else {
    printf("complaints data is empty or deleted");
}
}

/*SOCIETY SEARCH*/
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
          printf("\n\towner_name - %s\n\tflat_num - %d\n\towner_contact - %d",
                 root->owner_name, root->flat_num,  root->owner_contact);
          return;
        }
        if(prev->next != NULL) {
           prev = prev->next;
        }
        else {
           break;
        }
    }
}
/*MAINTENANCE SEARCH*/
void search_maintenance_D(int flat_num1)
{
    int pos = 0;
    if(root1==NULL) {
      printf("Linked List not initialized");
      return;
    }
    prev1 = root1;
    while(prev1!=NULL) {
        pos++;
        if(prev1->flat_num1== flat_num1) {
          printf("%d found at position %d\n", flat_num1, pos);
          printf("\n\twater_bill - %d\n\tflat_num1 - %d\n\telectricity_bill - %d",
                 root1->water_bill, root1->flat_num1,  root1->electricity_bill);
          return;
        }
        if(prev1->next1 != NULL) {
           prev1 = prev1->next1;
        }
      else {
         break;
      }
    }
}

/*VISITORS SEARCH*/
void search_visitors_D(int vehicle_num)
{
    int pos = 0;
    if(root2==NULL) {
      printf("Linked List not initialized");
      return;
    }
    prev2 = root2;
    while(prev2!=NULL) {
        pos++;
        if(prev2->vehicle_num == vehicle_num) {
          printf("%d found at position %d\n", vehicle_num, pos);
          printf("\n\tvisitor_name - %s\n\tvehicle_num - %d\n\tvisitor_contact - %d\n\tTimeIn -%d\n\tTimeOut - %d",
                root2->visitor_name, root2->vehicle_num, root2->visitor_contact, root2->TimeIn, root2->TimeOut);

          return;
        }
        if(prev2->next2 != NULL) {
           prev2 = prev2->next2;
        }
      else {
         break;
      }
  }
}

/*COMPLAINTS SEARCH*/
void search_complaints_D(int flat_number)
{
    int pos = 0;
    if(root3==NULL) {
      printf("Linked List not initialized");
      return;
    }
    prev3 = root3;
    while(prev3!=NULL) {
        pos++;
        if(prev3->flat_number == flat_number) {
          printf("%d found at position %d\n", flat_number, pos);
          printf("\n\tflat_number - %d\n\tcomplaints_name - %s\n\tsuggestions_name - %s",
                 root3->flat_number, root3->complaints_name, root3->suggestions_name);
          return;
        }
        if(prev3->next3 != NULL) {
           prev3 = prev3->next3;
        }
      else {
         break;
      }
    }
}

/*SOCIETY UPDATION*/
void update_society_D(int flat_num, int new_flat_num)
{
   int pos = 0;

   if(root == NULL) {
      printf("Linked List not initialized");
      return;
   }

   prev = root;
   while(prev!=NULL) {
      pos++;

      if(prev->flat_num== flat_num) {
         prev->flat_num = new_flat_num;
         printf("\n%d found at position %d, replaced with %d\n", flat_num, pos, new_flat_num);
         return;
      }

      if(prev->next != NULL) {
         prev = prev->next;
      }
      else {
         break;
      }
   }
   printf("%d does not exist in the list\n", flat_num);
}


/*MAINTENANCE UPDATION*/
void update_maintenance_D(int water_bill, int electricity_bill,int new_water_bill, int new_electricity_bill)
{
   int pos = 0;

   if(root1 == NULL) {
      printf("Linked List not initialized");
      return;
   }

   prev1 = root1;
   while(prev1!=NULL) {

      pos++;

      if(prev1->water_bill = water_bill, prev1->electricity_bill == electricity_bill) {
         prev1->water_bill = new_water_bill, prev1->electricity_bill = new_electricity_bill;
         printf("\n%d found at position %d, replaced with %d\n",water_bill, pos, new_water_bill);
         printf("\n%d found at position %d, replaced with %d\n",electricity_bill, pos, new_electricity_bill);
         return;
      }

      if(prev1->next1 != NULL) {
         prev1 = prev1->next1;
      }
      else {
         break;
      }
   }
   printf("%d %d does not exist in the list\n", water_bill, electricity_bill);
}

/*VISITORS UPDATION*/
void update_visitors_D(int vehicle_num, int new_vehicle_num)
{
  int pos = 0;

  if(root2 == NULL) {
     printf("Linked List not initialized");
     return;
  }

  prev2 = root2;
  while(prev2!=NULL) {

     pos++;

     if(prev2->vehicle_num == vehicle_num) {
        prev2->vehicle_num = new_vehicle_num;
        printf("\n%d found at position %d, replaced with %d\n",vehicle_num, pos, new_vehicle_num);
        return;
     }

     if(prev2->next2 != NULL)
        prev2 = prev2->next2;
     else
        break;
  }
  printf("%d does not exist in the list\n", vehicle_num);
}

/*COMPLAINTS UPDATION*/
void update_complaints_D(int flat_number, int new_flat_number)
{
  int pos = 0;

  if(root3 == NULL) {
     printf("Linked List not initialized");
     return;
  }

  prev3 = root3;
  while(prev3 !=NULL) {

     pos++;

     if(prev3->flat_number == flat_number) {
        prev3->flat_number = new_flat_number;
        printf("\n%d found at position %d, replaced with %d\n",flat_number, pos, new_flat_number);
        return;
     }

     if(prev3->next3 != NULL) {
        prev3 = prev3->next3;
     }
     else {
        break;
     }
  }
  printf("%d does not exist in the list\n", flat_number);
}

/*SOCIETY DELETION*/
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

/*MAINTENANCE DELETION*/
void delete_maintenance_D(int flat_num1)
{
    int key1 = flat_num1% size;
    struct maintenance_D *toDelete;
    struct maintenance_D *temp1 = arr1[key1];
    if(root1 == NULL) {
        printf("\n List is Empty");
    }
     else if(root1->flat_num1 == flat_num1) {
        root1 = NULL;
        arr1[key1] = NULL;
        free(root1);
        printf("\nnode deleted\n");
    }
    else {
	  while(root1->next1 != NULL) {
        if (root1->next1->flat_num1 == flat_num1) {
          root1 = NULL;
          toDelete = root1->next1;
        	root1->next1 = toDelete->next1;
        	toDelete->next1->prev1 = temp1;
        	free(toDelete);
        }
        root1 = root1->next1;
    }
        printf("\nnode deleted successfully\n");
    }
}
/*VISITORS DELETION*/
void delete_visitors_D(int vehicle_num)
{
    int key = vehicle_num % size;
    struct visitors_D *toDelete;
    struct visitors_D *temp2 = arr2[key];
    if(root2 == NULL) {
        printf("\n List is Empty");
    }
     else if(root2->vehicle_num == vehicle_num) {
        root2 = NULL;
        arr2[key2] = NULL;
        free(root2);
        printf("\nnode deleted\n");
    }
    else {
	  while(root2->next2 != NULL) {
        if (root2->next2->vehicle_num == vehicle_num) {
          root2 = NULL;
          toDelete = root2->next2;
        	root2->next2 = toDelete->next2;
          toDelete->next2->prev2 = temp2;
        	free(toDelete);
        }
          root2 = root2->next2;
        }
        printf("\nnode deleted successfully\n");
    }
}

/*COMPLAINTS DELETION*/
void delete_complaints_D(int flat_number)
{
    int key3 = flat_number % size;
    struct complaints_D *toDelete;
    struct complaints_D *temp3 = arr3[key3];
    if(root3 == NULL) {
        printf("\n List is Empty");
    }
     else if(root3->flat_number == flat_number) {
        root3 = NULL;
       arr3[key3] = NULL;
        free(root3);
        printf("\nnode deleted\n");
    }
    else {
	  while(root3->next3 != NULL) {
        if (root3->next3->flat_number == flat_number) {
          root3 = NULL;
          toDelete = root3->next3;
        	root3->next3 = toDelete->next3;
        	toDelete->next3->prev3 = temp3;
          free(toDelete);
        }
          root3 = root3->next3;
        }
        printf("\nnode deleted successfully\n");
    }
}

int
main()
{
    char owner_name[30], complaints_name[50], suggestions_name[50], visitor_name[30];
    int flat_num, flat_num1, new_flat_num, flat_number, new_flat_number, owner_contact, visitor_contact,TimeIn,TimeOut, water_bill, electricity_bill, new_water_bill, new_electricity_bill, vehicle_num, new_vehicle_num, ch;
    while(1) {

        printf("\n MANAGEMENT DATA");
        printf("\n1.insert data\n2.Display data\n3.search data\n4.update data\n5.delete data\n6.Exit");
        printf("\nEnter your choice(1-6) : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:printf("\nINSERT IN TO");
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

                        case 2: printf("\n\n\tEnter flat_num1 : ");
                                scanf("\t %d", &flat_num1);
                                printf("\n\n\tEnter water_bill : ");
                                scanf("\t %d", &water_bill);
                                printf("\n\tEnter electricity_bill : ");
                                scanf("\t %d", &electricity_bill);
                                insert_maintenance_D(flat_num1, water_bill, electricity_bill);
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

                        case 4:printf("\n\tEnter complainter's flat_number : ");
                                scanf("\t %d", &flat_number);
                                printf("\n\n\t Enter the complaints_name : ");
                                scanf("\t %s", complaints_name);
                                printf("\n\n\t Enter the suggestions_name : ");
                                scanf("\t %s", suggestions_name);
                                insert_complaints_D(flat_number, complaints_name, suggestions_name);
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
                    printf("\n1.Society data\n2.Maintenance data\n3.visitors data\n4.complaints data\n5.EXIT");
                    printf("\n\nEnter your choice to search(1-5):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: printf("enter flat_num for search:");
                                scanf("%d",&flat_num);
        				                search_society_D(flat_num);
                                break;
                        case 2: printf("enter flat_num for search:");
                                scanf("%d",&flat_num1);
                                search_maintenance_D(flat_num1);
                                break;
                        case 3: printf("enter vehicle_num for search:");
                                scanf("%d",&vehicle_num);
                        				search_visitors_D(vehicle_num);
                                break;
                        case 4: printf("enter complainter's flat_number for search:");
                                scanf("%d", &flat_number);
				                        search_complaints_D(flat_number);
                                break;
                        case 5: exit(0);
                        default: printf("Wrong Choice");
                        }
                        break;
            case 4: printf("\nupdate");
                    printf("\n1.Society data\n2.Maintenance data\n3.visitors data\n4.complaints data\n5.EXIT");
                    printf("\n\nEnter your choice to search(1-5):");
                    scanf("%d", &ch);

                    switch(ch)
                   {
                        case 1: printf("\n\n\tEnter old flat_num : ");
                                scanf("\t %d", &flat_num);
                                printf("\n\n\tEnter new_flat_num for Update : ");
                                scanf("\t %d", &new_flat_num);
				                        update_society_D(flat_num, new_flat_num );
                                break;
                        case 2: printf("\n\n\tEnter water_bill for Update : ");
                                scanf("\t %d", &water_bill);
                                printf("\n\n\tEnter new_water_bill for Update : ");
                                scanf("\t %d", &new_water_bill);
                                printf("\n\n\tEnter electricity_bill for Update : ");
                                scanf("\t %d", &electricity_bill);
                                printf("\n\n\tEnter new_electricity_bill for Update : ");
                                scanf("\t %d", &new_electricity_bill);
                                update_maintenance_D(water_bill, electricity_bill, new_water_bill, new_electricity_bill);
                                break;
                        case 3: printf("\n\n\tEnter vehicle_num for Update : ");
                                scanf("\t %d", &vehicle_num);
                                printf("\n\n\tEnter new_vehicle_num for Update : ");
                                scanf("\t %d", &new_vehicle_num);
        				                update_visitors_D(vehicle_num, new_vehicle_num);
                                break;
                        case 4: printf("\n\n\tEnter flat_number for Update : ");
                                scanf("\t %d", &flat_number);
                                printf("\n\n\tEnter new_flat_number for Update : ");
                                scanf("\t %d", &new_flat_number);
        				                update_complaints_D(flat_number, new_flat_number);
                                break;
                        case 5: exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

            case 5: printf("\nDELETE FROM");
                    printf("\n1.Society DATA\n2.Maintenance data\n3.visitors data\n4.complaints data\n5.EXIT");
                    printf("\n\nEnter your choice to delete(1-5):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: printf("enter flat_num for delete:");
                                scanf("%d",&flat_num);
				                        delete_society_D(flat_num);
                                break;
                        case 2: printf("enter flat_num for delete:");
                                scanf("%d", &flat_num1);
				                        delete_maintenance_D(flat_num1);
                                break;

                         case 3:
                                printf("enter vehicle_num for delete:");
                                scanf("%d", &vehicle_num);
				                        delete_visitors_D(vehicle_num);
                                break;

                         case 4:
                                printf("enter complainter's flat_number for delete:");
                                scanf("%d", &flat_number);
				                        delete_complaints_D(flat_number);
                                break;
                        case 5: exit(0);
                        default: printf("Wrong Choice");
                    }
                    break;
            case 6: exit(0);

                  }
              };
             return 0;
            }
