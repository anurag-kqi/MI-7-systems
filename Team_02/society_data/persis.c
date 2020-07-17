
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "soc.h"

// struct socData
// {
//   int index;
//   char owner_name[30];
//   int flat_num;
//   int owner_contact;
// };



extern void insert_soc(struct socData readsoc);
struct socData readsoc;
int num_records = 0;

void read_soc() {
  int fd;
  //int num_records = 0;
  fd = open(SOCIETY_DATAFILE, O_RDWR);
  if(fd < 0) {
     perror("read failed");
  }
  printf("In the read_soc %s %d\n", __FILE__, __LINE__);

  while (read(fd, (void *)&readsoc, sizeof(struct socData))) {
    printf("In the read_soc %d\n", __LINE__);
  
    printf("%d\n%s\n%d\n%d\n\n", readsoc.index, readsoc.owner_name, readsoc.flat_num, readsoc.owner_contact);
    insert_soc(readsoc);
    num_records++;
  }
  printf("In the read_soc %d\n", __LINE__);
  
  close(fd);
}

//Write the student data
void write_soc(struct socData soc)
{
  int fd;
  fd = open(SOCIETY_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
  if (fd < 0) {
    perror("file open failed...");
  }
  write(fd, (void *)&soc, sizeof(struct socData));
  close(fd);
}

//Delete the Student
/*void delete_soc_file()
{
  printf("delete num_records = %d\n", num_records);
  struct socData readsoc;
  int fd;
  fd = open("Society.txt", O_RDWR);
  lseek (fd, 2 * sizeof (readsoc), 0);
  char buff;
  read(fd, &buff, sizeof(buff));
  if (buff == 1) {
    printf("delete if\n");
    int replace = 2;
    write(fd, &replace, 1);
  }
  while (read(fd, (void *)&readsoc, sizeof(struct socData))) {
    printf("delete while\n");
    printf("%d\n%s\n%d\n%d\n\n", readsoc.index, readsoc.owner_name, readsoc.flat_num, readsoc.owner_contact);
    insert_soc(readsoc);
    num_records++;
  }
  close(fd);
}*/
