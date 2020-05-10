/* program to find size of data types*/

#include <stdio.h>
int 
main()
{
  int intType;
  float floatType;
  char charType;
  double doubleType;
  printf("size of int: %d bytes\n", sizeof (intType));
  printf("size of float: %f bytes\n", sizeof (floatType));
  printf("size of char: %c bytes\n", sizeof (charType));
  printf("size of double: %d bytes\n", sizeof(doubleType));
  return 0;
}
