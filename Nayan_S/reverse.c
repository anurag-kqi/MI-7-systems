// Program is to reverse a number entered by the user.

#include <stdio.h>
#include <conio.h>

int 
main()
{

   int number;
   int reverse = 0;
   int remainder;

  printf("Enter the Number you want to reverse!\n");
  scanf("%d", number); 

  while (Number != 0){
       remainder = number % 10;
       reverse = reverse * 10 + remainder;
       number /= 10;
     }

   printf("Reverse Number is %d", reverse);
   return 0;
}
