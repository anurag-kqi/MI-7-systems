/* Program to print student information using structure */

#include <stdio.h>

struct StudentData {
  int stu_id;
  int stu_marks;
  int stu_age;
};
int
main()
{
  /* student is the variable name*/
  struct StudentData student;

  /*Assinging value to structure members*/
  student.stu_id = 212;
  student.stu_marks = 78;
  student.stu_age = 19;

  /*Displaying the value of structure members*/
  printf("\nstudent id is: %d", student.stu_id );
  printf("\nstudent marks is: %d", student.stu_marks );
  printf("\nstudent age is: %d", student.stu_age);
  return 0;
}
