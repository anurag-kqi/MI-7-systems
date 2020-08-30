#include <stdio.h>
int main() {
   int n=8, x = 1, k, i, j;
     for (i = 0; i < n; i++) {
      for (k = 1; k <= n - i; k++)
         printf("  ");
      for (j = 0; j <= i; j++) {
         if (j == 0 || i == 0)
            x = 1;
         else
            x = x * (i - j + 1) / j;
         printf("%4d", x);
      }
      printf("\n");
   }
   return 0;
}

