#include<stdio.h>

int
main()
{
  int *p;
  
  struct employee
  {
      int emp_num;
      char emp_name[20];
      double emp_sall;
  };

  int str[20];
  char str1[20];
  float str2[20];

  printf("size of char = %d\n\n", sizeof(char));

  printf("size of int = %d\n", sizeof(int));
  printf("size of short = %d\n", sizeof(short));
  printf("size of long = %d\n\n", sizeof(long));

  printf("size of float = %d\n", sizeof(float));
  printf("size of double = %d\n\n", sizeof(double));

  printf("size of pointer int* = %d\n", sizeof(int *));
  printf("size of pointer p = %d\n", sizeof(p));
  printf("size of pointer *p = %d\n\n", sizeof(*p));

  printf("size of structure = %d\n\n", sizeof(struct employee));

  printf("size of integer array = %d\n", sizeof(str));
  printf("size of charector array = %d\n", sizeof(str1));
  printf("size of float array = %d\n", sizeof(str2));
  return 0;
}
