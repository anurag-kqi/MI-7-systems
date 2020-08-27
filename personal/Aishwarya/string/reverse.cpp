#include<iostream>
#include<string.h>
using namespace std;

void reverse(string& str) {
    int i = str.length();
    while(i>=0) {
        cout << str[i];
        i--;
    }
    cout<<endl;
}

int 
main()
{        
    string str;
    cout<<"Enter anything: ";
    cin>>str;
    cout<<"\nYou entered: "<< str << endl;
    cout<<"Reverse string is: ";
    reverse(str);
    return 0;
}