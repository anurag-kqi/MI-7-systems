#include <iostream>
using namespace std;

int 
main () {
    int n, i, flag = 0;
    cout << "Enter the Number to check Prime number or not: ";
    cin >> n;

    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            cout << n << " is not prime number" << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << n << " is a prime number" << endl;
    }
    
    return 0;
}