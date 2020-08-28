#include <iostream>
#include <string.h>
using namespace std;

void print(string name) {
        cout<<"Name after call by reference: "<< name << endl;
}

int 
main () {
    string name;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"You entered: "<< name << endl;
    string &ref = name;
    ref = "Aishu";
    print(ref);
    return 0;
}