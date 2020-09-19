#include <iostream>
#include <string>
#define MAX 100
using namespace std;

int main (){
    string str;
    cout << "Enter a string:";
    cin >> str;
    for(int i = 0; i < str.length(); i++) {
        if (str[i+1] == str[i]) {
            cout << str[i] << "*";
            // continue;
        }
        else {
            cout << str[i];
        }
    }
    return 0;
}