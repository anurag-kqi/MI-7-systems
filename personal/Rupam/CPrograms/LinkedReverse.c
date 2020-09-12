//Create a singly linked list and print it in reverse order

#include <stdio.h>
#include <stdlib.h>

struct node{
   int num;                    //Data of the node
   struct node *nextptr;       //Address of the node
  }*stnode;

void createNodeList(int n);     //function to create the list
void reverseDispList();         //function to convert the list in reverse
void displayList();             //function to display the list

int 
main()
  {
   int n;
		
   printf("\n\n Linked List : Create a singly linked list and print it in reverse order :\n");
   printf("******************************************************************************\n");

   printf(" Input the number of nodes : ");
   scanf("%d", &n);
	
   createNodeList(n);
   printf("\n Data entered in the list are : \n");
    
   displayList();
   reverseDispList();
   printf("\n The list in reverse are :  \n");
   displayList();
   return 0;
  }

void 
createNodeList(int n)
  {
   struct node *fnNode, *tmp;
   int num, i;
  
   stnode = (struct node *)malloc(sizeof(struct node));
    
   if(stnode == NULL) //check whether the stnode is NULL and if so no memory allocation
   {
     printf(" Memory can not be allocated.");
   }
   else{
     printf(" Input data for node 1 : ");    // reads data for the node through keyboard
     scanf("%d", &num);
 
     stnode-> num = num;
     stnode-> nextptr = NULL; //Links the address field to NULL
     tmp = stnode;

    for(i=2; i<=n; i++)                        // Creates n nodes and adds to linked list
     {
	fnNode = (struct node *)malloc(sizeof(struct node));
        if(fnNode == NULL) //check whether the fnnode is NULL and if so no memory allocation
	  {
	    printf(" Memory can not be allocated.");
            break;
	  }
      else{
            printf(" Input data for node %d : ", i);
	    scanf(" %d", &num);
		
	    fnNode->num = num;      // links the num field of fnNode with num
	    fnNode->nextptr = NULL; // links the address field of fnNode with NULL
	    tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
	    tmp = tmp->nextptr;
	  }
	}
    }
}

void 
reverseDispList()
  {
   struct node *prevNode, *curNode;

   if(stnode != NULL)
    {
	prevNode = stnode;
	curNode = stnode->nextptr;
	stnode = stnode->nextptr;

	prevNode->nextptr = NULL; //convert the first node as last

	while(stnode != NULL)
         {
	    stnode = stnode->nextptr;
	    curNode->nextptr = prevNode;

	    prevNode = curNode;
	    curNode = stnode;
	 }
	stnode = prevNode; //convert the last node as head
    }
}

void
displayList()
   {
    struct node *tmp;
    if(stnode == NULL)
    {
       printf(" No data found in the list.");
    }
    else{
	tmp = stnode;
	while(tmp != NULL)
	 {
	    printf(" Data = %d\n", tmp->num);   // prints the data of current node
	    tmp = tmp->nextptr;                 // advances the position of current node
	}
    }
}

