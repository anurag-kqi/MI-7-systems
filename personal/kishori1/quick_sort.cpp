/*quick sort programin cpp*/

#include <bits/stdc++.h> 
using namespace std;  
  
/*A utility function to swap two elements */ 
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; /* pivot  */

    /*Index of smaller element*/
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++)  
    {  
        /* If current element is smaller than the pivot  */
        if (arr[j] < pivot)  
        {  
            i++; 
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
 
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
int 
main()  
{  
    int n, i;
    cout << "enter number of element: ";
    cin >> n;
    int arr[n];
    cout << "enter element: " << endl;
    for(int i = 0;i < n; i++) {
      cin >> arr[i];
    }

    cout <<"array before sorting: ";
    printArray(arr, n);
    quickSort(arr, 0, n - 1); 
    cout << "array after sorting: ";
    printArray(arr, n);
}  
  