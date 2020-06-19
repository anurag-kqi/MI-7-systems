//Program to find sum of elements in a given array using function to return sum of elements.

#include <stdio.h> 
   
int 
sum(int arr[], int n)  
   {  
    int sum = 0;   
    for (int i = 0; i < n; i++)  
    sum = sum+arr[i];  
    return sum;  
    }  
 
int 
main()  
   {  
   int arr[] = {12, 3, 4, 15};  
   int n = sizeof(arr) / sizeof(arr[0]);  
   printf("Sum of given array is %d:" , sum(arr,n));  
   return 0;  
  }  
