/* program of union*/

#include <stdio.h>

union student
{
  int id;
  int marks;
};

int
main()
{
  /*info is a variable name*/
  union student info;
  info.id = 12;
  info.marks = 95;

  printf("id of the student: %d\n", info.id);
  printf("marks of the student: %d", info.marks);
  return 0;
  }
