/*School Mnagement Systems*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

struct studData
{
  int id;
  char name[30];
  char class[10];
  char address[50];
  int contact;
};

void write_stud(struct studData stud);
void read_stud();
void delete_stud();
//extern void insert_stud(int id, char name[], char class[], char address[], int contact);

//Read the student data
void read_stud() {
  struct studData readStud[5];
  int fd = open("Student.txt",O_RDWR);

  int i = 0;
  int count1;
  do {
  //while ( fd != EOF ){
    count1 = read(fd, (void *)&readStud[i], sizeof(struct studData));
    if(count1 < 0) {
       perror("read failed");
    }
    printf("%d\n%s\n%s\n%s\n%d\n", readStud[i].id, readStud[i].name, readStud[i].class, readStud[i].address, readStud[i].contact);
    i++;
  }while ( count1 !=0 ) ;
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

void delete_stud()
{
  // int fd;
  // fd = open("Student.data", O_TRUNC | O_WRONLY);
  // if (fd == NULL) {
  //   perror("could not open file");
  // }
  // close(fd);
  printf("deleting data \n");
  if (truncate("/home/harshada/Downloads/Student.txt", 88) == -1) {
    perror("could not truncate");
  }
  printf("data deleted\n");

}

//main function
int main()
{

  struct studData stud;

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
  delete_stud();
  read_stud();
    //calling main menu function
    //menus();

    return 0;
}
