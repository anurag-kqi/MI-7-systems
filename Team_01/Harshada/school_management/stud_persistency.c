/*School Mnagement Systems*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

struct studDataa
{
  int index;
  int id;
  char name[30];
  char class[10];
  char address[50];
  int contact;
};

extern void insert_stud(struct studDataa readStud);
struct studDataa readStud;
int num_records = 0;

//Read the student data
void read_stud() {
  int fd;
  fd = open("Student.txt",O_RDWR | O_CREAT, 0644);
  if(fd < 0) {
     perror("read failed");
  }
  while (read(fd, (void *)&readStud, sizeof(struct studDataa))) {
    printf("%d\n%d\n%s\n%s\n%s\n%d\n\n", readStud.index, readStud.id, readStud.name, readStud.class, readStud.address, readStud.contact);
    insert_stud(readStud);
    num_records = ++num_records;
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

//Delete the Student
void delete_stud_file()
{
  printf("delete num_records = %d\n", num_records);
  struct studDataa readStud;
  int fd;
  fd = open("Student.txt", O_RDWR);
  lseek (fd, 2 * sizeof (readStud), 0);
  char buff;
  read(fd, &buff, sizeof(buff));
  if (buff == 1) {
    printf("delete if\n");
    int replace = 2;
    write(fd, &replace, 1);
  }
  while (read(fd, (void *)&readStud, sizeof(struct studDataa))) {
    printf("delete while\n");
    printf("%d\n%d\n%s\n%s\n%s\n%d\n\n", readStud.index, readStud.id, readStud.name, readStud.class, readStud.address, readStud.contact);
    insert_stud(readStud);
    num_records++;
  }
  close(fd);
}
