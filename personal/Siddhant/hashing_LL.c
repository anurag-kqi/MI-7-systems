#include<stdio.h>
#include<iostream>
#include <stdlib.h>

//structure for linked list
struct Node
{
	int data;
	struct Node *next;
};

// function stores the element in sorted order into linked list
void SortedLinks(struct Node **H, int x)
{
	struct Node *t,*q = NULL, *p= *H;
	t =(struct Node*) malloc (sizeof(struct Node));
	t->data= x;
	t->next = NULL;
	if (*H==NULL) {
		*H = t;
	} else {
		while (p&& p->data<x) {
			q=p;
			p=p->next;
		}
		if (p==*H)	{
			t->next=*H;
			*H=t;
		}	else {
			t->next=q->next;
			q->next = t;
		}
	}
}

// print the hash at asked point
 struct Node *Print(struct Node *p) {
 	while (p!=NULL)	{
 		printf("%d-->",p->data);
 		if(p->next == NULL) {
 			printf("/");
 		}
 		p = p-> next;
 	}
 	return NULL;
 }
 int hash(int key,int size) {
	return key%size;	
}

// Insert element into array
void Insert(struct Node *H[], int key,int size) {
	int index=hash(key,size);
	SortedLinks(&H[index],key);
}

int main()
{	
	int size;
	printf("take the hashtable size:");
	scanf("%d",&size);
	struct Node *HT[size];
	for (int i = 0; i < size; ++i) {
		HT[i]=NULL;
	}
	int n;
	printf("enter number of keys:\n");
	scanf("%d",&n);
	int key[n];
	printf("enter the keys :\n");
	for (int i=0; i<n;i++)	{
		scanf("%d",&key[i]);
		Insert(HT,key[i],size);	
	}
	for (int i = 0; i <size ; i++) {	
	 	printf("%d : ",i);	
	 	Print(HT[i]);
	 	printf("\n");
	 }
    return 0;
}
