#include<stdio.h>
#include<stdlib.h>

typedef struct dnode
{
    int data;
    struct dnode *next,*prev;
}dnode;

    dnode * create();
    void print_for(dnode *);
    void print_rev(dnode *);
    
void
main()
{
    dnode *head,*h,*q;
    //head = NULL;
    head = create();
    printf("\n Elements in forward direction : ");
    print_for(head);
    printf("\n Elements in reverse direction : ");
    print_rev(head);
}

dnode *create()
{
    dnode *h,*P,*q;
    int i,n,x;
    h = NULL;
    printf("\n Enter no. of elements: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        printf("\nEnter data: ");
        scanf("%d",&x);
        q = (dnode*)malloc(sizeof(dnode));
	q->data = x;
	q->prev = q->next = NULL;
	if(h == NULL)
	{
	    h = P = q;
	    
	} else {
	    P->next = q;
	    q->prev = P;
	    P = q;
	}
    }
    return(h);
}

void print_for(dnode *h)
{
    while(h != NULL)
	{
	    printf("%d->",h->data);
	    h = h->next;
	}
}

void print_rev(dnode *h)
{
    while(h->next != NULL)
	h = h->next;
    while(h != NULL)
    {
	printf("%d->",h->data);
	h = h->prev;
    }
}


    

