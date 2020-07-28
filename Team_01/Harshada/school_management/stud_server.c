// Server Program: sttcps.c

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/stat.h>
#include "structure.h"
#define size 9

int
main()
{
    int s, n, sock, ch

    struct sockaddr_in client, server;

    s=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=2000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(s,(struct sockaddr *)&server,sizeof server);
    listen(s,1);
    n=sizeof client;
    sock=accept(s,(struct sockaddr *)&client,&n);

    while (1) {
        printf("\n_______________________________________________________________________________");
        printf("\n\n\t---- SCHOOL MANAGEMENT SYSTEM MENU ----");
        recv(sock, &ch, sizeof(int), 0);

	      printf("\n_______________________________________________________________________________");
        switch (ch) {
            case 1:
                printf("\n\n\t---- INSERT IN TO  STUDENT----");
                recv(sock,&ch,sizeof(int),0);
                switch (ch) {
                    case 1:
                     recv(sock,(void *)&stud,sizeof(stud),0);
                     printf("\nNew student record received is:%d %d %s %s %d %s\n",stud.index,stud.id,stud.name,stud.class,stud.contact,stud.address);
                     insert_stud(stud);
                     write_stud(stud);
                     num_records++;

//                   printf(" A student record has been added successfully...\n");

                            }
                            break;
                    case 2:
                     recv(sock,(void *)&steach,sizeof(teach),0);
                     printf("\nNew student record received is:%d %d %s %s %d \n",teach.index,teach.id,teach.name,teach.department,teach.contact);
                                insert_stud(teach;
                                write_stud(teach);
                                                   num_records++;

                    //                   printf(" A student record has been added successfully...\n");


                            }
                            break;
                    case 3: exit(0);
                    default: printf("\n\n\tWrong Choice!!\n");
                }
              break;
              case 2: printf("\n\n\t---- DISPLAY DATA ----");
                      printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    //  printf("\n\n\tEnter your choice to display(1-3) : ");
                      scanf("\t%d", &ch);
                      recv(sock,&ch,sizeof(int),0);

                      switch (ch)
                      {
                          case 1: display_stud();
                                  break;
                          case 2: display_teach();
                                  break;
                          case 3: exit(0);
                          default: printf("\n\n\tWrong Choice!!\n");
                      }
                      break;

              case 3: printf("\n\n\t---- DELETE FROM ----");
                      printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                      //printf("\n\n\tEnter your choice to delete(1-3) : ");
                      //scanf("\t %d", &ch);
                      recv(sock,&ch,sizeof(int),0);

                      switch(ch)
                      {
                          case 1: //printf("\n\n\tEnter Student id for Delete : ");
                                 // scanf("\t %d", &stud.id);
      		                 recv(sock,&stud.id,sizeof(int),0);

                                    delete_stud(stud.id);
                                  break;

                          case 2:// printf("\n\n\tEnter Teacher id for Delete : ");
                                  //scanf("\t %d", &teach.id);
                                  recv(sock,&teach.id,sizeof(int),0);

      			           delete_teach(teach.id);
                                  break;

                          case 3: exit(0);
                          default: printf("\n\n\tWrong Choice!!\n");
                      }
                      break;

              case 4: printf("\n\n\t---- UPDATE FROM ----");
                      printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                  //     printf("\n\n\tEnter your choice to update(1-3) : ");
                  //     scanf("\t %d", &ch);
                      recv(sock,&ch,sizeof(int),0);

                      switch(ch)
                      {
                          case 1: //printf("\n\n\tEnter Student ID for Update : ");
                                  //scanf("\t %d", &id);
  				                      recv(sock,&stud.id,sizeof(int),0);

                                                          update_stud(id);
                                  break;
                          case 2: //printf("\n\n\tEnter Teacher ID for Update : ");
                                  //scanf("\t %d", &id);
  				                      recv(sock,&teach.id,sizeof(int),0);

                                                          update_teach(id);
                                  break;
                          case 3: exit(0);
                          default: printf("\n\n\tWrong Choice!!\n");
                      }
                      break;

    	        case 5: printf("\n\n\t---- SEARCH FROM ----");
                      printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                      printf("\n\n\tEnter your choice to search(1-3) : ");
                      scanf("\t %d", &ch);
                      recv(sock,&ch,sizeof(int),0);

                      switch(ch)
                      {
                          case 1:// printf("\n\n\tEnter Student ID for Search : ");
                          //         scanf("\t%d", &id);
                                     recv(sock,&id,sizeof(int),0);

                                                          search_stud(id);
                                  break;
                          case 2: //printf("\n\n\tEnter Teacher ID for Search : ");
                                  //scanf("\t%d", &id);
                                     recv(sock,&id,sizeof(int),0);

                                                          search_teach(id);
                                  break;
                          case 3: exit(0);
                          default: printf("\n\n\tWrong Choice!!\n");
                      }
                      break;

              case 6: exit(0);
        	    default: printf("\n\n\tWrong Choice!!\n");
          }
      }
  }

    close(sock);
    close(s);
    return 0;

}








// //  printf("\n\t\t<<< STUDENT FILE MANAGEMENT SYSTEM>>>\n");
//   printf("\n_______________________________________________________________________________");
//   printf("\n\n\t---- SCHOOL MANAGEMENT SYSTEM MENU ----");
//   //do{
//     while(1){
//   recv(sock,&choice,sizeof(int),0);
//   switch(choice)
//     {
//     case 1 :
//             printf("\n\n\t---- INSERT IN TO ----");
//             printf("\n\n\t1.Student\n\t2.Teacher");
//             recv(sock,&choice,sizeof(int),0);
//             switch(choice){

//                  case 1:
//                 recv(sock,(void *)&student,sizeof(student),0);
//                 printf("\nNew student record received is:%d %s %d %d %s\n",student.id,student.name,student.class,student.contact,student.address);
//                 fp=fopen("studentfile.txt","a+");
//                 fprintf(fp,"\n%d\t%s\t%d\t%d\t%s\t",student.id,student.name,student.class,student.contact, student.address);
//                 fclose(fp);
//                 printf(" A student record has been added successfully...\n");
//                 recv(sock,&shift,sizeof(int),0);
//                 if(shift==1)
//                 break;
//                 else if(shift==2)
//                 {
//                         continu=0;
//                         break;
//                 }

//                  case 2 :
//                  recv(sock,(void *)&teacher,sizeof(teacher),0);
//                  printf("\nNew Teacher record received is:%d %s %s %d \n",teacher.id,teacher.name,teacher.department,teacher.contact);
//                  fp=fopen("teacherfile.txt","a+");
//                  fprintf(fp,"\n%d\t%s\t%s\t%d\t\t",teacher.id,teacher.name,teacher.department,teacher.contact);
//                  fclose(fp);
//                  printf(" A Teacher record has been added successfully...\n");
//                  recv(sock,&shift,sizeof(int),0);
//                  if(shift==1)
//                  break;
//                  else if(shift==2)
//                  {
//                          continu=0;
//                          break;
//                  }
//                  break;
//                  case 3:
//                         exit(0);
//                   default: printf("\n\n\tWrong Choice!!\n");
//                  }
//             break;
//     case 2:
//            recv(sock,&idnumber,sizeof(int),0);
//            printf("\n\n\tSearching record with id=%d.\n",idnumber);
//            found=0;
//            if((fp=fopen("studentfile.txt","r"))==NULL)
//         {
//             printf(" ! The File is Empty...\n\n");
//             send(sock,&found,sizeof(int),0);
//         }
//         else
//         {
//             while(!feof(fp)&& found==0)
//                 {
//                 fscanf(fp,"\n%d\t%s\t%d\t%d\t%s",&student.id,student.name,&student.class,&student.contact,student.address);
//                 if(student.id==idnumber)
//                     found=1;
//             }
//             send(sock,&found,sizeof(int),0);
//                  fclose(fp);
//                  if(found)
//             {
//                 printf(" Record found...\n");
//                 send(sock,(const char*)&student,sizeof(student),0);

//             }
//             else
//             {
//                 printf(" Record not found...Exiting\n");
//                 exit(0);
//             }

//         }
//         recv(sock,&shift,sizeof(int),0);
//         if(shift==1)
//         break;
//         else if(shift==2)
//         {
//                 continu=0;
//                 break;
//         }
//           default :
//           printf(" Bad request...Exiting...\n");
//           continu=0;
//         break;

// // case 3:
// //         printf("\n\n\t---- DISPLAY DATA ----");
// //         printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
// //         printf("\n\n\tEnter your choice to display(1-3) : ");
// //         recv(sock,&choice,sizeof(int),0);
// //
// //         // switch (ch)
//         // {
//         //    case 1: display_stud();
//         //    break;
//         //    case 2: display_teach();
//         //    break;
//         //    case 3: exit(0);
//         //    default: printf("\n\n\tWrong Choice!!\n");
//         //    }
//         //   break;
//         // case 4:
//         //         printf("\n\n\t------DELETE DATA-------");
//         //         printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
//         //         printf("\n\n\tEnter your choice to display(1-3) : ");
//         //         recv(sock,&choice,sizeof(int),0);
//         //            switch(choice)
//         //                 {
//                            // case 1: printf("Enter id to delete ")
//                            // //void Delete_Staff()         //Delete Staff Profile
//                            // recv(sock,&id,sizeof(int),0);
//                            //
//                            //  {
//                            //      FILE *fRead, *fWrite;
//                            //      char *TextFile;
//                            //      char c;
//                            //      int id, temp = 1;
//                            //
//                            //      TextFile="studentfile.txt";
//                            //
//                            //      fRead = fopen(TextFile, "r");
//                            //
//                            //      c = getc(fRead);
//                            //
//                            //      while (c != EOF){
//                            //      printf("%c", c);
//                            //      c = getc(fRead);
//                            //      }
//                            //
//                            //      rewind(fRead);
//                            //
//                            //      printf("\nDelete Student data with ID: ");
//                            //      scanf("%d", &id);
//                            //
//                            //      id=id+1;
//                            //
//                            //      fWrite = fopen("copy.c", "w");
//                            //      c = getc(fRead);
//                            //      while (c != EOF) {
//                            //      c = getc(fRead);
//                            //      if (c == '\n')
//                            //      temp++;
//                            //      if (temp != id){
//                            //      putc(c, fWrite);
//                            //         }
//                            //      }
//                            //
//                            //      fclose(fRead);
//                            //      fclose(fWrite);
//                            //
//                            //      remove(TextFile);
//                            //
//                            //      rename("copy.c", TextFile);
//                            //      printf("\nThe contents of file after being modified are as follows:\n");
//                            //
//                            //      fRead = fopen(TextFile, "r");
//                            //      c = getc(fRead);
//                            //      while (c != EOF) {
//                            //      printf("%c", c);
//                            //      c = getc(fRead);
//                            //      }
//                            //
//                            //      fclose(fRead);
//                            //  }
//                            //  send(sock,&TextFile,sizeof(int),0);
//                            //

//   }

// //  }while(continu!=0);
//   close(sock);
//   close(s);
//   return 0;

// }}
