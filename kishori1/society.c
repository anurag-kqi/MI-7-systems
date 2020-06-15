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
};
struct Complaints
{
    char complaint[50];
    char suggestion[50];
    struct complaints*next;
    struct complaints *prev;
};*/

 struct society_D* arr[10];
    void insert_society_D(char owner_name[], int flat_num, int owner_contact);
    void display_society_D();
    //void delete_society_D(int key);
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
    //newNode->prev = next;

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



/*void delete_society_D(int key)
{
    int key = key % size;
    struct society_D *ptr = arr[key], *toDelete;

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
}*/


int
main()
{
    char owner_name[10];
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
                    printf("\n1.Society data\n3.Exit(0)");
                    printf("\n\nEnter your choice to insert(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: printf("Enter owner_name, flat_num, owner_contact respectively : ");
				                        scanf("%s, %d, %d", &owner_name, &flat_num, &owner_contact);
			                	        insert_society_D(owner_name, flat_num, owner_contact);
                                break;
                        case 3: exit(0);

                        default: printf("Wrong Choice!!");
                     }
                    break;

            case 2: printf("\nDISPLAY SOCIETY DATA");
                    printf("\n1.society data\n3.Exit(0)");
                    printf("\n\nEnter your choice to display(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: display_society_D();
                                break;

                        case 3: exit(0);

                        default: printf("Wrong Choice!!");
                    }
                    break;


          /*  case 3: printf("\nDELETE FROM");
                    printf("\n1.Society DATA\n3.EXIT");
                    printf("\n\nEnter your choice to delete(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1: printf("Enter society data for Delete : ");
                                printf("enter flat_num for delete:\n");
                                scanf("%d",&flat_num);
				                        //delete_society_D(flat_num);
                                break;


                        default: printf("Wrong Choice");
                    }

                    break;
                  }*/
              }
            };
              return 0;
}
