// cyclic swapping call by reference
#include <iostream>
using namespace std;

int swap (int *a, int *b, int *c) {
    int temp = *c;
    *c = *b;
    *b = *a;    
    *a = temp;
}

int main () {
    int a, b, c;
    cout << "Enter values for a, b and c : ";
    cin >> a >> b >> c;

    swap(&a, &b, &c);
    cout << "Cyclic swapping done.." << endl;
    cout << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl;
    return 0;
}