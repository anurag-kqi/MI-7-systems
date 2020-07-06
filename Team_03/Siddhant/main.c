#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"database.h"

int hash_at_int(int key,int size)
{
	return key%size;
}

int main() {
  char x;
	int size,n,choice;
	printf("enter size of hash table\n");
	scanf("%d",&size);
	printf("\n");
	printf("enter number of nodes\n");
	scanf("%d",&n);
	struct Node *B = (struct Node *)malloc(n*sizeof(struct Node));
	struct Node **HT = (struct Node**)malloc(size*sizeof(struct Node));

	char *s  = "sr.no";
	char *BI = "Business ID";
	char *BN = "Business Name";
	char *BO = "Business Owner";
	char *BT = "Business Type";
	char *CO = "Contact no.";
	char *CA = "Contact Address";
	char *CE = "Email";


  int Bi = 0;
  int Oi = 0;
  char bN[15] = "";
  char oN[16] = "";
  char bA[31] = "";
  int bT = 0;
  char c[10] = "";
  char e[21] = "";
      
	 
  for(int i = 0; i < size; i++) 
        HT[i] = NULL;
    
  printf("\n\t We have following categories of businesses avaible \n \t 1.Grocery \n \t 2.Jewelery \n \t 3.Provision \n \t 4.Entertainment \n \t 5.Tours and Travels \n \t 6.Clothings \n  ");
  printf("This is business catalogue of surrounding you are given following choices:");
  
  do{
        printf("\nMENU :- \n\t 1.Register your business \n\t 2.Remove a Business or remove any element \n\t 3.Search a Business using Business id \n\t 4.Display entire catalogue \n\n\tplease enter your choice ");
        scanf("%d",&choice);

        switch(choice){
          case 1:{
            printf("Welcome dear \n");
            for(int i = 0; i<n ; i++){
                printf("___________________________________________________________________________________________________\n");
                printf("\t\t--> Enter Business id( 4 digit Integer)\n\t\t-");
                scanf("%d",&Bi);
                B[i].BID=Bi;

                printf("___________________________________________________________________________________________________\n");
                printf("\t\t--> Enter Business Name\n\t\t-");
                scanf("%s",bN);
                strcpy(B[i].bName,bN);
            
                printf("___________________________________________________________________________________________________\n");
                printf("\t\t--> Enter owner Name\n\t\t-");
                scanf("%s",oN);
                strcpy(B[i].oName,oN);
                //B[i].oName=oN;

                printf("___________________________________________________________________________________________________\n");
                printf("\t\t--> Enter owner id(5 Digit Integer)\n\t\t-");
                scanf("%d",&Oi);
                B[i].OID=Oi;

                printf("___________________________________________________________________________________________________\n");
                printf("\t\t--> Enter Business Type(\n\t\tchoose among following Options)\n\n\t\t1.Grocery \n\t\t2.Jewelery \n\t\t3.Provision \n\t\t4.Entertainment \n\t\t5.Tours and Travels \n\t\t6.Clothings\n\t\t-");
                scanf("%d",&bT);
                switch(bT){
                  case 1:
                       strcpy(B[i].bType,"Grocery");
                    break;
                  case 2:
                    strcpy(B[i].bType,"Jewelery");
                    break;
    
                  case 3:
                    strcpy(B[i].bType,"Provision");
                    break;
    
                  case 4:
                    strcpy(B[i].bType,"Entertainment");
                    break;
    
                  case 5:
                    strcpy(B[i].bType,"Tours_and_Travels");
                    break;
    
                  case 6:
                    strcpy(B[i].bType,"Clothings");
                    break;
                  default:
                    strcpy(B[i].bType,"Others");
                    break;
                }

            
            
                printf("___________________________________________________________________________________________________\n");
                printf("\t\t--> Enter Business Address\n\t\t-");
                scanf("%s",bA);
                strcpy(B[i].bAdd,bA);
            
                printf("___________________________________________________________________________________________________\n");
                printf("\t\t--> Enter owner contact( 10 DIGIT Integer )\n\t\t-");
                scanf("%s",c);
                strcpy(B[i].contact,c);

                printf("___________________________________________________________________________________________________\n");
                printf("\t\t--> Enter owner Email\n\t\t-");
                scanf("%s",e);
                strcpy(B[i].email,e);
                Insert_Row(HT,B[i],size);
              printf("\n"); 
            }
          }break;

          case 2:{
          int c;
          printf("select whether you want to remove entire business or remove an entry \n insert '1' for removing entire entry or '2' for removing any element ");
          scanf("%d",&c);
          switch (c){
            case 1:{ 
              int i;
              printf("Enter the Business ID which you want to delete:\t");
              scanf("%d",&i);
              for(int j= 0; j<n ; j++){
                if(B[j].BID==i){
                  int Index= hash_at_int(i,size);
                  delete_BID(&HT[Index],B[j]);
                }break;
              printf("there is no such business with BID : %d",i);
              }
              break;}
            case 2:
              //ask for row to delete from 
              //ask for element to delete
              //delete the item replacing 0;
              break;
            default:
              break;
            } 
          }break;
          
          case 3:{
          int i;
          printf("ENTER THE BUSINESS ID FOR YOUR BUSINESS:\n");
          scanf("%d",&i);
          
              printf("Enter the Business ID which you want to delete:\t");
              scanf("%d",&i);
              printf("\n");
              for(int j= 0; j<n ; j++){
                if(B[j].BID==i){
                  printf("\tBusiness ID: %d\n",B[j].BID);
                  printf("\tBusiness Name: %s\n",B[j].bName);
                  printf("\tOwner Name: %s\n",B[j].oName);
                  printf("\tBusiness Address: %s\n",B[j].bAdd);
                  printf("\tBusiness Type: %s\n",B[j].bType);
                  printf("\tContact no: %s\n",B[j].contact);
                  printf("\tEmail: %s",B[j].email);
                }break;
            printf("there is no such business with BID : %d",i);
          }
          }break;

          case 4:{
          int a;
          printf( "Do you want to look at 1.database table or 2.hash table [1/2]?");
          scanf("%d",&a);
            switch (a){
              case 1:{
                printf("\n\n\t\t\t----DATABASE-TABLE----\n\n");
            // //display database table ;
                for(int i = 0; i<50 ;i++)
                  printf(" ");
                printf( "MI-Batch-2020 (Team_03) business catalogue\n");
    
                for (int i = 0; i < 143 ;i++){
                  if(i==0||i==5||i==19||i==39||i==60||i==80||i==92||i==122||i==142)
                    printf("+");
                  printf("-");
                }
                printf("\n|");
                printf("%-5s|",s);
                printf("%-14s|",BI);
                printf("%-20s|",BN);
                printf("%-21s|",BT);
                printf("%-20s|",BO);
                printf("%-12s|",CO);
                printf("%-30s|",CA);
                printf("%-20s|",CE);
                printf("\n");
                
                for (int i = 0; i < 143 ;i++){
                  if(i==0||i==5||i==19||i==39||i==60||i==80||i==92||i==122||i==142)
                    printf("+");
                  printf("-");
                } 
                
                for(int i = 0; i<n ; i++){  
                  Print_DB(B[i]); 
                }
                printf("\n");
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

          default :
            break;
      }
      printf("Do you want to continue:- [Y/N]?\t");
      scanf("%s",&x);
    }while(x == 'y'|| x== 'Y');
  	
	free(*HT);
	free(B);
	

	return 0;
	 				
}

