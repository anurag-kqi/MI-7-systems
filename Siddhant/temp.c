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

// void insert(nodeElement *T, nodeElement B) {
//   static int i = 0;  
//   {
//     T[i] = B;
//     printf("%d\n",T[i].s);
//     printf("%s\n",T[i].name);
//     i++;
//   }
// }

void write_in(nodeElement B) {
  int fd = open("IN.data", O_APPEND|O_RDWR|O_CREAT, 0666);
  int count;
  count = write(fd, (void *)&B, sizeof(nodeElement));
  if(count < 0) {
    perror ("write failed");
    _exit(1);
  } else {
    fprintf(stderr,"wrote %d bytes\n", count);
  }
  close(fd);
}

void read_in(nodeElement Businesses[],int fd1) {
  fd1 = open("IN.data",O_RDWR);

  int i = 0;
  int count1;
  do {
    
    count1 = read(fd1, (void *)&Businesses[i], sizeof(nodeElement));
    if(count1 < 0) {
       perror("read failed");
    } 
    printf(" Businesses[%d] is %d %s %s\n",i,Businesses[i].s,Businesses[i].name,Businesses[i].address);
    i++;
   
  } while ( count1 !=0 ) ;
  free(Businesses);
  close(fd1);
}

void delete(int del_id, int size, nodeElement Businesses[]) {
  int fd1 = open("IN.data",O_RDWR);
  int count;
  

  for (int i = 0; i<size; i++) {
    if(Businesses[i].s == del_id) {
        lseek (fd1,sizeof(nodeElement),SEEK_CUR);
        for( int j = i ; j<size+1; j++) {
          Businesses[i].s = Businesses[i+1].s;
          strcpy(Businesses[i].name,Businesses[i+1].name);
          strcpy(Businesses[i].address,Businesses[i+1].address);
          
        } 
        printf("element deleted ! written %d bytes\n",count);
        size --;
    } break; 
  }
  lseek (fd1, 0,SEEK_SET);
  count = write(fd1,(void *)&Businesses,sizeof(nodeElement));
  close(fd1);
  read_in(Businesses,fd1);

}

int main() {
  
  nodeElement B;
  int count;
  int fd1;
  
  printf("enter id no : ");
  scanf("%d",&B.s);
  printf("enter name : ");
  scanf("%s",B.name);
  printf("enter address : ");
  scanf("%s",B.address);
  write_in(B);
  
  //printf("length : %d\n",length);
  fd1 = open("IN.data",O_RDWR);
  int length = lseek(fd1, 0, SEEK_END)+1;
  int size = length/sizeof(nodeElement);
  close(fd1);
  nodeElement *Businesses = (nodeElement *) calloc (size-1,sizeof(nodeElement));
  
  read_in(Businesses,fd1);
  
  int del_id;
  printf("enter the id you want to delete :");
  scanf("%d",&del_id);
  delete(del_id, size, Businesses);

  
  return 0;
}