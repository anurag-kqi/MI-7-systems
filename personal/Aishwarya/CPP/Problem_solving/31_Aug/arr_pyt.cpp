#include <iostream>
using namespace std;
#define MAX 50

int 
main () {
    int i, a[MAX],n;
    cout << "Enter number of elements that you want to enter in array: ";
    cin >> n;
    int *ptr = & a[0];
    cout << "Enter elements: " << endl;
    for ( i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Displaying Elements using Pointer: " << endl;
    for ( i = 0; i < n; i++) {
        cout << *ptr << endl;
        ptr ++;
    }
    return 0;
    
}