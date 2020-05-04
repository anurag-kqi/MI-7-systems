#include<stdio.h>
int main() {
  int a = 4;
  int *p = &a;
  char str[3];
  char *ptr;

  printf(" a = %d \n p = %d \n &a = %d \n &p = %d \n *p = %d \n *(&a) = %d \n",
         a, p, &a, &p, *p, *(&a));

  printf("Enter a string");
  scanf("%s", str);
  printf("%s\n", str);

  // ptr=str;  //assinging address of str to ptr
  // printf("Entered string is:");
  // while (*ptr != '\0') {
  //   printf("%c", *ptr);
  // }

  return 0;
}
