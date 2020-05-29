#include<stdio.h>

void main()
{
struct
{
int id_no;
char name[20];
char address[20];
int age;

}newstud;
printf("Enter the Student Information:\n");
printf("Now Enter student ID:");
scanf("%d", &newstud.id_no);
printf("Enter name of Student:");
scanf("%s", &newstud.name);
printf("Enter Address of Student:");
scanf("%s", &newstud.address);
printf("Enter age of Student:");
scanf("%d", &newstud.age);
printf("Student Information:");
printf("Student ID= %d\n", newstud.id_no);
printf("Student Name=%s\n", newstud.name);
printf("Student Address= %s\n", newstud.address);
printf("Age of Student= %d\n ", newstud.age);

}
