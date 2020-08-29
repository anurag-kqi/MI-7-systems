#include <iostream>
using namespace std;

void count(int, int);
int palindrome (int);

int palindrome (int n) {
    int rev = 0;
    for (int i = n; i > 0; i /= 10) {
        rev = rev * 10 + i % 10;
    }
    return (n == rev);
    
}

void count(int min, int max) {
    for (int i = min; i <= max; i++) {
        if (palindrome(i)) {
            cout<< i << " ";
        }
    }
    
}

int 
main() {
    int min,max;
    cout<<"Enter range that you want to find palindrome numbers between them: ";
    cin>>min>>max;
    count(min,max);
    return 0;
}