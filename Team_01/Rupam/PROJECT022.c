#include<stdio.h>

#include<stdlib.h>

struct info

{

char name[30];

int roll_no;

int number;

char class_[10];

struct info *next;

struct info *prev;

};

struct info *head=NULL,*temp,*disp;



void main()

{

void addrecord();

void deleterecord();

void disrecord();

int ch;



while (1)

  {

    printf("\n 1. To add records\n");

    printf("\n 2. To delete a records\n");

    printf("\n 3. To view the records\n");

    printf("\n 4. To exit\n");

    printf("\n Enter your choice\n");

    scanf("%d",&ch);


     fflush(stdin);

    switch(ch)

     {

	  case 1:addrecord();

		 break;

	  case 2:deleterecord();

		 break;

	  case 3: disrecord();

		 break;

	  case 4:exit(0);

     }

  }

}



void addrecord()

{

   struct info *add;

   char ans='y';



   while (ans=='y')

   {

   add=(struct info*)malloc(sizeof(struct info));

   printf("\n Enter the names:\n");

   gets(add->name);

   fflush(stdin);

   printf("\n Enter the Roll number:\n");

   scanf("%d",&add->roll_no);

   fflush(stdin);

     if (head==NULL)

     {

	  head=add;

	  add->next=NULL;

	  add->prev=NULL;

	  temp=add;

      }

      else

      {

	  temp->next=add;

	  add->prev=temp;

	  add->next=NULL;

	  temp=add;

      }

      printf("Enter Mobile Number");
      scanf("%d", &add->number);
      fflush(stdin);

      printf("Enter class ");
      gets(add->class_);
     fflush(stdin);

    printf("\n Would you like to enter another name(y\\n): \n");

    ans = getchar();

    fflush(stdin);

    }



 }

void deleterecord()

{

  struct info *del;

 int teno;



  if (head==NULL)

  {

    printf("\n No records to delete\n");

    return;

   }



  printf("\n Enter the Roll number to be deleted \n");

  scanf("%d",&teno);

  fflush(stdin);



  del=(struct info*)malloc(sizeof (struct info));

  del=head->next;

     if (head->roll_no==teno)

	   {

	   printf("\n Head data cannot be deleted\n");

	   return;

	   }

while(del)

{

  if(del->roll_no==teno)

    {

      del->prev->next=del->next;

	  if (del->next!=NULL)

	  {

	  del->prev->next=del->next;

	  del->next->prev=del->prev;

	  }

	  else

	  {

	  head->next=temp->next=NULL;

	  temp=head;

	  }

	  return;

     }

     else

     {

     del=del->next;

     }

 }



   printf("\nInvalid input\n");

}

 void disrecord()

{

   if (head==NULL)

   {

    printf("\n No records to view\n");

    return;

    }

    printf("\n ***************Student Information******************\n");

    for (disp=head;disp!=NULL;disp=disp->next)

    {

    printf("\n\n Name   : %s",disp->name);

    printf("\n\n Number : %d",disp->roll_no);
    printf("\n\n Mobile Number : %d", disp->number);
    printf("\n\n Class : %d", disp->class_);
    }

    printf("\n Press any key to continue\n");

    getchar();

    printf("\n From backward direction\n");

    for (disp=temp;disp!=NULL;disp=disp->prev)

    {

    printf("\n\n Name   : %s",disp->name);

    printf("\n\n Number : %d",disp->roll_no);
    printf("\n\n Mobile Number : %d", disp->number);
    printf("\n\n Class_ : %d", disp->class_);

    }



}