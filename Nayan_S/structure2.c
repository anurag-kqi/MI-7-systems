#include <stdio.h>

struct student
{
    char name[20];
    int rollno;
}; 

void
main()
{
    struct student s1;  //ordinary type of student variable.
    struct student *p;  // pointer type of student variable.

    p = &s1; //storing address of s1 in pointer p variable.
  
    printf("Enter the student name\n");
    scanf("%s\n", p->name);
    printf("Enter the Roll No. of student");
    scanf("%d\n", &p->rollno);
    printf("-------------------------------------");
    printf("The Name of student is: %s", (*p).name);
    printf("The Roll No. of student is: %d", (*p).rollno);
}
