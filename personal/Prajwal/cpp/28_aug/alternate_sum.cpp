#include <iostream>
using namespace std;

int main () {
    int arr[100], n, i, sum = 0;
    cout << "Enter how many number you have insert in array : ";
    cin >> n;
    cout << "\nEnter elements : ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }    
    // for (i = 0; i < 7; i++) {
    //     cout << arr[i] << " ";
    // }
    // sum = arr[0];
    // cout << "\nsum = " << sum << endl;
    for (i = 0; i < n; i++) {
        if(arr[i] % 2 != 0) {
            sum = sum + arr[i];
        }
    }
    cout << "sum = " << sum << endl;
    return 0;
}