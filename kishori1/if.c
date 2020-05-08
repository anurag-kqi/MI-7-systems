#include <stdio.h>
int main()
{
  int num;
  printf("enter a number:\n");
  scanf("%d",&num);
  if (num >= 0)
  {
    if (num > 0)
      printf("%d is a positive number \n",num);
    else
      printf("you have entered value zero");
  }
  else
  printf("%d is negative num",num);
  return 0;
}
