/* Single Linked List operation*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
};
struct node *root = NULL, *new_node, *temp;
int len, loc;

struct node* list_init();
void list_add();
void addbegin();
void addafter();
int length();
void display_list();
void list_del_ele();
void list_find();

int
main()
{
    int ch;

    while (1) {
      printf("Single linkes list operation:\n\n");
      printf("1.Add Element\n");
      printf("2.Add Begine\n");
      printf("3.Add after\n");
      printf("4.Length of list\n");
      printf("5.Display list\n");
      printf("6.Delete Element\n");
      printf("7.Search Element\n");
      printf("8.Quit\n\n");

      printf("Enter your choice: ");
      scanf("%d", &ch);

      switch (ch) {
        case 1: list_add();
                break;

        case 2: addbegin();
                break;

        case 3: addafter();
                break;

        case 4: len = length();
                printf("length of list : %d\n\n", len);
                printf("--------------------------------------------\n");
                break;

        case 5: display_list();
                break;

        case 6: list_del_ele();
                break;

        case 7: list_find();
                break;

        case 8: exit(1);

        default: printf("wrong choice...\n");

      }
    }
}

// Initializing Node
struct node*
init()
{
  temp = (struct node*)malloc(sizeof(struct node));

  printf("Enter Element: ");
  scanf("%d", &temp->key);
  temp->next = NULL;

  return temp;
}

// Add node at the end of linked list
void
list_add()
{
    new_node = init();

    //inserting first node into list
    if (root == NULL) {  //list is empty
        root = new_node;
        printf("first node is added\n");
    }
    //inserting node to creates list
    else {
        struct node *p;
        p = root;

        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_node;

        printf("Node is added\n");
    }
    printf("--------------------------------------------\n");
}

// Add node after a specific node
void
addafter()
{
    int i = 1;

    new_node = init();

    if (root == NULL) {
        root = new_node;
        printf("first node is added\n");
    }
    else {
        printf("\nEnter location of Node: ");
        scanf("%d", &loc);

        if (loc > length()) {
            printf("Wrong choice...\n\n");
        }
        else {
            struct node *prev_node, *next_node; // nodes before and after the location
            prev_node = root;

            while (i < loc) {
                prev_node = prev_node->next;
                i++;
            }
            next_node = prev_node->next;
            new_node->next = next_node;
            prev_node->next = new_node;
            printf("%d is added after %d\n\n", new_node->key, loc);
        }
    }
    printf("--------------------------------------------\n");
}

// Add node at begining of List
void
addbegin()
{
    new_node = init();

    if (root == NULL) {
        root = new_node;
    }
    else {
        new_node->next = root;
        root = new_node;
    }
    printf("Node is added at begining\n\n");
    printf("--------------------------------------------\n");
}

// length of the List
int
length()
{
    int count = 0;
    temp = root;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Displaying the linked List
void
display_list()
{
    temp = root;

    if (temp == NULL) {
        printf("List is empty\n\n");
    }
    else
    {
        while (temp != NULL) {
            printf("%d-->", temp->key);
            temp = temp->next;
        }
        printf("\n\n");
    }
    printf("--------------------------------------------\n");
}

//Deleting element
void
list_del_ele()
{
    temp = root;

    if (temp == NULL) {
        printf("List is empty\n\n");
    }
    else {
        printf("Enter location of node to delete: ");
        scanf("%d", &loc);
      //  printf("location is %d\n\n", loc);

        if (loc == 1) {
            root = temp->next;  //root link to second Node
            temp->next = NULL;  //remove the link to the next Node
            free(temp);  //release the memory of first Node
            printf("Node at location %d is deleted\n\n", loc);
        }
        else if (loc < length()) {
            struct node *p, *q;
            int i = 1;
            p = root;

            while (i < (loc-1)) {
                p = p->next;
                i++;
            }
            q = p->next;  //pointing to that node which we want to Delete

            p->next = q->next;
            q->next = NULL;
            free(q);
            printf("Node at location %d is deleted\n\n", loc);
        }
        else {
            printf("Enter correct location\n\n");
        }

    }
    printf("--------------------------------------------\n");

}

// Searching a element
void
list_find()
{
    int ele;
    temp = root;

    if (temp == NULL) {
        printf("List is Empty\n\n");
    }
    else {
        printf("Enter element to be searched:");
        scanf("%d", &ele);

        while (temp != NULL) {
            if (temp->key == ele) {

                printf("%d is found\n", ele);
            }
            temp = temp->next;
        }
    }
    printf("--------------------------------------------\n");

}
