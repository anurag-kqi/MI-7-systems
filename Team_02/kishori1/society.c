#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 9

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

struct maintenance_D
{
    int water_bill;
    int electricity_bill;
    int key;
    int value;
    struct maintenance_D *next;
    struct maintenance_D *prev;
};
struct maintenance_D *root2 = NULL;
//int key;
struct maintenance_D *temp2;
struct maintenance_D *next2;
struct maintenance_D *prev2;



/*struct visitors
{
    char visitor_name[30];
    int vehicle_num;
    int visitor_contact;
    struct visitors *next;
    struct visitors *prev;
};
struct Complaints
{
    char complaint[50];
    char suggestion[50];
    struct complaints*next;
    struct complaints *prev;
};*/
 /* SOCIETY DATA*/
  struct society_D* arr[10];
    void insert_society_D(char owner_name[], int flat_num, int owner_contact);
    void display_society_D();
    //void delete_society_D(int key, int flat_num);
    void search_society_D(char owner_name[]);


  /* MAINTENANCE DATA*/
  struct maintenance_D* arr2[10];
    void insert_maintenance_D(int water_bill, int electricity_bill);
    void display_maintenance_D();

    void init()
{
    int i;
    for(i = 0; i < size; i++) {
        arr[i] = NULL;
        arr2[i] = NULL;

    }
}
/*SOCIETY INSERTION*/
void insert_society_D(char owner_name[], int flat_num, int owner_contact)
{
    //create a newnode with value
    //int key;
    struct society_D* newNode = (struct society_D*)malloc(sizeof(struct society_D));
    strcpy(newNode->owner_name, owner_name);
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

/* MAINTENANCE INSERTION*/
void insert_maintenance_D(int water_bill, int electricity_bill)
{
  struct maintenance_D* newNode = (struct maintenance_D*)malloc(sizeof(struct maintenance_D));

  newNode->water_bill= water_bill;
  newNode->electricity_bill = electricity_bill;
  newNode->next = NULL;
  newNode->prev = NULL;
  //calculate hash key
  key = water_bill % size;
  key = electricity_bill % size;

      if (root2 == NULL) {
        root2 = newNode;
  }

  else {
      struct maintenance_D* temp2 = root2;

      while(temp2->next != NULL){
          temp2 = temp2->next;
        }
        temp2->next = newNode;
        newNode->prev = temp2;
    }
    printf("Node inserted\n");
}

void display_society_D()
{
    struct society_D *temp;
    temp = root;
    while(temp) {
          printf("%s, %d, %d -->", temp->owner_name, temp->flat_num, temp->owner_contact);
          temp = temp->next;
      }

    }

    void display_maintenance_D()
    {
        struct maintenance_D *temp2;
        temp2 = root2;
        while (temp2) {
            printf("%d %d -->",temp2->water_bill, temp2->electricity_bill);
            temp2 = temp2->next;
        }
        printf("NULL\n");
    }


  /*void search_society_D(char owner_name[])
{
    struct society_D *ptr;
    int i=0, flag;

    //int key = flat_num % size;

    ptr = arr[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
      while (ptr != NULL) {
            if (ptr->owner_name == owner_name) {
                printf("\n\n\tflat_num found at location %d ", i+1);
                printf("\n\n\tflat_num- %d\n\towner_name - %s\n\towner_contact - %d"-
                       ptr->flat_num, ptr->owner_name, ptr->owner_contact);
                flag = 0;
                break;
            } else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if (flag==1) {
            printf("\n\n\tnot found\n");
        }
    }
}*/


/*void delete_society_D(int key, int flat_num)
{
  //int key;
    key = flat_num % size;
    struct society_D *ptr = arr[key], *toDelete;
    //struct society_D *ptr = arr[key];
    //struct society_D *toDelete;

    if(ptr == NULL) {
        printf("\n List is Empty");
    }
    else if(ptr->flat_num == flat_num && ptr->next == NULL) {
      arr[key] = NULL;
        ptr = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
    else {
	while(ptr->next != NULL) {
            if(ptr->next->flat_num == flat_num) {

                toDelete = ptr->next;
        	ptr->next = toDelete->next;
        	toDelete->next->prev = ptr;
        	free(toDelete);
            }
            ptr = ptr->next;
        }
        printf("\nnode deleted successfully\n");
    }
}*/


int
main()
{
    char owner_name[10];
    int flat_num, owner_contact,ch, water_bill, electricity_bill;
   //init array of list to NULL
    init();
    while(1) {

        printf("\nSOCIETY MANAGEMENT");
        printf("\n1.insert data\n2.Display data\n3.delete data\n4.search data\n5.Exit\n");
        printf("\nEnter your choice(1-6) : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                    printf("\nINSERT IN TO");
                    printf("\n1.Society data\n2.maintenance data\n3.Exit(0)");
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
                        case 2: printf("\n\n\tEnter water_bill : ");
				                                  scanf("\t %d", &water_bill);
				                                  printf("\n\tEnter electricity_bill : ");
				                                  scanf("\t %d", &electricity_bill);
				                                  insert_maintenance_D(water_bill, electricity_bill);
                                break;

                        case 3: exit(0);

                        default: printf("Wrong Choice!!");
                     }
                    break;

            case 2: printf("\nDISPLAY SOCIETY DATA");
                    printf("\n1.society data\n2. maintenance data\n3.Exit(0)");
                    printf("\n\nEnter your choice to display(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: display_society_D();
                                break;
                        case 2: display_maintenance_D();
                                break;

                        case 3: exit(0);

                        default: printf("Wrong Choice!!");
                    }
                    break;


          /*case 3: printf("\nDELETE FROM");
                    printf("\n1.Society DATA\n3.EXIT");
                    printf("\n\nEnter your choice to delete(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: //printf("Enter society data for Delete : ");
                                printf("enter flat_num for delete:\n");
                                scanf("%d",&flat_num);
				                        delete_society_D(key, flat_num);
                                break;


                        default: printf("Wrong Choice");
                    }

                    //break;*/

                    /*case 4: printf("\n\n\t SEARCH FROM");
                    printf("\n\n\t1.society data\n\t2.EXIT");
                    printf("\n\n\tEnter your choice to search(1-3) : ");
                    scanf("\t %d", &ch);

                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter owner_name for Search : ");
                                scanf("\t%s, &owner_name");
				                        search_society_D(owner_name);
                                break;


                        case 3: exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;*/

                  }
              };
              return 0;
            }
