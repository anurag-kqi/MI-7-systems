// access array using pointer
#include <iostream>
#define MAX 100
using namespace std;

int main () {
    int arr[MAX], n, i, *acc;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter "<< n << " elements : ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) {
        acc = &arr[i];
        cout << "array " << *acc << endl; 
    }
    return 0;
}