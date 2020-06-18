#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;

}node;

struct node* root = NULL;
void insert_beg();
void insert_end();
void insert_loc();
void display();
int length();
void del_beg();
void del_end();


int
main()
{
    int ch,nh,len;
    char s,c,n;
    do
    {
        printf("\n********Double Linked List*******\n");
	printf("1.Insert\n2.Display\n3.Delete\n4.Search\n5.Length\n6.Exit\nEnter Your Choice(1-5): ");
	scanf("%d",&ch);
	
	switch(ch)
	{
	    case 1: do
		    {
      		        printf("\n****Insert Options****\n");
		        printf("1.Insert at Begining\n2.Insert by Location\n3.Insert at end\nEnter your choice(1-3): ");
		        scanf("%d",&nh);
			switch(nh)
			{
			    case 1: insert_beg();
				    break;

			    case 2: insert_loc();
				    break;
			    
  			    case 3: insert_end();
				    break;

			    default: printf("\nWrong Choice!\n");  
			}
		    printf("\nDo you want to continue?(y/n) : ");
		    scanf("%s",&s);

		    } while(s == 'y');
	  	    break;
	
	    case 2: display();
		    break;

	    case 3: do
		    {
      		        printf("\n****Delete Options****\n");
		        printf("1.Delete at Begining\n2.Delete by Location\n3.Delete at end\nEnter your choice(1-3): ");
		        scanf("%d",&nh);
			switch(nh)
			{
			    case 1: del_beg();
				    break;

			    /*case 2: del_loc();
				    break;*/
			    
  			    case 3: del_end();
				    break;

			    default: printf("\nWrong Choice!\n");  
			}
		    printf("\nDo you want to continue?(y/n) : ");
		    scanf("%s",&s);

		    } while(s == 'y');
	  	    break;

	    case 5: len = length();
		    printf("Number of nodes in list are %d.",len);
		    break;

	    case 6: exit(0);
	
	    default: printf("\nWrong Choice!\n");    
	}
	printf("\nDo you want to continue with other options?(y/n)");
	scanf("%s",&s);
    } while(s == 'y');
return 0;
}


void insert_beg()
{
    node *head;
    head = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter node to insert: ");
    scanf("%d",&head->data);
    head->next = NULL;
    head->prev = NULL;
    
    if(root == NULL)
    {
	root = head;
    }
    else
    {
	head->next = root;
	root->prev = head;
	root = head;
    }
}

void insert_loc()
{
    node *head,*P;
    int loc,len,i = 1;
    printf("Enter location to add: ");
    scanf("%d",&loc);
    len = length();
    if(loc > len)
    {
	printf("\nInvalid location....");
	printf("\nList contains only %d nodes",len);
    } else if(loc == 1){
        insert_beg();
    } else{
    	head = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter node to insert: ");
        scanf("%d",&head->data);
        head->next = NULL;
        head->prev = NULL;
	P = root;
	while(i < loc-1 && P!=NULL)
	{
	    P = P->next;
	    i++;
	}
	head->prev = P;
	head->next = P->next;
	if(P->next != NULL)
	    P->next->prev = head;
	P->next = head;
    }
}

void insert_end()
{
    node *head,*P;
    head = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter node to insert: ");
    scanf("%d",&head->data);
    head->next = NULL;
    head->prev = NULL;
    
    if(root == NULL)
    {
	printf("\nList is empty");
    } else{
    P = root;
    while(P->next != NULL)
    {
	P = P->next;	        
    }
    P->next = head;
    head->prev = P;  
    head->next = NULL; 
    head = root;
   }
}

void display()
{
    struct node *head;
    head = root;
    if(head == NULL)
    {
        printf("\nList is empty.....\n");
    } else{
        while(head != NULL)
        {
	   printf("%d->",head->data);
	   head = head->next;
	}
    }
     
}

void del_beg()
{
    node *head;
    if(root == NULL)
    {
	printf("\nList is empty");
    } else if(root->next == NULL){
        root = NULL;
	free(root);
	printf("\n Node is deleted.....");
    } else{
        head = root;
	root = root->next;
	root->prev = NULL;
	free(head);
    }
    printf("\n First node is deleted.....");
}

void del_end()
{
    node *P,*head;
    
    if(root == NULL)
    {
	printf("\nList is empty");
    } else if(root->next == NULL){
        root = NULL;
	free(root);
	printf("\n Node is deleted.....");
    } else{
        P = root;
	while(P->next != NULL)
	{
	    
	    P = P->next; 
	    P->prev->next = NULL;   
	}
	
	free(P);
	printf("\n Last node is deleted.....");
    }

}

int length()
{
    struct node *head;
    int count = 0;
    head = root;
    if(head == NULL)
    {
        printf("\nList is empty.....\n");
    } else{
        while(head != NULL)
        {
	   count++;
	   head = head->next;
	}
    }
  return count;   
}
