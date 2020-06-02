#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10
struct society_D
{
    int flat_num;
    char owner_name[30];

    int owner_contact;
    int key;
    int value;
    struct society_D *next;
    //struct society_D *prev;

};
//struct society_D* root = NULL;
int key;
//struct society_D* temp;
//struct society_D* arr[10];
   void insert_society_D(char owner_name[], int flat_num, int owner_contact);
   void display_society_D();
   struct society_D *arr[size];
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
   struct society_D *newNode = (struct society_D*)malloc(sizeof(struct society_D));
   strcpy(newNode->owner_name, owner_name);
   //newNode->owner_name = owner_name;
   newNode->flat_num = flat_num;
   newNode->owner_contact = owner_contact;
   newNode->next = NULL;
   //newNode->prev = next;

   //calculate hash key
   int key = flat_num % size;

   //if(arr[key] == NULL) {
  if (arr[key] == NULL) {

   newNode->next = NULL;
   newNode->prev = NULL;
   arr[key] = newNode;
 }
 else {
} //else{
       struct society_D* temp = arr[key];

       while(temp->next != NULL){


           temp = temp->next;
       }
       temp->next = newNode;
       newNode->prev = temp;
       newNode->next = NULL;

   printf("Node inserted\n");
}

void display_society_D()
{
  int i;

for(i = 0; i < size; i++) {
for (i = 0; i < size; i++) {
    struct society_D *temp = arr[i];
    printf("arr[%d]-->",i);
    while(temp) {
        printf("%d %s %d -->",temp->flat_num, temp->owner_name, temp->owner_contact);
    printf("\tarr[%d]-->",i);
    while (temp) {
        printf("%d %s %d -->",temp->flat_num, temp->owner_name, temp->owner_contact);
        temp = temp->next;
    }
    printf("NULL\n");
}
}
}


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

                                case 1: printf("\n\n\tEnter flat_num : ");
                                        scanf("\t %d", &flat_num);
                                        printf("\n\tEnter owner_nameName : ");
                                        scanf("\t %s", owner_name);
                                        printf("\n\tEnter owner_contact : ");
                                        scanf("\t %d", &owner_contact);
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
                              }
                            }
                            return 0;
};
}
