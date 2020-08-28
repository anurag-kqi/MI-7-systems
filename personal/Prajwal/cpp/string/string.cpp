#include <iostream>
using namespace std;

void print_my_name(string name) {
    cout << "My name is : " << name << endl;
}

void print_my_name1(string name) {
    cout << "My name 1 is : " << name << endl;
}

int main () {
    string name;
    cout << "Enter Your name here : ";
    cin >> name;
    cout << name.length() << endl;
    cout << "you entered : " << name << endl;
    string &ref = name;
    ref = "Amber";
    print_my_name(ref);
    print_my_name1(name);

    string str = "soft";
    ref.append(str);
    cout << "ref = " << ref << endl;
    return 0;
}