#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <string.h>
#include "functions.h"


void delete_it(int del_id, int size, nodeElement Businesses[]) {
  int fd1 = open("IN.data",O_RDWR);
  if (fd1 < 0) {
    perror("Open failed");
    return;
  }
  int i = 0;
  int count, count1;
  int found = 0;
  int fd2 = open("temp.data", O_APPEND|O_RDWR|O_CREAT|O_TRUNC, 0666);
  if (fd2 < 0) {
    perror("Open failed");
    return;
  }
  //nodeElement *temp =(nodeElement *) malloc (sizeof(nodeElement)*size);
  do {
    
    count = read(fd1, (void *)&Businesses[i], sizeof(nodeElement));
    if (count < 0) {
       perror("read failed");
    }

    if (Businesses[i].s == del_id) {
      printf("element found\n");
      found = 1;
      size--;
    } else {
      count1 = write(fd2,(void *)&Businesses[i],sizeof(nodeElement));
      if (count1 < 0) {
        perror("write failed");
        _exit(-1);
      } 
    }

    i++;
  }  while (count);
  
  if(!found) {
    printf("no element found with such ID\n");
  }

  close(fd2);
  close(fd1);
  remove("IN.data");
  rename("temp.data","IN.data");
  //free(temp);
  //read_in (Businesses,fd1);
}