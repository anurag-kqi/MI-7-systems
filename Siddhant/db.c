#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h> 


typedef struct element {
	int BID;
	int OID;
	char bName[15];
	char oName[16];
	char bAdd[31];
	char bType[13];
	char contact[10];
	char email[21];
} element;

typedef struct Node {

	element value;
	struct Node *prev;
	struct Node *next;
} Node;


void SortedLinks(struct Node **H, element x) {
	struct Node *t,*q = NULL, *p= *H;
	t =(struct Node *) malloc (sizeof(Node));
	t->value.BID = x.BID;
	t->value.OID = x.OID;
	strcpy(t->value.bName, x.bName);
	strcpy(t->value.oName, x.oName);
	strcpy(t->value.bAdd, x.bAdd);
	strcpy(t->value.bType, x.bType);
	strcpy(t->value.contact, x.contact);
	strcpy(t->value.email, x.email);
	t->next = NULL;
	if(*H==NULL) {
		t->next = t->prev =NULL;
		*H = t;

	} else {
		while(p&& p->value.BID<x.BID) {
			q=p;
			p=p->next;
		}
		if(p == *H) {
			t -> prev = p -> prev;
			t -> next = *H;
			*H=t;
		} else {
			t -> next = q -> next;
			q -> next = t;
			t -> prev = q;
		}
	}
}

int hash_at_int(int key,int size) {
	return key%size;
}

void Insert_Row(struct Node *H[], element key , int size) {	
	int c;
	int Index= hash_at_int(key.BID,size);
	SortedLinks(&H[Index],key);
}

struct Node *Print_Hash(struct Node *p) {	
 	printf("<-");
 	while(p!=NULL)
 	{
 		printf("->{%d,%s,%s,%s,%d,%s,%s,%s}<-",p->value.BID,p->value.bName,p->value.bType,p->value.oName,p->value.OID,p->value.contact,p->value.bAdd,p->value.email);
 		if(p->next == NULL)
 		{
 			printf("->NULL");
 		}
 		p = p-> next;

 	}
 	return NULL;
 }

 struct Node *Print_DB(struct Node p) {
			printf("\n");
           	static int Sr =1;
           	{
				printf("|%-5d|",Sr);
    			printf("%-14d|",p.value.BID);
    			printf("%-20s|",p.value.bName);
      			printf("%-21s|",p.value.bType);
      			printf("%-20s|",p.value.oName);
      			printf("%-12s|",p.value.contact);
      			printf("%-30s|",p.value.bAdd);
      			printf("%-20s|",p.value.email);
      			printf("\n");
          		for (int i = 0; i < 143 ;i++){
            		if(i==0||i==5||i==19||i==39||i==60||i==80||i==92||i==122||i==142)
                  		printf("+");
              	printf("-");
   				}
    		} Sr++;
    	return 0;
  }   

void delete_BID(struct Node **H, element key) {
     // Deletes an Business ID from the table
     struct Node *q = NULL, *p= *H;
     if( p == NULL) {
     	printf("node is not present");
     } else if( p->value.BID == key.BID ) {
     *H = p->next;
     //*H -> prev = NULL;
      p -> next = NULL;
      free(p);
      printf("node deleted");
      return;
     } else {	
    	while( p->next != NULL ) {
    		if( p->value.BID == key.BID ) {
    			q=p;
    			if( q->next == NULL) {
    				p ->next = NULL;
    				free(q);
    				printf("node deleted");
    				return;
    			} else {
    				p->next = q->next;
    				q->next->prev = q->prev;
    				free(q);
    				printf("node is deleted");

    			}
    		}
      		
      		p=p->next;
     	}
    }
    free(p);
  }

 
void input(element B,struct Node **H,int size) {
	int n = sizeof(struct Node);
	//unsigned char *buffer=(char*)malloc(n);
   	int fd1 = open("Input.txt",O_APPEND| O_RDWR,0666);
  	int Bi = 0;
    int Oi = 0;
    char bN[15]="";
    char oN[16]="";
    char bA[31]="";
    int bT = 0;
    char c[10] = "";
    char e[21] = "";

			printf("___________________________________________________________________________________________________\n");
            printf("\t\t--> Enter Business id( 4 digit Integer)\n\t\t-");
            scanf("%d",&Bi);
            B.BID=Bi;

            printf("___________________________________________________________________________________________________\n");
            printf("\t\t--> Enter Business Name\n\t\t-");
            scanf("%s",bN);
            strcpy(B.bName,bN);
            
            printf("___________________________________________________________________________________________________\n");
            printf("\t\t--> Enter owner Name\n\t\t-");
            scanf("%s",oN);
            strcpy(B.oName,oN);
                
            printf("___________________________________________________________________________________________________\n");
            printf("\t\t--> Enter owner id(5 Digit Integer)\n\t\t-");
            scanf("%d",&Oi);
            B.OID=Oi;

            printf("___________________________________________________________________________________________________\n");
            printf("\t\t--> Enter Business Type(\n\t\tchoose among following Options)\n\n\t\t1.Grocery \n\t\t2.Jewelery \n\t\t3.Provision \n\t\t4.Entertainment \n\t\t5.Tours and Travels \n\t\t6.Clothings\n\t\t-");
            scanf("%d",&bT);
            switch(bT){
              case 1:
                   strcpy(B.bType,"Grocery");
                break;
              case 2:
                strcpy(B.bType,"Jewelery");
                break;

              case 3:
                strcpy(B.bType,"Provision");
                break;
    
              case 4:
                strcpy(B.bType,"Entertainment");
                break;
    
              case 5:
               strcpy(B.bType,"Tours_and_Travels");
                break;
    
              case 6:
                strcpy(B.bType,"Clothings");
                break;
              default:
                strcpy(B.bType,"Others");
                break;
            }

            
            
            printf("___________________________________________________________________________________________________\n");
            printf("\t\t--> Enter Business Address\n\t\t-");
            scanf("%s",bA);
            strcpy(B.bAdd,bA);
            
            printf("___________________________________________________________________________________________________\n");
            printf("\t\t--> Enter owner contact( 10 DIGIT Integer )\n\t\t-");
            scanf("%s",c);
            strcpy(B.contact,c);

            printf("___________________________________________________________________________________________________\n");
            printf("\t\t--> Enter owner Email\n\t\t-");
            scanf("%s",e);
            strcpy(B.email,e);

            //memcpy(buffer, &B, sizeof(struct Node));
        	//memcpy(buffer,(const unsigned char*)&B,n);
			//printf("%s",&B);
            int count = write(fd1, &B, sizeof(struct Node));
            if (count < 0) {
       			perror("write failed");
       			exit(1);
   			} else {
       			fprintf(stderr, "wrote %d bytes\n", count);
  			}
            Insert_Row(H, B, size);
            //free(buffer);
            //memcpy(&copy_data, buffer, sizeof(struct Node));
            printf("\n"); 
}

int main() {
  	char x;
	int size,choice;
  	//static int n=1;
	printf("enter size of hash table\n");
	scanf("%d",&size);
	printf("\n");
	element B;
    struct Node **HT = (struct Node**)malloc(size*sizeof(struct Node));
    
    int n = sizeof(struct Node);
    
   	struct Node copy_data;

  	char *s  = "sr.no";
 	char *BI = "Business ID";
  	char *BN = "Business Name";
  	char *BO = "Business Owner";
  	char *BT = "Business Type";
  	char *CO = "Contact no.";
  	char *CA = "Contact Address";
  	char *CE = "Email";

      
 	 /*initialize hash*/ 
    for(int i = 0; i < size; i++) 
        HT[i] = NULL;
    
    printf("\n\t We have following categories of businesses avaible \n \t 1.Grocery \n \t 2.Jewelery \n \t 3.Provision \n \t 4.Entertainment \n \t 5.Tours and Travels \n \t 6.Clothings \n  ");
    printf("This is business catalogue of surrounding you are given following choices:");
  
    while(1) {

        printf("\nMENU :- \n\t 1. Register your business \n\t 2. Remove a Business or remove any element \n\t 3. Search a Business using Business id \n\t 4. Display entire catalogue \n\t 5. Exit\n\n\tplease enter your choice ");
        scanf("%d",&choice);

        switch(choice) {
          case 1: {
            input(B,HT,size);
          } break;

          case 2:{
          // int c;
          // printf("select whether you want to remove entire business or remove an entry \n insert '1' for removing entire entry or '2' for removing any element ");
          // scanf("%d",&c);
          // switch (c){
          //   case 1:{ 
          //     int i;
          //     printf("Enter the Business ID which you want to delete:\t");
          //     scanf("%d",&i);
          //     for(int j= 0; j<n ; j++) {
          //       if(B[j].BID==i) {
          //         int Index= hash_at_int(i,size);
          //         delete_BID(&HT[Index],B[j]);
          //       } break;
          //     printf("there is no such business with BID : %d",i);
          //     }
          //       break;}
          //     case 2:
          //     //ask for row to delete from 
          //     //ask for element to delete
          //     //delete the item replacing 0;
          //     break;
          //   default:
          //     break;
          //   } 
          }break;
          
          case 3:{
          // int i;
          // printf("ENTER THE BUSINESS ID FOR YOUR BUSINESS:\n");
          // scanf("%d",&i);
          
          //     printf("Enter the Business ID which you want to delete:\t");
          //     scanf("%d",&i);
          //     printf("\n");
          //     for(int j= 0; j<n ; j++){
          //       if(B[j].BID==i){
          //         printf("\tBusiness ID: %d\n",B[j].BID);
          //         printf("\tBusiness Name: %s\n",B[j].bName);
          //         printf("\tOwner Name: %s\n",B[j].oName);
          //         printf("\tBusiness Address: %s\n",B[j].bAdd);
          //         printf("\tBusiness Type: %s\n",B[j].bType);
          //         printf("\tContact no: %s\n",B[j].contact);
          //         printf("\tEmail: %s",B[j].email);
          //       }break;
          //   printf("there is no such business with BID : %d",i);
          // }
          }break;

          case 4:{
          int a;
          printf( "Do you want to look at 1.database table or 2.hash table [1/2]?");
          scanf("%d",&a);
            switch (a){
              case 1:{
            //     printf("\n\n\t\t\t----DATABASE-TABLE----\n\n");
            // // //display database table ;
            //     for(int i = 0; i<50 ;i++)
            //       printf(" ");
            //     printf( "MI-Batch-2020 (Team_03) business catalogue\n");
    
            //     for (int i = 0; i < 143 ;i++){
            //       if(i==0||i==5||i==19||i==39||i==60||i==80||i==92||i==122||i==142)
            //         printf("+");
            //       printf("-");
            //     }
            //     printf("\n|");
            //     printf("%-5s|",s);
            //     printf("%-14s|",BI);
            //     printf("%-20s|",BN);
            //     printf("%-21s|",BT);
            //     printf("%-20s|",BO);
            //     printf("%-12s|",CO);
            //     printf("%-30s|",CA);
            //     printf("%-20s|",CE);
            //     printf("\n");
                
            //     for (int i = 0; i < 143 ;i++){
            //       if(i==0||i==5||i==19||i==39||i==60||i==80||i==92||i==122||i==142)
            //         printf("+");
            //       printf("-");
            //     } 
                
            //     for(int i = 0; i<n ; i++){  
            //       Print_DB(B[i]); 
            //     }
            //     printf("\n");
              }break;

              case 2:{
                int a;
                printf( "Do you want to look at 1.database table or 2.hash table [1/2]?\n");
    
                //display Hash table;
                printf("\n\n\t\t\t----HASH-TABLE----\n\n");
                for(int i = 0; i <size ; i++){  
                  printf("%d : ",i);  
                  Print_Hash(HT[i]);
                  printf("\n");
                }
              }break;
            }
          }break;
			
		  case 5: 
		  		exit(0);
		  		
          default :
            break;
      }
    }
  	

	  free(*HT);
	  return 0;
	 				
}