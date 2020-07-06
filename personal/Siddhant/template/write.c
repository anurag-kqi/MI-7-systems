#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <string.h>
#include "functions.h"

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