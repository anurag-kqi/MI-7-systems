/* Single Linked List operation*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
struct node *root = NULL;
int len;

void append();
void addbegin();
void addafter();
int length();
void display();
void deletenode();

int
main()
{
    int ch;

    while (1) {
      printf("Single linkes list operation:\n\n");
      printf("1.Append\n");
      printf("1.Add Begine\n");
      printf("3.Add after\n");
      printf("4.Length\n");
      printf("5.Display\n");
      printf("6.Delete\n");
      printf("7.Quit\n\n");

      printf("Enter your choice: ");
      scanf("%d", &ch);
      printf("your choice %d\n\n", ch);

      switch (ch) {
        case 1: append();
                break;

        case 2: addbegin();
                break;

        case 3: addafter();
                break;

        case 4: len = length();
                printf("length of list : %d\n\n", len);
                break;

        case 5: display();
                break;

        case 6: deletenode();
                break;

        case 7: exit(1);

        default: printf("wrong choice...\n");

      }
    }
}

// Add node at the end of linked list
void
append()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter node data: ");
    scanf("%d", &temp->data);
    printf("Node is added\n\n");
    temp->link = NULL;

    //inserting first node into list
    if (root == NULL) {  //list is empty
        root = temp;
    }
    //inserting node to creates list
    else {
        struct node *p;
        p = root;

        while (p->link != NULL) {
            p = p->link;
        }
        p->link = temp;
    }
}

// Add node after a specific node
void
addafter()
{
  /* code */
}

// Add node at begining of List
void
addbegin()
{

}

// length of the List
int
length()
{
    int count = 0;
    struct node *temp;
    temp = root;

    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    return count;
}

// Displaying the linked List
void
display()
{
    struct node *temp;
    temp = root;

    if (temp == NULL) {
        printf("List is empty\n");
    }
    else
    {
        while (temp != NULL) {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}

//Deleting element
void deletenode()
{

}
