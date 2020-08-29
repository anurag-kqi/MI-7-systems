// Fibonaci series

#include <iostream>
using namespace std;

// logic
// addition of first two no is third element, then 2nd and 3rd element addition as 4th element and so on.. 
// taking two numbers t1 and t2 as 0 and 1
// display t1 and t2
// take another variable (t3) and store (t1 + t2)
// swapping t1 and t2 
// display t3 for n time

int main() {
    int t1 = 0; 
    int t2 = 1;
    int n, t3;
    cout << "Enter how many elements to add in array : " << endl;
    cin >> n; // n: size of array
    for(int i = 1; i <= n; i++) {
        // compair and display t1
        if(i == 1) {
            cout << t1 << " ";
            continue;
        }

        // compair and display t2
        if(i == 2) {
            cout << t2 << " ";
            continue;
        } 

        t3 = t1 + t2; // addtion of t1 & t2
        t1 = t2; // swapping
        t2 = t3; // swapping
        cout << t3 << " ";
    }
    return 0;
}