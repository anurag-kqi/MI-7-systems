#include "header.h"
struct
{
    int roll_no;
    char name[20];
    int mark;
}student;

int main()
{
   struct sockaddr_in client;
   int s,flag,choice,shift,rollnumber,found,continu;
   char buffer[20];


   s=socket(AF_INET,SOCK_STREAM,0);
   client.sin_family=AF_INET;
   client.sin_port=2000;
   client.sin_addr.s_addr=inet_addr("127.0.0.1");
   connect(s,(struct sockaddr *)&client,sizeof client);

   do{
      printf("\n\t\t<<< SCHOOL FILE MANAGEMENT SYSTEM>>>\n\t1 -> ADD a new record in server\n\t2 -> Search a student record from server\nEnter your choice: ");
      scanf("%d",&choice);
      send(s,&choice,sizeof(int),0);
      switch(choice)
      {
       case  1:
       printf("\nEnter Student Details:\nRoll number (Integer): ");
       scanf("%d",&student.roll_no);
       printf("\nName : ");
       scanf("%s",student.name);
       printf("\nMark : ");
       scanf("%d",&student.mark);
       send(s,(const char*)&student,sizeof(student),0);
       printf(" A student record has been sent successfully...\n");
       printf("\n press 1 -> conitnue,\n\t 2 -> Exit: ");
       scanf("%d",&shift);
       send(s,&shift,sizeof(int),0);

       if(shift==1)
        break;
       else if(shift==2)
        {
            continu=0;
            break;
        }
        case 2:
       printf("\nEnter Roll number: ");
       scanf("%d",&rollnumber);
       send(s,&rollnumber,sizeof(int),0);
       recv(s,&found,sizeof(int),0);
       if(found)
       {
          recv(s,(void *)&student,sizeof(student),0);
         printf("\nThe record is found.\nRoll no: %d\nName: %s\nMark: %d \n",student.roll_no,student.name,student.mark);
       }
       else
       {
         printf("Not found...\n");
         exit(0);
       }
       printf("\n press 1 -> conitnue,\n\t 2 -> Exit: ");
       scanf("%d",&shift);
       send(s,&shift,sizeof(int),0);
       if(shift==1)
        break;
       else if(shift==2)
       {
            continu=0;
            break;
       }
       default :
          printf(" Bad choice...Exiting...\n");
          continu=0;
        break;
        }
      }while(continu!=0);

      //close(s);
}
