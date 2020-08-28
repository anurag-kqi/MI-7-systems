#include <iostream>
using namespace std;

void addition(int a, int b) {
    int c = a + b;
    cout << "c = " << c << endl;
}

int main() {
    int a, b;
    cout << "Enter values for a and b : ";
    cin >> a >> b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    addition(a,b);
}