// factorial
#include <iostream>
using namespace std;
// logic
// find the factorial of number n
// take input element to find factorial 
// calculate factorial and display it

int main () {
    int n, i, fact = 1;
    // n : number to find factorial
    cout << "Enter number you have to find factorial : ";
    cin >> n;
    // calculate factorial
    for(i = 1; i <= n; i++) {
        // if (n= 5), fact =  1 * 2 * 3 * 4 * 5
        fact = fact * i;
        
    }
    cout << "factorial of " << n << " = "<< fact << endl;
    return 0;
}