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
}

int main() {
  
  nodeElement B;
  int fd1;
  int fd = open("IN.data", O_APPEND|O_RDWR|O_CREAT, 0666);
  int count;

  FILE *fp = fopen("IN.txt", "rw+");
  if(fp == NULL) {
    perror("fopen failed");
    exit(-1);
  }

  printf("enter id no : ");
  scanf("%d",&B.s);
  printf("enter name : ");
  scanf("%s",B.name);
  printf("enter address : ");
  scanf("%s",B.address);

  count = write(fd, (void *)&B, sizeof(nodeElement));
  if(count < 0) {
    perror ("write failed");
    _exit(1);
  } else {
    fprintf(stderr,"wrote %d bytes\n", count);
  }
  int length = lseek(fd, 0, SEEK_END)+1;
  close(fd);

  fd1 = open("IN.data",O_RDWR);
  //printf("length : %d\n",length);
  int size = length/sizeof(nodeElement);
  //printf("size : %d\n",size);
  nodeElement *Businesses = (nodeElement *) malloc (sizeof(nodeElement)*size);
  
  int i = 0;
  int count1;
  do {
    printf("count is : %d", count);
    count1 = read(fd1, (void *)&Businesses[i], sizeof(nodeElement));
    if(count1 < 0) {
       perror("read failed");
    } 
    printf(" Businesses[%d] is %d %s %s\n",i,Businesses[i].s,Businesses[i].name,Businesses[i].address);
    i++;
   
  } while ( count1 !=0 ) ;
  //free(Businesses);
  //close(fd1);
  
  //delete_portion
  int del_id;
  printf("enter the id you want to delete :");
  scanf("%d",&del_id);
  for (int i = 0; i<size; i++) {
    if(Businesses[i].s == del_id) {
        for( int j = i ; j<size+1; j++) {
          Businesses[i].s = Businesses[i+1].s;
          strcpy(Businesses[i].name,Businesses[i+1].name);
          strcpy(Businesses[i].address,Businesses[i+1].address);
          count = write(fd1,(void *)&Businesses[i],sizeof(nodeElement));
        } 
        printf("element deleted ! written %d bytes\n",count);
        size --;
    } break; 
  }
 // Businesses = (nodeElement *) realloc (Businesses,sizeof(nodeElement)*size);
  i = 0;
  do {
    printf("count initial is :%d\n",count);
    count = read(fd1, (void *)&Businesses[i], sizeof(nodeElement));
    if(count < 0) {
       perror("read failed");
    } 
    printf(" Businesses[%d] is %d %s %s\n",i,Businesses[i].s,Businesses[i].name,Businesses[i].address);
    printf("count final is :%d\n",count);
    i++;
  } while ( count !=0);
  close(fd1);

  free(Businesses);
  return 0;
}
