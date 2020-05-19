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
      printf("2.Add Begine\n");
      printf("3.Add after\n");
      printf("4.Length\n");
      printf("5.Display\n");
      printf("6.Delete\n");
      printf("7.Quit\n\n");

      printf("Enter your choice: ");
      scanf("%d", &ch);

      switch (ch) {
        case 1: append();
                break;

        case 2: addbegin();
                break;

        case 3: addafter();
                break;

        case 4: len = length();
                printf("length of list : %d\n\n", len);
                printf("--------------------------------------------\n");
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
    temp->link = NULL;

    //inserting first node into list
    if (root == NULL) {  //list is empty
        root = temp;
        printf("first node is added\n");
    }
    //inserting node to creates list
    else {
        struct node *p;
        p = root;

        while (p->link != NULL) {
            p = p->link;
        }
        p->link = temp;

        printf("Node is added\n");
    }
    printf("--------------------------------------------\n");
}

// Add node after a specific node
void
addafter()
{
    int loc, i = 1;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL) {
        root = temp;
        printf("first node is added\n");
    }
    else {
        printf("\nEnter location of Node\n");
        scanf("%d", &loc);
        printf("Node is added after %dth Node\n\n", loc);

        if (loc > length()) {
            printf("Wrong choice...\n\n");
        }
        else {
            struct node *p, *q;
            p = root;

            while (i < loc) {
                p = p->link;
                i++;
            }
            q = p->link;
            temp->link = q;
            p->link = temp;
            printf("%d is added after %d\n\n", temp->data, loc);
        }
    }
    printf("--------------------------------------------\n");
}

// Add node at begining of List
void
addbegin()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter node data\n");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL) {
        root = temp;
    }
    else {
        temp->link = root;
        root = temp;
    }
    printf("Node is added at begining\n\n");
    printf("--------------------------------------------\n");
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
        printf("List is empty\n\n");
    }
    else
    {
        while (temp != NULL) {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
    printf("--------------------------------------------\n");
}

//Deleting element
void
deletenode()
{
    struct node *temp;
    temp = root;

    if (temp == NULL) {
        printf("List is empty\n\n");
    }
    else {
        int loc;
        printf("Enter location of node to delete\n");
        scanf("%d", &loc);
        printf("location is %d\n\n", loc);

        if (loc == 1) {
            root = temp->link;  //root link to second Node
            temp->link = NULL;  //remove the link to the next Node
            free(temp);  //release the memory of first Node
            printf("Node at location %d is deleted\n\n", loc);
        }
        else if (loc < length()) {
            struct node *p, *q;
            int i = 1;
            p = root;

            while (i < (loc-1)) {
                p = p->link;
                i++;
            }
            q = p->link;  //pointing to that node which we want to Delete

            p->link = q->link;
            q->link = NULL;
            free(q);
            printf("Node at location %d is deleted\n\n", loc);
        }
        else {
            printf("Enter correct location\n\n");
        }

    }
    printf("--------------------------------------------\n");

}
