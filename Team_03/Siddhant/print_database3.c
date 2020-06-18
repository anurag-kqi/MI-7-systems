#include<stdio.h>
#include"database.h"

struct Node *Print_Hash(struct Node *p)
 {	
 	printf("<-");
 	while(p!=NULL)
 	{
 		printf("->{%d,%s,%s,%s,%d,%s,%s,%s}<-",p->BID,p->bName,p->bType,p->oName,p->OID,p->contact,p->bAdd,p->email);
 		if(p->next == NULL)
 		{
 			printf("->NULL");
 		}
 		p = p-> next;

 	}
 	return NULL;
 }

 struct Node *Print_DB(struct Node p){
			printf("\n");
           	static int Sr =1;
           	{
				printf("|%-5d|",Sr);
    			printf("%-14d|",p.BID);
    			printf("%-20s|",p.bName);
      			printf("%-21s|",p.bType);
      			printf("%-20s|",p.oName);
      			printf("%-12s|",p.contact);
      			printf("%-30s|",p.bAdd);
      			printf("%-20s|",p.email);
      			printf("\n");
          		for (int i = 0; i < 143 ;i++){
            		if(i==0||i==5||i==19||i==39||i==60||i==80||i==92||i==122||i==142)
                  		printf("+");
              	printf("-");
   				}
    		} Sr++;
    	return 0;
  }   
