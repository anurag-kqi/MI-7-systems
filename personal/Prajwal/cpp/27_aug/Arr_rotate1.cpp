#include <iostream>
using namespace std;

int bsearch(int arr[], int l, int r,int key) {    

    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        
        if (arr[mid] == key) 
            return mid; 
  
        
        if (arr[mid] > key) 
            return bsearch(arr, key, mid - 1); 
  
        
        return binarySearch(arr, key, mid + 1);    
}

int main() {
    int arr[30], n, m, temp,temp1[30], i, j, key;
    cout << "Enter how many elements to add in array : " << endl;
    cin >> n;
    cout << "Enter elements : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter how many rotation you have to rotate : ";
    cin >> m;

    
    for(i = 0; i < m; i++) {
        temp = arr[0];
        // cout << temp << endl;
        for(j = 0; j < n-1; j++) {
            arr[j] = arr[j+1];
        }
        arr[j] = temp;        
    }
    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    } 
    cout << "Enter element to search : ";
    cin >> key;
    bsearch(arr, 0, n-1, key);  
    return 0; 
}