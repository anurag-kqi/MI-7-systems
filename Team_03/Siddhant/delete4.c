#include<stdio.h>
#include<stdlib.h>
#include"database.h"
 void delete_BID(struct Node **H, struct Node key) {
     // Deletes an Business ID from the table
     struct Node *q = NULL, *p= *H;
     if(p != NULL && p->BID == key.BID ){
      *H = p->next;
      free(p);
      return;
     }
     while(p != NULL && p->BID != key.BID){
      q=p;
      p=p->next;
     }
     if ( p == NULL) return;
     q->next = p->next;
     free(p);
  }

