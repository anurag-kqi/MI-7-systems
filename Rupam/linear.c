//Linear Search  Program

#include <stdio.h>

#define SIZE 5 //size of the array

int 
LinearSearch(int arr[], int size, int key) {
    
    int i;
     //if any match, return 1
    for(i = 0; i < size; i++)
        if(arr[i] == key)
            return 1;

    return 0;
   }

int 
main()
   {
    //array of elements
    int page_number[SIZE] = {86, 91, 34, 50, 0};

    //key to search
    int key = 50;

    if(LinearSearch(page_number, SIZE, key) == 1)
        printf(" Search Found ");
    else
        printf(" Search Not Found ");

    return 0;
}
