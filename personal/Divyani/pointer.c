#include<stdio.h>
void main() 
{
  int a = 10;
  int *p =&a;
  printf(" a=%d \n p=%d \n &a=%d \n &p=%d \n *p=%d \n *(&a)=%d",a, p, &a, &p, *p, *(&a) );
}
