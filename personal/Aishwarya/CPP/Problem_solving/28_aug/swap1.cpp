#include <iostream>
using namespace std;

int 
main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Numbers before swapping: ";
    cout << a << " " << b << endl;
    cout << "Numbers after swapping: ";
    a = a + b;
    b = a - b;
    a = a - b;
    cout << a << " " << b << endl;
    return 0;
}
