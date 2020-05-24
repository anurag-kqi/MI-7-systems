#include<stdio.h>
#include<stdlib.h>

#define HTABSIZE 100;
int size = 0;
int max = HTABSIZE;

struct node
{
  int key;
  int value;
  struct node *next;
};

struct htabitem
{
  struct node *start;
  struct node *end;
};
struct htabitem *htab;

void htab_init();
void htab_insert(int, int);
void htab_delete(int);
void htab_print();
int htab_find(struct node*, int);

void  main()
{
    int choice, key, value, n;

    htab = (struct htabitem*)malloc(max * sizeof(struct htabitem*));
    do{
        printf("\n --------- Hash Table Menu --------- \n");
        printf("\n Please Enter Your Choice : ");
        printf("\n 1. Insert Data in Hash Table.");
        printf("\n 2. Delete Data from Hash Table.") ;
        printf("\n 3. Display Data.");
        printf("\n 4. Exit.");
        scanf("%d", &choice);

        switch(choice)
        {

          case 1 :
            printf("\n Enter key and Value that you want to insert in Hash Table:");
            scanf("%d %d", &key, &value);
            htab_insert(key,value);
            break;
          case 2:
            printf("\n Enter the key which you want to Delete from the Hash Table:");
            scanf("%d", &key);
            htab_delete(key);
            break;
          case 3:
            printf("\n Displaying the contents of Hash Table !");
            htab_print();
            break;
          case 4:
            exit(0);
          default:
            printf("\n Invalid Entry !");
       }
       printf("\n Press 1 to continue ");
       scanf("%d", &n);
    }while(n == 1);
}


int hashtable(int key)
{
  return(key % max);
}

/* Initializing the Hash Table*/
void  htab_init()
{
  int i = 0;
  for( i = 0; i < max; i++)
  {
    htab[i].start = NULL;
    htab[i].end = NULL;
  }
}


/* inserting into Hash table */
void htab_insert(int key,int value)
{
  int index = hashtable(key);

  struct node *list = (struct node*)htab[index].start;

  struct node *item = (struct node*)malloc(sizeof(struct node));
  item->key = key;
  item->value = value;
  item->next = NULL;

  if (list == NULL) {

      htab[index].start = item;
      htab[index].end = item;
      size++;
      printf("\n Inserted key %d and value %d in the list !", key, value);
    }

    else{
    printf("\n Collision occured ! Linked List is present in the given location");
    }
}

/*Find element from the list*/
int htab_find(struct node *list,int key)
{
  int value = 0;
  struct node *temp = list;
  while(temp != NULL)
  {
      if(temp->key == key)
      {
        return value;
      }
      temp = temp->next;
      value++;
  }
  return -1;
}

/* deleting element from Hash Table */
void htab_delete(int key){

    int index = hashtable(key);
    struct node *list = (struct node*)htab[index].start;
    if( list == NULL)
    {
        printf("\n The list is Empty");
    }
    else{

        int find_index = htab_find(list, key);

        if(find_index == -1)
        {
          printf("\n Key does not exist in the list !");
        }
        else
        {
            struct node *temp = list;
            if(temp->key == key)
            {
                htab[index].start = temp->next;
                printf("\n The key has bee deleted from the List !");
            }
            while(temp->next->key != key)
            {
                  temp = temp->next;
            }
            if(htab[index].end == temp->next)
            {
                temp->next = NULL;
                htab[index].end = temp;
            }
            else
            {
                temp->next = temp->next->next;
            }

            printf("\n The key has been removed from the list ");

        }
    }
}




/* To display the content of list */
void htab_print()
{
    int i = 0;
    for(i = 0;i < max;i++)
    {
        struct node *temp = htab[i].start;
        if(temp ==  NULL)
        {
            printf("\n The list at %d is Empty !",i);
        }
        else
        {
            printf("\n The list at %d is not Empty !",i);
            while(temp->next != NULL)
            {
                printf("\n The key is %d and the Value is %d ", temp->key,temp->value);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}
