#include <stdio.h>

int
main()
{
    int i, j, k, n;

    printf("Enter any number: \n");
    scanf("%d", &n);

    for (i = 0; i <= n; i++) {

<<<<<<< HEAD
      for (k = n; k > 0; k--) {
        printf("  ");
      }
      n = n - 1;
=======
      for (k = 1; k <= (n - i); k++) {
        printf("  ");
      }
      //n = n - 1;
>>>>>>> 48c04f381a3b768b8ea8a4cfe3f6971b6e5d544c

      for (j = 1; j <= (2 * i) + 1; j++) {
        printf(" *");
      }
      printf("\n");
    }
    return 0;
}
