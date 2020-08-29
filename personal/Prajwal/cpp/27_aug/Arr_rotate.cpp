// Array rotation
#include <iostream>
using namespace std;

// logic
// take array with size n and insert elements
// take m as number rotations to perform rotations
// if m = 2, then 1st two elements will go to last
// display rotated array

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

int main() {
    int arr[30], n, m, temp, i, j;
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
    return 0;    
}