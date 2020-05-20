#include<stdio.h>
#include<stdlib.h>
//#include<allocc.h>

struct node
{
	int data;
	struct node *next;

};
struct node *head = NULL, *newnode , *temp;

void insert_list_in_beg();
void insert_list_in_end();
void delete_list_from_beg();
void delete_list_from_end();
void display_list();
void search_list();

int 
main() 
{ 

	int choice;
	while(1) {
	
		printf("\n ------------ SINGLY LINKED LIST OPERATION ------------");
		printf("\n 1. INSERT \n 2. DELETE \n 3. SEARCH \n 4. DISPLAY \n 5. EXIT ");
		printf("\n Eter your choice : ");
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1 :
				printf("\n ~~~ Select Insertion Position ~~~ ");
				printf("\n 1. Inserting Node in the Beginning. \n 2. Inserting Node in the End. ");
				scanf("%d",&choice);
				
				switch(choice){
					
					case 1: insert_list_in_beg();
						break;
						
					case 2: insert_list_in_end();
						break;
						
					default: 
						printf("\n Invalid entry :");
					}
				break;
				
			case 2 :
			
				printf("\n ~~~ Select Deletion Position ~~~ ");
				printf("\n 1. Delete from Beginning. \n 2. Delete from End. ");
				scanf("%d" , &choice);
				
					switch(choice){
					
					case 1: delete_list_from_beg();
						break;
						
					case 2: delete_list_from_end();
						break;
						
					default: 
						printf("\n Invalid entry :");
					}
				break;
			
			case 3 :
			
				search_list();
				break;
				
			case 4 :
				
				display_list();
				break;
				
			case 5 :
			
				exit(0);
				
			default:
				
				printf("\n Invalid Entry !");
			}
		}
		
		return 0;
	}
	
void 
insert_list_in_beg() {
	
	newnode = (struct node *)malloc(sizeof(struct node));
	
	printf("\n Enter your Data : ");
	scanf("%d",&newnode -> data);
	
	if(head == NULL)
		head = temp = newnode;
				
	else {
		temp -> next = newnode;
		temp = newnode;
	}
}

void 
insert_list_in_end() {

	newnode = (struct node *)malloc(sizeof(struct node));
	
	printf("\n Enter your Data : ");
	scanf("%d",&newnode -> data);
	newnode -> next = NULL;
	
	if(head == NULL)
		head = temp = newnode;
	
	else{
		
		while(temp -> next != NULL)
			temp = temp -> next;
		
		temp -> next = newnode;
	}
}

void 
delete_list_from_beg() {

	if(head == NULL)
		printf("\n THE LIST IS EMPTY !");
	
	else {
	
		temp = head;
		head = head -> next;
		printf("\n Deleted element is %d" , temp -> data);
		free(temp);
	}
}

void 
delete_list_from_end() {

	 if(head == NULL)
		printf("\n THE LIST IS EMPTY !");
	
	else {
	
		temp = head;
		while(temp -> next != NULL)
			temp = temp -> next;
		
		newnode = temp -> next;
		temp -> next = NULL;
		printf("\n The deleted element is %d", newnode -> data);
		free(newnode);
	}
}

void 
display_list() {

	if( head == NULL)
		printf("\n LIST IS EMPTY !");
		
	else {
	
		temp == head;
		printf("\n The Linked List is :");
		while (temp -> next != NULL){
		
			printf(" %d  ", temp -> data);
			temp = temp -> next;
		}
	}
}

void 
search_list() {

	int i = 0, num, flag;
	temp = head;
	if( head == NULL)
		printf("\n THE LIST IS EMPTY !");
	
	else {
	
		printf("\n Enter the data which you wnt to search from list : ");
		scanf("%d", &num);
		while( temp -> next != NULL) {
		
			if(temp -> next == num){
				printf("\n The data %d is present at location %d ", num, i+1);
				flag = 0;
			}
			
			else
				flag = 1;
			
			i++;
			temp = temp -> next;
		}
		
		if(flag == 1)
			printf("\n Item is not present in the list !");
	}
}
	

	
	
	
	
	
	
	
			
