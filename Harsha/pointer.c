#include<stdio.h>
int main() {
  int a = 4;
  int *p = &a;
  printf(" a = %d \n p = %d \n &a = %d \n &p = %d \n *p = %d \n *(&a) = %d",
   a, p, &a, &p, *p, *(&a) );
  return 0;
}
