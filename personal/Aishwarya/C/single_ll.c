#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next; 

}node;

node *create(int);
void print(node *);
int count(node *);

void main()
{
  node *HEAD;
  int n,num;
  printf("\nEnter no. of items: ");
  scanf("%d",&n);
  HEAD = create(n);
  printf("Printing elements....\n");
  print(HEAD);
  num = count(HEAD);
  printf("\n No of nodes = %d",num);
}

node *create(int n)
{
 node *HEAD,*P;
 int i;
 HEAD = (node*)malloc(sizeof(node));
 HEAD->next = NULL;
 scanf("%d",&(HEAD->data));
 P = HEAD;
 for(i=1;i<n;i++)
 {
   P->next = (node*)malloc(sizeof(node));
   P = P->next;
   scanf("%d",&(P->data));
   P->next = NULL;
 }
 return(HEAD);
}

void print(node *P)
{
  while(P!=NULL)
  {
    printf("%d->",P->data);
    P = P->next;
  }
}

int count(node *P)
{
  int i=0;
  while(P!=NULL)
  {
    P=P->next;
    i++;
  }
  return(i);
}

