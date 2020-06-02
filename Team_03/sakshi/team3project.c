#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>


/*structure of every node in linked list*/
struct Node_at{
	struct Node_at *prev;
	int BID;
	int OID;
	char bName[15];
	char oName[16];
	char bAdd[31];
	char bType[13];
	char contact[10];
	char email[21];
};

/*single node for linked list made out of attributes*/
struct Node{
	struct Node * prev;
	struct Node_at value;
	struct Node* next;
};

void SortedLinks(struct Node **H, struct Node_at x)
{
	struct Node *t,*q = NULL, *p= *H;
	t =(struct Node*) malloc (sizeof(struct Node));
	t->value= x;
	t->next = NULL;
	if(*H==NULL)
	{
		t->next = t->prev =NULL;
		*H = t;
	}else{
		while(p&& p->value.BID<x.BID)
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
int hash_at_int(int key,int size)
{
	return key%size;
}

void Insert_Row(struct Node *H[], struct Node_at key , int size)
{	
	int c;
	int Index= hash_at_int(key.BID,size);
	printf("insert name of Business: \n");
	scanf("%s",key.bName);
	printf("insert owner name:\n");
	scanf("%s",key.oName);
	printf("insert owner's ID :\n");
	scanf("%d",&key.OID);
	printf("insert business type:\n");
	scanf("%s",key.bType);
	printf("insert business Address\n");
	scanf("%s",key.bAdd);
	printf("insert contact number:\n");
	scanf("%s",key.contact);
	printf("do you have email \n \t press 1 for yes press 0 for no? :");
	scanf("%d",&c);
	switch (c){
		case 1:
			printf("enter email:\n");
			scanf("%s",key.email);
			break;
		case 0:
			printf("ok no worries\n");
			break;
		default:
			break;
	}
	SortedLinks(&H[Index],key);
}

struct Node *Print_Hash(struct Node *p)
 {
 	while(p!=NULL)
 	{
 		printf("%d,%s,%s,%s,%d,%s,%s,%s}-->",p->value.BID,p->value.bName,p->value.bType,p->value.oName,p->value.OID,p->value.contact,p->value.bAdd,p->value.email);
 		if(p->next == NULL)
 		{
 			printf("NULL");
 		}
 		p = p-> next;

 	}
 	return NULL;
 }

  struct Node *Print_DB(struct Node *p){
	
              printf("\n");
           int Sr =1;
           while(p!=NULL){
   			printf("Sr");
            printf("p->value.BID");
            printf("p->value.bName");
        	printf("p->value.bType");
        	printf("p->value.oName");
        	printf("p->value.contact");
            printf("p->value.bAdd");
            printf("p->value.email");
          	for (int i = 0; i < 137 ;i++){
              	if(i==0||i==5||i==19||i==39||i==54||i==74||i==86||i==116||i==136)
                  		printf("+");
              	printf("-");
              	printf("\n");
   				if(p->next == NULL)
 			    	{
  				printf("\n");
   					}
   				p = p-> next;
  				printf("\n");
   				}
    		}
    	return 0;
  }    

int main()
{	char x;
	int choice;
	int size,n;
	printf("take the hashtable size:");
	scanf("%d",&size);
	struct Node **HT= (struct Node**)malloc(size*sizeof(struct Node));
	for (int i = 0; i < size; ++i)
	{
		HT[i]=0;
	}
	printf("enter  no. of nodes: \n");
	scanf("%d",&n);
	struct Node_at *key= (struct Node_at*)malloc(size*sizeof(struct Node_at));
	
	do{	
		printf("This is business catalogue of surrounding you are given following choices:");
		printf("\nMENU :- \n 1.Register your business \n 2.Remove a Business or remove any element \n 3.Check number of businesses \n 4.Display entire catalogue \n \n please enter your choice ");

		scanf("%d",&choice);

		switch(choice){
			case 1:
				printf("Welcome dear \n \t We have following categories of businesses avaible \n \t 1.Grocery \n \t 2.Jewelery \n \t 3.Provision \n \t 4.Entertainment \n \t 5.Tours and Travels \n \t 6.Clothings \n  Enter your BID ");
				for(int i = 0;i<n;i++){
					scanf("%d",&key[i].BID);
					Insert_Row(HT,key[i],size);
					//main();
					printf("\n");	
				}
				break;

			case 2:{
				int c;
				printf("select whether you want to remove entire business or remove an entry \n insert '1' for removing entire entry or '2' for removing any element ");
				scanf("%d",&c);
				switch (c){
					case 1:
						//remove_row();
						break;
					case 2:
						//ask for row to delete from 
						//ask for element to delete
						//delete the item replacing 0;
						break;
					// default:
					// 	break;
				}}

			case 3:{
				printf("total businesses in Town is:\n");//<< length();
				break;
			}
			case 4:{
				int a;
				printf( "Do you want to look at 1.database table or 2.hash table [1/2]?");
				scanf("%d",&a);
				switch (a){
					
					case 1:{
						// //display database table ;
						 printf(" MI-Batch-2020 (Team_03) business catalogue");
						 for(int i =0; i<137;i++){
         				if(i==0||i==5||i==19||i==39||i==54||i==74||i==86||i==116||i==136)
                					printf("+");
             				printf("-");
         				}
         				printf("\n");
   				

    					printf("Sr.no");
    					printf("Business ID");
    					printf("Business Name");
      				    printf("Business Type");
      				    printf("Business Owner");
      				    printf("Contact no.");
      				    printf("Business Address");
      				    printf("Business Email");
      				    printf("\n");
        				for (int i = 0; i < 137 ;i++){
             				if(i==0||i==5||i==19||i==39||i==54||i==74||i==86||i==116||i==136)
                 						printf("+");
             				printf("-");
        					}	
						 for(int i = 0; i <size ; i++){	
	 						
	 					Print_DB(HT[i]);
	 				 		printf("\n");
   				
	 				 		for(int i = 0; i < 137 ;i++){
                  		if(i==0||i==5||i==19||i==39||i==54||i==74||i==86||i==116||i==136)
                					printf("+");
            				printf("-");
        					}
         					printf("\n");
   			
		 				 	}
						break;
					}
					case 2:{
						//display Hash table;
						for(int i = 0; i <size ; i++){	
	 						printf("%d : ",i);	
	 						Print_Hash(HT[i]);
	 						printf("\n");
	 					}
						break;
					}
					default:
						break;
				}
			}
		
			default:
				break;

		}
		printf("Do you want to continue:- [Y/N]?\t");
		scanf("%c",&x);
	} while (x=='Y'||x=='y');
	//free(*HT);
	//free(key);
	return 0;
}

