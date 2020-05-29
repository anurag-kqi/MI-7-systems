#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct node
{
    struct node *prev;
    int n;
    int key;
    int value;
    struct node *next;
}*h,*temp;

void insert1();
void create();
void display();
int count = 0;
int size = 0;
int key, value;
int main()
{
    int ch;

    h = NULL;
    temp = NULL;

    printf("\n 1 - Insert at beginning");
    printf("\n 2 - Display from beginning");
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert1();
            break;
        case 2:
            display();
            break;
            default:
            printf("\n Wrong choice menu");
        }
    }
    return 0;
}

void create()
{

    int data;

    temp =(struct node *)malloc(1*sizeof(struct node));
    //temp->key = key;
    //temp->value = value;
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter value to node : ");
    scanf("%d", &data);
    temp->n = data;
    count++;
}

/*  TO insert at beginning */
void insert1()
{
  key = value % size;
    if (h == NULL)
    {
        create();

        h = temp;
        temp = h;
      }
  else
  {
      create();

      temp->next = h;
      h->prev = temp;
      h = temp;
      temp->key = key;
      temp->value = value;

  }

}
void display()
{
    temp = h;



    if (temp == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("\n Linked list elements from begining : ");

    while (temp->next != NULL)
    {
        printf(" %d ", temp->n);
        temp = temp->next;
    }
    printf(" %d ", temp->n);
}
