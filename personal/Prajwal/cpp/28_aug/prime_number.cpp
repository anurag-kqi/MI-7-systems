// Prime_number
#include <iostream>
using namespace std;

int main() {
    int n, m = 0, i, flag = 0;
    cout << "Enter number to check whether prime or not prime number : ";
    cin >> n;
    m = n/2;
    for(i = 2; i <= m; i++) {
        if (n % i == 0) {
            cout << n << " is not prime number\n";
            flag = 1;
            break;
        }        
    }
    if(flag == 0)
        cout << n << " is Prime number\n";
    
    
    return 0;
}