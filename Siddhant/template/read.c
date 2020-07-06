#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <string.h>
#include "functions.h"

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
  close(fd1);
}

