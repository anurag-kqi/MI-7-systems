#include <iostream> 
using namespace std; 
  
int binarySearch(int arr[], int low, int high, int key) 
{ 
    if (high >= low) { 
        int mid = (low + high) / 2; 
  
        if (arr[mid] == key) 
            return mid; 
  
        if (arr[low] <= arr[mid]) {
            if (key >= arr[low] && key <= arr[mid]) { 
                return binarySearch(arr, low, mid - 1, key); 
            }
            return binarySearch(arr, mid + 1, high, key);
        }
        if (key >= arr[mid] && key <= arr[high]) {
                    return binarySearch(arr, mid + 1, high, key); 
        }
        return binarySearch(arr, low, mid - 1, key); 
    } 
  
    return -1; 
} 
  
int 
main() { 
    int i, low, high,key,m,n,j; 
    cout << "Enter number of elements: "; 
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the number for rotation: ";
    cin >> m;
    cout << "Array after rotation: "; 
    for (i = 0; i < m; i++) {
        int temp = arr[0];
        for (j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[j] = temp;
    }
    

    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nEnter the key to search: ";
    cin >> key;
    int result = binarySearch(arr, 0, n - 1, key); 
    if (result == -1) {
        cout << "Element not found..." << endl;
    } else {
        cout << "Element is found at index: " << result << endl;
    }                
    return 0; 
} 