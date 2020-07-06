// Program is to check number entered by user is palindrome or not.

#include <stdio.h>
#inlucde <conio.h>

void
main()
{
    int number;
    int remainder;
    int reverse = 0;
    int dummy;

    printf("Enter the Number:\n");
    scanf("%d\n", &number);
    dummy = number;

    while (number != 0){
        remainder = number % 10;
        reverse = reverse * 10 + remainder;
        number /= 10;   // number = number / 10
      }

    if(dummy == reverse)
      {
         printf("%d is palindrome number", dummy);
      }
    else
      {
         printf("%d is not a palindrome number", dummy);
      }

}
