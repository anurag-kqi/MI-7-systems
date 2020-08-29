// swapping with two variable
#include <iostream>
using namespace std;
// logic
// swapping of two variables without taking third variable
// if a = 10 and b = 20  
// 1. add a = a + b  (a = 30)
// 2. sub b = a - b  (b = 10)
// 3. sub a = a - b  (a = 20)

int main () {
    int a, b;
    a = 10;
    b = 20;
    cout << "Before swapping...\n";
    cout << "a = " << a << " b = " << b << endl << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "After swapping...\n";
    cout << "a = " << a << " b = " << b << endl; 
    return 0;
}