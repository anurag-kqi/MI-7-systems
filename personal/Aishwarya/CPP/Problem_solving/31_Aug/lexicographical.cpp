#include <iostream>
using namespace std;
#define MAX 50

int 
main() {
    string str[MAX], temp;
    int i, j, n;
    cout << "Enter the number of words: ";
    cin >> n;
    cout << "Enter words that you want to print in lexicographical order: " << endl;
    for( i = 0; i < n; i++) {
        cin >> str[i];
    }

    for( i = 0; i < n; i++) {
       for( j = i+1; j < n; j++) {
          if(str[i] > str[j]) {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
          }
        }
    }
    cout << "In lexicographical order: " << endl;

    for(int i = 0; i < n; i++) {
       cout << str[i] << endl;
    }
    return 0;
}