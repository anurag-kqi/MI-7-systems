//Linear Search  Program

#include <stdio.h>
#define SIZE 5

int
LinearSearch(int arr[], int size, int key) {

	int i;
    for(i = 0; i < size; i++)
        if(arr[i] == key)
            return 1;

    return 0;
   }

int
main()
   {
    int array[SIZE] = {86, 91, 34, 50, 0};

    int key = 50;

    if(LinearSearch(array, SIZE, key) == 1)
        printf(" Search Found ");
    else
        printf(" Search Not Found ");

    return 0;
}
