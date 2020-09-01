#include <iostream>
#include <string.h>
using namespace std;

int 
main() {
    string str;
    string temp = "";

    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = 0; i < str.size(); ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            temp = temp + str[i];
        }
    }
    str = temp;
    cout << "String after removing all characters except alphabates: "<< str << endl;
    return 0;
}