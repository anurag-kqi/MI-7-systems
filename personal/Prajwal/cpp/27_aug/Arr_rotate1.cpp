#include <iostream>
using namespace std;

// logic
// take array with size n and insert elements
// take m as number rotations to perform rotations
// if m = 2, then 1st two elements will go to last
// display rotated array
// take input element to search in rotated array
// searching : using binary search
// display is input element is present or not

void rotate(int arr[], int m, int n) {
    int temp, i, j;
    for(i = 0; i < m; i++) {
        // copy first element of array to temp var
        temp = arr[0];
        //shifting one by one element to left 
        for(j = 0; j < n-1; j++) {
            arr[j] = arr[j+1];
        }
        // put first element of array at last
        arr[j] = temp;        
    }
    // display rotated array
    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    }    
}

// binary search
int bsearch(int arr[], int l, int r, int key) {    

    if (r >= l) {
        // find mid 
        int mid = (l + r) / 2; 
  
        // check if key is present at mid
        if (arr[mid] == key) 
            return mid; 

        //compair left and mid value
        if (arr[l] <= arr[mid]){
            if (arr[mid] >= key && key >= arr[l]) 
                return bsearch(arr, l, mid - 1, key); 
            return bsearch(arr, mid + 1, r, key); 
        }  
        
        if(key >= arr[mid] && key <= arr[r]) {
            return bsearch(arr, mid + 1, r, key);
        }
        return bsearch(arr, l, mid - 1, key); 
    }
    return -1;   
}

int main() {
    int arr[30], n, m, temp,temp1[30], i, j, key;
    cout << "Enter how many elements to add in array : " << endl;
    cin >> n; // n: size of array
    cout << "Enter elements : ";
    // input n elements to array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // m: number of rotations
    cout << "Enter how many rotation you have to rotate : ";
    cin >> m;
    rotate(arr, m, n);    
    
    // enter element to search
    cout << "\nEnter element to search : ";
    cin >> key;
    int result = bsearch(arr, 0, n-1, key); 
    if (result == -1) {
        cout << "Element not found..\n";
    }
    else {
        cout << "Element found..\n";
    } 
    return 0; 
}