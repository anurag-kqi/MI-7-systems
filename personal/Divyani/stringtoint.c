/*Program to convert string into integer*/

#include <stdio.h>
#include <stdlib.h>

void
main()
{
   int num;
   char A [256];
   
   printf ("\nEnter the number : ");
   fgets (A, 256, stdin);
   
   num = atoi (A);
   printf ("The value of number is : %d\n",num);
}
 
