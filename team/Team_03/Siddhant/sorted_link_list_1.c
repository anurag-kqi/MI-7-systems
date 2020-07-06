#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"database.h"
void SortedLinks(struct Node **H, struct Node x) {
	struct Node *t,*q = NULL, *p= *H;
	t =(struct Node*) malloc (sizeof(struct Node));
	t->BID = x.BID;
	t->OID = x.OID;
	strcpy(t->bName,x.bName);
	strcpy(t->oName,x.oName);
	strcpy(t->bAdd,x.bAdd);
	strcpy(t->bType,x.bType);
	strcpy(t->contact,x.contact);
	strcpy(t-> email,x.email);
	;
	t->next = NULL;
	if(*H==NULL)
	{
		t->next = t->prev =NULL;
		*H = t;

	}else{
		while(p&& p->BID<x.BID)
		{
			q=p;
			p=p->next;
		}
		if(p==*H)
		{
			t->prev = p->prev;
			t->next=*H;
			*H=t;
		}else{
			t->next=q->next;
			q->next = t;
			t->prev = q;
		}
	}
}
