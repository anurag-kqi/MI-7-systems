#include <stdio.h>
int main()
{
  int intType;
  float floattType;
  char charType;
  double doubleType;
  printf("size of int: %ld bytes\n", sizeof (intType));
  printf("size of float: %ld bytes\n", sizeof (floattType));
  printf("size of char: %ld bytes\n", sizeof (charType));
  printf("size of double: %ld bytes\n", sizeof(doubleType));
  return 0;
}
