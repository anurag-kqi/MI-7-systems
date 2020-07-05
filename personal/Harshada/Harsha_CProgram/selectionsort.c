/* Sort Elements by using selection Sort*/

#include <stdio.h>

void selectionSort(int count, int number[]);

int
main()
{
    int i, count, number[10];

    printf("how many numbers you want to enter: \n");
    scanf("%d", &count);

    printf("Enter numbers\n");
    for (i = 0; i < count; i++) {
        scanf("%d", &number[i]);
    }

    selectionSort(count, number);

    return 0;
}

void
selectionSort(int count, int number[])
{
  int i, j, temp;

  for (i = 0; i < count; i++) {
      for (j = (i + 1); j < count; j++) {
          if (number[i] > number[j]) {
              temp = number[i];
              number[i] = number[j];
              number[j] = temp;
          }
      }
  }

  printf("Sorted Elements: ");
  for (i = 0; i < count; i++) {
      printf("%d ", number[i]);
  }
}
