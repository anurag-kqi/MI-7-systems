/*School Mnagement Systems*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

struct studData
{
  int id;
  char name[30];
  char class[10];
  char address[50];
  int contact;
  int index;
};

void write_stud(struct studData stud);
void read_stud();
void delete_stud();
//extern void insert_stud(int id, char name[], char class[], char address[], int contact);

//Read the student data
void read_stud() {
  // struct studData readData;
  // int id, contact;
  // char name[30], class [30], address[50];
  // int fd =open("Student.txt", O_RDONLY);
  // if (fd < 0) {
  //   perror("open failed");
  //   exit(-1);
  // }
  // while (read(fd, (void*)&readData, sizeof(struct studData))) {
  //   printf("%d\n%s\n%s\n%s\n%d\n%d\n\n", readData.id, readData.name, readData.class, readData.address, readData.contact, readData.index);
  // }
  // close(fd);

  struct studData readStud;
  int fd = open("Student.txt",O_RDWR);
  int num_record = 0;

  while (read(fd, (void *)&readStud, sizeof(struct studData)) != EOF)
  {
    printf("\n%d\n%d\n%s\n%s\n%s\n%d\n", readStud.index, readStud.id, readStud.name, readStud.class, readStud.address, readStud.contact);
    num_record++;
  }
  printf("\n------number of records: %d------\n\n", num_record);
  free(readStud);
  close(fd);
}
//Write the student data
void write_stud(struct studData stud)
{
  int fd;
  fd = open("Student.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
  if (fd < 0) {
    perror("file open failed...");
  }
  write(fd, (void *)&stud, sizeof(struct studData));
  close(fd);

}

void delete_stud(int num_record)
{
   int fd;
   fd = open("Student.txt", O_RDWR);
  // lseek ((num_record - 1) * sizeof (struct studData), 0);
  // if (fd == NULL) {
  //   perror("could not open file");
  // }
  // close(fd);
  // printf("deleting data \n");
  // if (truncate("/home/harshada/Harshada1/MI-7-systems/personal/Harshada/Harsha_CProgram/Student.txt", sizeof(struct studData)) == -1) {
  //   perror("could not truncate");
  // }
  // printf("data deleted\n");

}

//main function
int main()
{

  struct studData stud;

  printf("\n\tEnter Index : ");
  scanf("\t %d", &stud.index);
  printf("\n\n\tEnter ID : ");
  scanf("\t %d", &stud.id);
  printf("\n\tEnter Name : ");
  scanf("\t %[^\n]%*c", stud.name);
  printf("\n\tEnter Class : ");
  scanf("\t %s", stud.class);
  printf("\n\tEnter Address : ");
  scanf("\t %[^\n]%*c", stud.address);
  printf("\n\tEnter Contact : ");
  scanf("\t %d", &stud.contact);

  write_stud(stud);
  //delete_stud();
  read_stud();
    //calling main menu function
    //menus();

    return 0;
}
