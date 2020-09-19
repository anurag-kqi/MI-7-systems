#include <iostream>
using namespace std;

int
main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << "String after  " << endl;
    int len = str.length();
    str[len+1] = '\0';
    for (int i = 0; i < len; i++) {
        if (str[i] != str[i+1] && str[i+1] != str[i]) {
            cout << str[i];
        }else if (str[i] == str[i+1]) {
            cout << str[i] << "*";
        }
    }
    return 0;
}