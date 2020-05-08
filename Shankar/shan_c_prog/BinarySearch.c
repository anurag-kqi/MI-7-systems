
// C program to implement Binary Search 

#include <stdio.h> 
#define MAX_SIZE 100  // Maximum array size  

//function to search element
int 
binarySearch(int arr[], int left, int right, int toSearch) 
{ 
    if (right >= left) { 
        int mid = left + (right - left) / 2; 
  
        // If the element is present at the middle  
        if (arr[mid] == toSearch) { 
            return mid; 
        }
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > toSearch) { 
            return binarySearch(arr, left, mid - 1, toSearch); 
        }
        // Else the element can only be present in right subarray

        else { 
        return binarySearch(arr, mid + 1, right, toSearch); 
        }
    } 
  
    //when element is not present in array 
    return -1; 
} 
  
int 
main(void) 
{ 
    int arr[MAX_SIZE], size, i, toSearch; 

    /* Input size of array */
    printf("Enter size of array: ");
    scanf("%d", &size);

    /* Input elements of array */
    printf("Enter elements in array: ");
    for (i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &toSearch);

    int result = binarySearch(arr, 0, size - 1, toSearch); 
    (result == -1) ? printf("Element is not present in array") 
                   : printf("Element is present at index %d", result); 
    return 0; 
} 

