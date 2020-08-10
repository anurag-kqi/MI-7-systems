//Program to Sorting array elements Using Bubble Sort

#include <stdio.h>

int
main()
 {
    int i, j, temp;
    int a[10] = {2, 3, 4, 1, 32, 22, 14, 55, 21, 31};

    for(i = 0; i < 10; i++) {
        for(j = i + 1; j < 10; j++) {
            if(a[j] < a[i]){
               temp = a[i];
               a[i] = a[j];
               a[j] = temp;
            }
        }
    }
    printf("sorted elemets are : \n");

    for(i = 0; i < 10; i++){
       printf("%d \n", a[i]);
    }
    return 0;
 }
