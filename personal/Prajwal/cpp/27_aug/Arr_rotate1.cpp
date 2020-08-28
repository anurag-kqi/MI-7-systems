#include <iostream>
using namespace std;

void rotate(int arr[], int m, int n) {
    int temp, i, j;
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
}

int bsearch(int arr[], int l, int r, int key) {    

    if (r >= l) { 
        int mid = (l + r) / 2; 
  
        
        if (arr[mid] == key) 
            return mid; 
  
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
    cin >> n;
    cout << "Enter elements : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter how many rotation you have to rotate : ";
    cin >> m;
    rotate(arr, m, n);    
    
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