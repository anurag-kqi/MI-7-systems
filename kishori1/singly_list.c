/*program to traversal the singly linked list*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList()
{
    struct node *ptr = head;
    printf("\n[head] =>");

    while(ptr != NULL) {
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }
    printf(" [null]\n");
}

/*insert data at the first location*/
void insert(int data)
{
  /*allocate memory*/
    struct node *link = (struct node*) malloc(sizeof(struct node));

   //link->key = key;
    link->data = data;
    link->next = head;
    head = link;
}

int
main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);

    printList();
    
    return 0;
}
