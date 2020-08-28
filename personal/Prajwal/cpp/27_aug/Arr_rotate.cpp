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

int main() {
    int arr[30], n, m, temp, i, j;
    cout << "Enter how many elements to add in array : " << endl;
    cin >> n;
    cout << "Enter elements : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter how many rotation you have to rotate : ";
    cin >> m;

    rotate(arr, m, n);
    return 0;
    
}