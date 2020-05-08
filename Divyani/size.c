/*Find the size of int,char,float*/
#include <stdio.h>
void
main()
{
  int a=4;
  char y='b';
  //Using variable name as a input
  
  printf("The size of int is: =%d\n",sizeof(a));
  printf("The size of char is: =%d\n",sizeof(y));
  
  //Using data type as a input
  printf("The size of float is: =%d\n",sizeof(float));
}
