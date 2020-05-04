#include<stdio.h>
int main() {
  int *p;
  printf("size of char=%d\n\n", sizeof(char));

  printf("size of int=%d\n", sizeof(int));
  printf("size of short=%d\n", sizeof(short));
  printf("size of long=%d\n\n", sizeof(long));

  printf("size of float=%d\n", sizeof(float));
  printf("size of double=%d\n\n", sizeof(double));

  printf("size of pointer int*=%d\n", sizeof(int *));
  printf("size of pointer p=%d\n", sizeof(p));
  printf("size of pointer *p=%d\n", sizeof(*p));

  return 0;
}
