/*program to traversal the singly linked list*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};
void printList(struct node* node)
{
    while (node != NULL) {
      printf(" %d ", node->data);
        node = node->next;
    }
}

int
main()
{
  /* Allocate list_head and initialize next to NULL*/
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    /*allocate memory to node*/
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1; /*assign data to head*/
    head->next = second; /*link head to second node*/

    second->data = 2; /*assign data to second node*/
    second->next = third;

    third->data = 3; /* assign dta to third node*/
    third->next = NULL;
    printList(head);

    return 0;
}
