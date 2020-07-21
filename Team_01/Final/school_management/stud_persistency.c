/*School Mnagement Systems*//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

struct studDataa
{
  int id;
  char name[30];
  char class[10];
  char address[50];
  int contact;
};

extern void insert_stud(struct studDataa readStud);
struct studDataa readStud;

//Read the student data
void read_stud() {
  int i = 0;
  int fd;

  fd = open("Student.txt",O_RDWR | O_CREAT, 0644);
  if(fd < 0) {
     perror("read failed");
  }
  while (read(fd, (void *)&readStud, sizeof(struct studDataa))) {
    printf("%d\n%s\n%s\n%s\n%d\n", readStud.id, readStud.name, readStud.class, readStud.address, readStud.contact);
    insert_stud(readStud);
  }
  close(fd);
}

//Write the student data
void write_stud(struct studDataa stud)
{
  int fd;
  fd = open("Student.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
  if (fd < 0) {
    perror("file open failed...");
  }
  write(fd, (void *)&stud, sizeof(struct studDataa));
  close(fd);
}
