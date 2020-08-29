/*program of pascals triangle*/

#include <stdio.h>

int 
main() 
{
   int rows, c = 1, dist, i, j;
   printf("number of rows: ");
   scanf("%d", &rows);
   for (i = 0; i < rows; i++) {
      for (dist = 1; dist <= rows - i; dist++)
         printf("  ");
      for (j = 0; j <= i; j++) {
         if (j == 0 || i == 0)
            c = 1;
         else
            c = c * (i - j + 1) / j;
         printf("%4d", c);
      }
      printf("\n");
   }
   return 0;
}