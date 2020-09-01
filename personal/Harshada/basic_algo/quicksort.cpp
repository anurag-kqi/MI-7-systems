/* Cpp implementation QuickSort */
#include <iostream>
using namespace std;

/* - first select a element as pivot
   - place it at it's correct position as smaller elements are on left side and
     greater are on right side*/

// function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to partition array
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // higher element is pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* arr[] - Array to be sorted,
   low - Starting index,
   high - Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array //
void printArray(int arr[], int size)
{
    int i;

    std::cout << "Sorted array: " << '\n';
    for (i=0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << '\n';
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};

    int n = sizeof(arr)/sizeof(arr[0]);  //calculate number elements in array

    quickSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}
