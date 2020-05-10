#include <stdio.h>

void bubbleSort(int ary[], int n);
void swap(int *x, int *y);
void printAry (int ary, int n);

int
main ()
{
    int ary[] = {64, 85, 2, 6, 25, 85, 30, 72, 0, 100};
    int *n;

    // calculate size of array ary[]
    *n = (sizeof(ary) / sizeof(ary[0]));

    bubbleSort(ary, *n);
    printf("Sorted arrat:\n");
    printAry(ary, *n);

    return 0;
}

void
bubbleSort (int ary[], int n)
{
    int i, j;

    for (i = 0; i < n-1; i++) {
        for (j = 0 ; j < (n - i - 1); j++) {
            if (ary[j] > ary[j + 1]) {
                swap(&ary[j], &ary[j+1]);
            }
        }
    }
}

void
swap (int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void
printAry (int ary, int n)
{
    int i;
    for(i = 0; i < n; i++){
      printf("%d\n", ary[i]);
    }
    printf("\n");
}
