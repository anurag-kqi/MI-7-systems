// odd and even program 
#include <stdio.h>
  int main()
  {
      int num;
      printf("enter an number:");
      scanf("%d",&num);
      // using modulus operator(%)
      if (num%2==0)
      printf("%d is even num",num);
      else
      printf("%d is odd num", num);
      return 0;
  }