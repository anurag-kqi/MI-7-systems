//single linklist

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node* create(int);
void display();

void main(){
	int n;
	node *head;
	head = NULL;
	printf("Enter no of elements to store:");
	scanf("%d", &n);
	head = create(n);
	display(head);
}

node *create(int n){
	node *head, *P, *temp;
	int i;
	printf("Enter values for %d nodes:\n", n);
	P = (node*)malloc(sizeof(node));
	scanf("%d", &(P->data));
	P->next = NULL;
	head = P;

	for(i = 1; i<n; i++){
		temp = (node*)malloc(sizeof(node));
		temp->next = NULL;
		scanf("%d", &(temp->data));
		P->next = temp;
		P = P->next;
	}
	return head;
}

void display(node *head){
	node *temp;
	temp = head;
	while(temp!= NULL){
		printf("%d->", temp->data);
		temp = temp->next;
	}
printf("NULL\n");
}
	
