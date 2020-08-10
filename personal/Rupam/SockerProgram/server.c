#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>

struct
{
    int roll_no;
    char name[20];
    int mark;
}student;

int main()
{
  int s,n,sock,choice,found,rollnumber,shift,continu;
  char buffer[20];
  FILE *fp;
  struct sockaddr_in client,server;
  s=socket(AF_INET,SOCK_STREAM,0);
  server.sin_family=AF_INET;
  server.sin_port=2000;
  server.sin_addr.s_addr=inet_addr("127.0.0.1");
  bind(s,(struct sockaddr *)&server,sizeof server);
  listen(s,1);
  n=sizeof client;
  sock=accept(s,(struct sockaddr *)&client,&n);
  printf("\n\t\t<<< STUDENT FILE MANAGEMENT SYSTEM>>>\n");
  do{
  recv(sock,&choice,sizeof(int),0);
  switch(choice)
  {
    case 1 :

        recv(sock,(void *)&student,sizeof(student),0);
        printf("\nNew student record received is:%d %s %d \n",student.roll_no,student.name,student.mark);
        fp=fopen("studentfile.txt","a+");
        fprintf(fp,"\n%d\t%s\t%d\t",student.roll_no,student.name,student.mark);
        fclose(fp);
        printf(" A student record has been added successfully...\n");
        recv(sock,&shift,sizeof(int),0);
        if(shift==1)
        break;
        else if(shift==2)
        {
                continu=0;
                break;
        }

    case 2:
           recv(sock,&rollnumber,sizeof(int),0);
           printf("Searching record with rollnumber=%d.\n",rollnumber);
           found=0;
           if((fp=fopen("studentfile.txt","r"))==NULL)
        {
            printf(" ! The File is Empty...\n\n");
            send(sock,&found,sizeof(int),0);
        }
        else
        {
            while(!feof(fp)&& found==0)
                {
                fscanf(fp,"\n%d\t%s\t%d\t",&student.roll_no,student.name,&student.mark);
                if(student.roll_no==rollnumber)
                    found=1;
            }
            send(sock,&found,sizeof(int),0);
                 fclose(fp);
                 if(found)
            {
                printf(" Record found...\n");
                send(sock,(const char*)&student,sizeof(student),0);

            }
            else
            {
                printf(" Record not found...Exiting\n");
                exit(0);
            }

        }
        recv(sock,&shift,sizeof(int),0);
        if(shift==1)
        break;
        else if(shift==2)
        {
                continu=0;
                break;
        }
    default :
          printf(" Bad request...Exiting...\n");
          continu=0;
        break;
  }
  }while(continu!=0);

 //close(sock);
  //close(s);
}
