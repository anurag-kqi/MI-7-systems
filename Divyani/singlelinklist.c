/*Operation perform using singly linked list*/

#include <stdlib.h>
#include <stdio.h>
     
struct node
{
    int info;
    struct node *next;
};

void create();
void list_display();
void insert_begin();
void insert_end();
void delete_begin();
void delete_end();
 
struct node *start = NULL;

int 
main()     
{
        int choice;
        
        while (1) {
               
           
                printf("\n 1.Create \n");
                printf("\n 2.List_Display \n");
                printf("\n 3.Insert at the beginning  \n");
                printf("\n 4.Insert at the end  \n");
                printf("\n 5.Delete from beginning  \n");
                printf("\n 6.Delete from the end   \n");
                printf("\n 7.Exit   \n");
                printf("\n Enter your choice:- \n");
                scanf("%d", &choice);
                
                switch (choice)
                {
                        case 1:       create();
                                      break;
                                        
                        case 2:       list_display();
                                      break;
                                        
                        case 3:       insert_begin();
                                      break;
                                        
                        case 4:       insert_end();
                                      break;
                                        
                        case 5:       delete_begin();
                                      break;
                                        
                        case 6:       delete_end();
                                      break;
                                        
                        case 7:       exit(0);
                                      break;
                             
                        default:      printf("\n Wrong Choice:- \n");
                                      break;
                }
        }
        return 0;
}

void create()
{
        struct node *temp, *ptr;
        temp = (struct node *)malloc(sizeof(struct node));
        
        if (temp == NULL) {
        
                printf("\n Out of Memory Space:- \n");
                exit(0);
        }
        
        printf("\n Enter the data value for the node:- \n");
        scanf("%d", &temp->info);
        temp->next = NULL;
        
        if (start == NULL) {
        
                start=temp;
                
        } else {
                   ptr=start;
                   while (ptr->next != NULL) {
                        ptr = ptr->next;
                } 
                
                ptr->next = temp;
        }
}

void list_display()
{
        struct node *ptr;
        
        if (start == NULL) {
               
                printf("\n List is empty:- \n");
                return;
                
        } else {
                  ptr=start;
                  printf("\n The List elements are:- \n");
                  while (ptr != NULL) {
                        printf("%d\n", ptr->info );
                        ptr = ptr->next ;
                }
        }
}

void insert_begin()
{
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        
        if (temp == NULL) {
                
                printf("\n Out of Memory Space:-\n");
                return;
        }
        
        printf("\n Enter the data value for the node:- \n" );
        scanf("%d", &temp->info);
        temp->next = NULL;
        
        if (start == NULL) {
                
                start=temp;
                
        } else { 
        
                temp->next = start;
                start=temp;
        }
}

void insert_end()
{
        struct node *temp,*ptr;
        temp = (struct node *)malloc(sizeof(struct node));
        
        if (temp == NULL) {
        
                printf("\n Out of Memory Space:- \n");
                return;
        }
        
        printf("\nEnter the data value for the node:\n" );
        scanf("%d", &temp->info );
        temp->next = NULL;
     
        if (start == NULL) {
                
                start=temp;
                
        } else {
               
                ptr=start;
                while (ptr->next != NULL) {
                        ptr = ptr->next ;
                }
                
                ptr->next = temp;
        }
}

void delete_begin()
{
        struct node *ptr;
        
        if (start == NULL) {
        
                printf("\n List is Empty:- \n");
                return;
                
        } else {
               
                ptr=start;
                start = start->next ;
                printf("nThe deleted element is :%d\n", ptr->info);
                free(ptr);
        }
}

void delete_end()
{
        struct node *temp,*ptr;
        
        if (start == NULL) {
                printf("\n List is Empty:- \n");
                exit(0);
                 
        }  else if (start->next == NULL) {
                ptr=start;
                start=NULL;
                printf("\n The deleted element is:%d\n", ptr->info);
                free(ptr);
                
        }   else {
                ptr=start;
                while (ptr->next != NULL) {
                        temp=ptr;
                        ptr = ptr->next;
                }
                temp->next = NULL;
                printf("\n The deleted element is:%d\n", ptr->info);
                free(ptr);
        }
}

