#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;

};
struct node* head;
void Add(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Display()
{
    struct node* temp = head;
    printf("linked list is:");
    while(temp != NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");

}

int main()
{
    head = NULL;
    printf("Ensert no. of element:");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the element:");
        scanf("%d",&x);
        Add(x);
        Display();

    }
    return(0);
}
