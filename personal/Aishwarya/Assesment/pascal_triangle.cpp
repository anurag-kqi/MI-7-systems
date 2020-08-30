#include <iostream>
using namespace std;

int 
main() {
    int row, col, i, j, s, k = 1;
    cout << "Enter the no. of rows that you want to print Pascal Triangle: ";
    cin >> row;
    for ( i = 0; i < row; i++) {
        for ( s = 0; s < row - i; s++) {
            cout << " ";
        }
        for ( j = 0; j <= i; j++) {
            cout << " ";
            if (j == 0 || i == 0) {
                k = 1;
            } else {
                cout << " ";
                k = k * (i - j + 1) / j;
            }
            cout << k;
        }
        cout << endl;
    }
    return 0;
}
    