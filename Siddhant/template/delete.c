#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <string.h>
#include "functions.h"

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