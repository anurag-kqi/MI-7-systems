/*perform operations on Singly linked list*/

#include<stdio.h>
#include<stdlib.h>
//#include<process.h>
 
struct node
{
    int data;
    struct node *next;
} *start, *temp, *newNode;
 
int 
main()
{
    int ch;
    void insert_beg();
    void insert_end();
    int insert_pos();
    void display();
    void delete_beg();
    void delete_end();
    int delete_pos();
    void search();

    while(1) {
        printf("\n\n---- Singly Linked List(SLL) Menu ----");
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit\n\n");
        printf("\nEnter your choice(1-4) : ");
        scanf("%d", &ch);
 
        switch(ch) {
            case 1:
                    printf("\n---- Insert Menu ----");
                    printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d", &ch);
 
                    switch(ch)
                    {
                        case 1: insert_beg();
                                break;
                        case 2: insert_end();
                                break;
                        case 3: insert_pos();
                                break;
                        case 4: exit(0);
                        default: printf("Wrong Choice!!");
                    }
                    break;
 
            case 2: display();
                    break;
 
            case 3: printf("\n---- Delete Menu ----");
                    printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from specified position\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);
 
                    switch(ch)
                    {
                        case 1: delete_beg();
                                break;
                        case 2: delete_end();
                                break;
                        case 3: delete_pos();
                                break;
                        case 4: exit(0);
                        default: printf("Wrong Choice!!");
                    }
                    break;

	    case 4: search();
                    break;

            case 5: exit(0);
                    
	    default: printf("Wrong Choice!!");
        }
    }
    return 0;
}
 
void insert_beg()
{
    int num;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &num);
    newNode->data = num;
 
    if(start == NULL) {
        newNode->next = NULL;
        start = newNode;
    }
    else {
        newNode->next = start;
        start = newNode;
    }
}
 
void insert_end()
{
    int num;
    newNode = (struct node*) malloc (sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &num);
    newNode->data = num;
    newNode->next = NULL;
 
    if(start == NULL) {
        start = newNode;
    }
    else {
        temp = start;
        while(temp->next != NULL)
        temp = temp->next;
        temp->next = newNode;
    }
}
 
int insert_pos()
{
    int pos,i,num;
    if(start == NULL) {
        printf("List is empty!!");
        return 0;
    }
 
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &num);
    printf("Enter position to insert:");
    scanf("%d", &pos);
    newNode->data = num;
 
    temp = start;
    for(i=1;i<pos-1;i++) {
        if(temp->next == NULL) {
            printf("There are less elements!!");
            return 0;
        }
 
        temp = temp->next;
    }
 
    newNode->next = temp->next;
    temp->next = newNode;
    return 0;
}
 
void display()
{
    if(start == NULL) {
        printf("List is empty!!");
    }
    else {
        temp = start;
        printf("The linked list is:\n");
        while(temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
}
 
void delete_beg()
{
    if(start == NULL) {
        printf("The list is empty!!");
    }
    else {
        temp = start;
        start = start->next;
        printf("Deleted element is %d", temp->data);
        free(temp);
    }
}
 
void delete_end()
{
    if(start == NULL) {
        printf("The list is empty!!");
    }
    else {
        temp = start;
        while(temp->next->next != NULL)
        temp = temp->next;
 
        newNode = temp->next;
        temp->next = NULL;
        printf("Deleted element is %d", newNode->data);
        free(newNode);
    }
}
 
int delete_pos()
{
    int pos,i;
 
    if(start == NULL) {
        printf("List is empty!!");
        return 0;
    }
 
    printf("Enter position to delete:");
    scanf("%d", &pos);
 
    temp = start;
    for(i=1;i<pos-1;i++) {
        if(temp->next == NULL) {
            printf("There are less elements!!");
            return 0;
        }
        temp = temp->next;
    }
 
    newNode = temp->next;
    temp->next = newNode->next;
    printf("Deleted element is %d", newNode->data);
    free(newNode);
 
    return 0;
}

void search()  
{  
    int num, i=0, flag;  
    temp = start;   
    if(temp == NULL) {  
        printf("\nEmpty List\n");  
    }  
    else {   
        printf("\nEnter Data which you want to search?\n");   
        scanf("%d", &num);  
        while (temp != NULL) {  
            if(temp->data == num) {  
                printf("item found at location %d ", i+1);  
                flag=0;  
            }   
            else {  
                flag=1; 
		
	    }  
            i++;  
            temp = temp -> next;  
        }  
        if(flag==1) {  
          printf("Item not found\n");  
        }  
    }     
          
}  
