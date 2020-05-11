/* Sort numbers using bubble Sort*/

#include <stdio.h>

int
main ()
{
    int i, j, temp, count, ary[10];
    printf("how many numbers you want to enter: \n");
    scanf("%d", &count);

    printf("Enter numbers\n");
    for (i = 0; i < count; i++) {
        scanf("%d", &ary[i]);
    }


    for (i = 0; i < count-1; i++) {
        for (j = 0 ; j < (count - i - 1); j++) {
            if (ary[j] > ary[j + 1]) {
                temp = ary[j];
                ary[j] = ary[j + 1];
                ary[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: \n");

    for (i = 0; i < count; i++) {
            printf("%d ", ary[i]);
    }
    printf("\n");

    return 0;
}
