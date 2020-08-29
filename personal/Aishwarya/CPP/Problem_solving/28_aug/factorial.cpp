#include <iostream>
using namespace std;

int 
main () {
    int fact = 1, i, n;
    cout << "Enter the number that you want to find the factorial: ";
    cin >> n;
    if(n == 0) {
        cout << "Enter the number greater than 0" << endl;
        return 1;
    } 
    for (i = 1; i <= n; i++) {
        fact *= i;
    }
    cout << "Facorial of " << n << " is: ";
    cout << fact << endl;
    return 0;
}