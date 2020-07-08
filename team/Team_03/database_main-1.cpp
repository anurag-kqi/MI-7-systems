#include<iostream>
#include<iomanip>

using namespace std;


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
	char email[21]="0";
	struct Node_at *next;
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
	}
	else{
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
		}
		else{

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
	cout<<"insert name of Business: ";
	cin>>key.bName;
	cout<<"insert owner name:";
	cin>>key.oName;
	cout<<"insert owner's ID :";
	cin>>key.OID;
	cout << "insert business type:";
	cin>>key.bType;
	cout << "insert business Address";
	cin>>key.bAdd,31;
	cout<<"insert contact number:";
	cin>>key.contact;
	cout<<"do you have email \n \t press 1 for yes press 0 for no";
	cin>>c;
	switch (c){
		case 1:
			cout<< "enter email:";
			cin>>key.email;
			break;
		case 0:
			cout<< "ok no worries";
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
 		cout<<"{"<<p->value.BID<<","<<p->value.bName<<","<<p->value.bType<<","<<p->value.oName<<","<<p->value.OID<<","<<p->value.contact<<","<<p->value.bAdd<<","<<p->value.email<<"}-->";
 		if(p->next == NULL)
 		{
 			printf("/");
 		}
 		p = p-> next;

 	}
 	return NULL;
 }

struct Node *Print_DB(struct Node *p){
	cout<<left;
	
        cout<<endl;
        int Sr =1;
        while(p!=NULL){
 			cout<<setw(1)<<"|"<<setw(5)<<Sr<<setw(1)<<"|"<<setw(14)<<p->value.BID<<setw(1)<<"|"<<setw(20)<<p->value.bName<<
      	          setw(1)<<"|"<<setw(15)<<p->value.bType<<setw(1)<<"|"<<setw(20)<<p->value.oName<<setw(1)<<"|"<<setw(12)<<p->value.contact<<setw(1)<<"|"<<setw(30)<<p->value.bAdd<<
                  setw(1)<<"|"<<setw(20)<<p->value.email<<setw(1)<<"|"<<"\n";
        	for(int i = 0; i < 137 ;i++){
            	if(i==0||i==5||i==19||i==39||i==54||i==74||i==86||i==116||i==136)
                		cout<<"+";
            	cout<<"-";
            	cout<<endl;
 				if(p->next == NULL)
 				{
 					cout<<endl;
 				}
 				p = p-> next;
 				cout<<endl;
 	}
     

  }
  return 0;
}    

int main()
{	cout<<left;
 	char x;
	int choice;
	int size,n;
	printf("take the hashtable size:");
	cin>>size;
	struct Node **HT= new struct Node*[size];
	for (int i = 0; i < size; ++i)
	{
		HT[i]=NULL;
	}
	cout<<"enter  no. of nodes: "<<endl;
	cin>>n;
	Node_at *key = new Node_at[n];
	
	do{	
		cout<<"This is business catalogue of surrounding you are given following choices:";
		cout<< "\nMENU :- \n 1.Register your business \n 2.Remove a Business or remove any element \n 3.Check number of businesses \n 4.Display entire catalogue \n \n please enter your choice ";
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"Welcome dear \n \t We have following categories of businesses avaible \n \t 1.Grocery \n \t 2.Jewelery \n \t 3.Provision \n \t 4.Entertainment \n \t 5.Tours and Travels \n \t 6.Clothings \n  Enter your BID ";
				for(int i = 0;i<n;i++){
					cin>>key[i].BID;
					Insert_Row(HT,key[i],size);
					cout<<endl;	
				}
				break;
			case 2:
				int c;
				cout<< "select whether you want to remove entire business or remove an entry \n insert '1' for removing entire entry or '2' for removing any element ";
				switch (c){
					case 1:
						//remove_row();
						break;
					case 2:
						//ask for row to delete from 
						//ask for element to delete
						//delete the item replacing 0;
						break;
					default:
						break;

				}
			case 3:
				cout<< "total businesses in Town is:";//<< length();
				break;
			case 4:
				int a;
				cout<< "Do you want to look at 1.database table or 2.hash table [1/2]?";
				cin>> a;
				switch (a){
					case 1:
						//display database table ;
						cout<< setw(145) << "                                                     MI-Batch-2020 (Team_03) business catalogue"<<"\n";
        				for(int i = 0; i < 137 ;i++){
            				if(i==0||i==5||i==19||i==39||i==54||i==74||i==86||i==116||i==136)
                					cout<<"+";
            				cout<<"-";
        				}
        				cout<<endl;

    					cout<<setw(1)<<"|"<<setw(5)<<"Sr.no"<<setw(1)<<"|"<<setw(14)<<"Business ID"<<setw(1)<<"|"<<setw(20)<<"Business Name"<<
      						  setw(1)<<"|"<<setw(15)<<"Business Type"<<setw(1)<<"|"<<setw(20)<<"Business Owner"<<setw(1)<<"|"<<setw(12)<<"Contact no."<<setw(1)<<"|"<<setw(30)<<"Business Address"<<
      						  setw(1)<<"|"<<setw(20)<<"Business Email"<<setw(1)<<"|"<<"\n";
        				for(int i = 0; i < 137 ;i++){
            				if(i==0||i==5||i==19||i==39||i==54||i==74||i==86||i==116||i==136)
                						cout<<"+";
            				cout<<"-";
       					}	
						for(int i = 0; i <size ; i++)
	 					{	
	 						
	 						Print_DB(HT[i]);
	 						cout<<endl;
	 						for(int i = 0; i < 137 ;i++){
            				if(i==0||i==5||i==19||i==39||i==54||i==74||i==86||i==116||i==136)
                					cout<<"+";
            				cout<<"-";
        					}
        					cout<<endl;
	 					}
						break;
					case 2:
						//display Hash table;
						for(int i = 0; i <size ; i++)
	 					{	
	 						printf("%d : ",i);	
	 						Print_Hash(HT[i]);
	 						printf("\n");
	 					}
						break;
					default:
						break;

				}
			default:
				break;

			}
		cout<<"Do you want to continue:- [Y/N]?\t";
		cin>>x;
	}while (x=='Y'||x=='y');
	return 0;
}

