#include <iostream>
using namespace std;

int main() {
    string str1, str2, str3;
    cout << "We are performing string concatination.." << endl;
    cout << "Enter str1 and str2 : ";
    cin >> str1 >> str2;
    cout << "str1 : " << str1 << endl << "str2 : " << str2 << endl;
    str3 = str1 + str2;
    cout << "Concatination of str1 and str2 is : " << str3 << endl;
}