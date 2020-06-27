#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <string.h>

typedef struct nodeElement {
  int s;
  char name[20]; 
  char address[20];
} nodeElement;

nodeElement *T;

void insert(nodeElement *T, nodeElement B) {
  static int i = 0;  
  {
    T[i] = B;
    printf("%d\n",T[i].s);
    printf("%s\n",T[i].name);
    i++;
  }
  //free(T);
}

int main() {
  nodeElement *Businesses = (nodeElement *) malloc (sizeof(nodeElement));
  nodeElement B;
  int fd = open("IN.txt", O_APPEND|O_RDWR|O_CREAT, 0666);
  int count;
  printf("enter roll no");
  scanf ("%d",&B.s);
  char sa[8] = itoa(B.s); 
  count = write( fd, B.s, sizeof(int) );
  if (count < 0) {
       perror("write failed");
       _exit(1);
   } else {
       fprintf(stderr, "wrote %d bytes\n", count);
  }
  lseek(fd,sizeof(int),SEEK_CUR);
  printf("enter name");
  scanf("%s",B.name);
  int size= strlen(B.name);
  printf("size of string is %d",size);
  count = write( fd, B.name, strlen(B.name) );
  if (count < 0) {
       perror("write failed");
       _exit(1);
   } else {
       fprintf(stderr, "wrote %d bytes\n", count);
  }
  lseek(fd,strlen(B.name),SEEK_CUR);
  //lseek(fd,0,SEEK_CUR);
  
  insert(Businesses,B);
  printf("enter roll no");
  scanf ("%d",&B.s);
  count = write( fd, &B.s, sizeof(int) );
  if (count < 0) {
       perror("write failed");
       _exit(1);
   } else {
       fprintf(stderr, "wrote %d bytes\n", count);
  }
  lseek(fd,sizeof(int),SEEK_CUR);
  printf("enter name");
  scanf("%s",B.name);
  count = write( fd, B.name, strlen(B.name) );
  if (count < 0) {
       perror("write failed");
       _exit(1);
   } else {
       fprintf(stderr, "wrote %d bytes\n", count);
  }
  lseek(fd,strlen(B.name),SEEK_CUR);
  //count = write()
  insert(Businesses,B);
  free (Businesses);
}