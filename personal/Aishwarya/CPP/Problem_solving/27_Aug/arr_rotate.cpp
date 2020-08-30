#include <iostream>
using namespace std;

int 
main() { 
    int i, m, n, j; 
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
    cout << endl;
    return 0;
}
