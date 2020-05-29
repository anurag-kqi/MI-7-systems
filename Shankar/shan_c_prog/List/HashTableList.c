#include<stdio.h>
#include<stdlib.h>

#define size 9

struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];

/*int hashCode(int key) {
   return key % SIZE;
}*/

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    //create a newnode with value
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty
    if(chain[key] == NULL) {
        chain[key] = newNode;
    }
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void display()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int delete(int value)
{
    int key = value % size;
    struct node *temp = chain[key], *dealloc;
    if(temp != NULL)
    {
        if(temp->data == value)
        {
            dealloc = temp;
            temp = temp->next;
            free(dealloc);
            return 1;
        }
        else
        {
            while(temp->next)
            {
                if(temp->next->data == value)
                {
                    dealloc = temp->next;
                    temp->next = temp->next->next;
                    free(dealloc);
                    return 1;
                }
                temp = temp->next;
            }
        }
    }

    return 0;
}

void search(int value)  
{  
    int key = value % size;
    struct node *temp = chain[key];
    
    int flag;  
    if(temp == NULL) {  
        printf("\nEmpty List\n");  
    }  
    else {     
        while (temp != NULL) {  
            if(temp->data == value) {  
                //printf("element %d is found...", value);  
                flag=0;  
            }   
            else {  
                flag=1; 
		
	    }    
            temp = temp -> next;  
        }  
        if(flag==1) {  
          printf("element %d is not found...\n", value);  
        }
	else {
	    printf("element %d is found...", value);
	}  
    }     
          
}

int main()
{
    int ch, num;

    //init array of list to NULL
    init();
    while(1) {

        printf("\n\n---- Hash Table with List(SLL) Menu ----");
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit\n\n");
        printf("\nEnter your choice(1-4) : ");
        scanf("%d", &ch);

        switch(ch) {

    	    case 1 : printf("\nEnter The Data to inserts : ");
                     scanf("%d",&num);
                     insert(num); 
		     break;
            case 2 : display();
	             break;
            case 3 : printf("\nEnter The Data to Delete : ");
                     scanf("%d",&num);
                     delete(num); 
		     break;
            case 4 : printf("\nEnter The Data for search : ");
                     scanf("%d",&num);
		     search(num);
	             break;
	    default : exit(0);
                      break;
        }
    }
    return 0;
}
