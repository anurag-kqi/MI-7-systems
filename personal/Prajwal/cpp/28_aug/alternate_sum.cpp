// alternate_no_addition
#include <iostream>
using namespace std;
// logic 
// addition of alternate numbers in array
// if arr[] = {1, 2, 3, 4, 5}
// then sum of(1 + 3 + 5) = 9 

int main () {
    int arr[100], n, i, sum = 0;
    cout << "Enter how many number you have insert in array : ";
    cin >> n; // n: size of array
    cout << "\nEnter elements : ";
    // input array elements
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }    
    
    for (i = 0; i < n; i++) {
        // if element is at odd position then
        // calculate sum of alternate elements
        if(arr[i] % 2 != 0) {
            sum = sum + arr[i];
        }
    }
    cout << "sum = " << sum << endl;
    return 0;
}