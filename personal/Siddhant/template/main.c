#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <string.h>
#include "functions.h"


int main() {
  nodeElement B;
  int count;
  int fd1;
  char add[20];
  char na[20];

  static int size = 0,length = 0;
  nodeElement *Businesses;
  int choice;
  while(1) {
    printf("\t\tMENU:\n");
    printf("\t Options are :\n\t\t1) insert\n\t\t2) read\n\t\t3) delete\n\t\t4) exit\n\t\t5) size of file\n");
    printf("\t write your choice : ");
    scanf("%d",&choice);
    printf("\n");
    switch(choice) {
      case 1 : {
        printf("enter id no : ");
        scanf("%d",&B.s);
        printf("\nenter name : ");
        scanf("%s[^'\n']*c",B.name);
        printf("\nenter address : ");
        scanf("%s[^'\n']*c",B.address);
        write_in(B);
      } break;
      
      case 2: {
        fd1 = open("IN.data",O_RDWR);
        length = lseek(fd1, 0, SEEK_END)+1;
        size = length/sizeof(nodeElement);
        close(fd1);
        Businesses = (nodeElement *) calloc (size,sizeof(nodeElement));
        read_in(Businesses,fd1);
      } break;
      
      case 3: {
        int del_id;
        fd1 = open("IN.data",O_RDWR);
        length = lseek(fd1, 0, SEEK_END)+1;
        size = length/sizeof(nodeElement);
        close(fd1);
        printf("enter the id you want to delete :");
        scanf("%d",&del_id);
        delete_it(del_id, size, Businesses);
      } break;

      case 4 : {
        free(Businesses);
        exit(1);
      }

      case 5 : {
        printf("size of file till now is :");
        fd1 = open("IN.data",O_RDWR);
        length = lseek(fd1, 0, SEEK_END)+1;
        size = length/sizeof(nodeElement);
        close(fd1);
        printf("%d Bytes\n and nodes present are %d\n", length, size);

      }

      default : {
        printf("incorrect choice\n");
      } break;
    }
  }
  free(Businesses);
  return 0;
}