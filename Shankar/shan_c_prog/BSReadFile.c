// C program to implement Binary Search 

#include <stdio.h> 
#define MAX_SIZE 100  // Maximum array size  

//function to sort element

int 
sortArr(int arr[], int len)
{
    int temp = 0;    
    int length = len;    
   
    //Sort the array in ascending order    
    for (int i = 0; i < length; i++) {     
        for (int j = i+1; j < length; j++) {     
           if(arr[i] > arr[j]) {    
               temp = arr[i];    
               arr[i] = arr[j];    
               arr[j] = temp;    
           }     
        }     
    }    
            
    //Displaying elements of array after sorting    
    printf("\n\nSorted array = ");    
    for (int i = 0; i < length; i++) {     
        printf("%d ", arr[i]);    
    }    
}

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
    int len=0;

    FILE *fp1;      //file pointer

    for (i = 0; i < 50; i++) {   //initialize array with 0
    arr[i] = 0;
    }
    i = 0;      
    if (( fp1 = fopen("student.txt","r" )) == NULL) {
    printf("votes.txt failed to open\n");
    return 1;
    }
    else {
	printf("\nUnsorted array = ");
        while (( fscanf(fp1, "%d", &arr[i] )) != EOF){ //scanf and check EOF
            printf("%d ", arr[i]);
            i++;
	    len++;
        }
    }

    //calculate array length
    printf("\n\nlength of array: %d", len);

    //calling sort array function
    sortArr(arr, len);

    printf("\n\nEnter element to search : ");
    scanf("%d", &toSearch);

    int result = binarySearch(arr, 0, len - 1, toSearch); 
    (result == -1) ? printf("\nElement is not present in array\n") 
                   : printf("\nElement is present at index %d\n", result); 
    return 0; 
}
