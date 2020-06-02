/*program to find solution using selection sort*/

#include <stdio.h>
void 
main()
{
   int i, j, count, temp, number[25];

   printf("How many numbers u are going to enter?: ");
   scanf("%d", &count);
   printf("Enter %d elements: ", count);
   
   // Loop to get the elements stored in array
   for (i=0;i<count;i++){
      scanf("%d", &number[i]);
   }
 
   // Logic of selection sort algorithm 
   for (i=0;i<count;i++){
     for (j=i+1;j<count;j++){
       if (number[i] > number[j]){
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
         }
       }
     }

   printf("Sorted elements: ");
   for (i=0;i<count;i++){
      printf(" %d", number[i]);
    }
}
