#include <iostream>
using namespace std;
#define MAX 50

int 
main () {
    int a[MAX][MAX], b[MAX][MAX], n, m, i, j, res[MAX][MAX];
    cout << "Enter the number of rows and coloumns: ";
    cin >> n >> m;
    cout << "Enter the elements for matrix 1: ";
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < m; j++) {
            cin >> a[i][j];
        } 
    }
    cout << "Enter the elements for matrix 2: ";
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < m; j++) {
            cin >> b[i][j];
        }
        
    }
    cout << "Matrix 1: " << endl;
    for (i = 0; i < n; i++) {
        cout << endl;
        for (j = 0; j < m; j++) {
            cout << " ";
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << "Matrix 2: " << endl;
    for (i = 0; i < n; i++) {
        cout << endl;
        for (j = 0; j < m; j++) {
            cout << " ";
            cout << b[i][j];
        }
        cout << endl;
    }
    cout << "Multiplication is: " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            res[i][j] = 0;
            for (int k = 0; k < m; k++) {
                res[i][j] += (a[i][k] * b[k][j]);
            }
            
        }
    }
    for (i = 0; i < n; i++) {
        cout << endl;
        for (j = 0; j < m; j++) {
            cout << " ";
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;    
}