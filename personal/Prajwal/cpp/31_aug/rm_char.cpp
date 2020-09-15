// remove characters in string
#include <iostream>
using namespace std;

int main () {
    char ch[100];
    string new_string;
    cout << "Enter single word : ";
    cin.get(ch,100);

    for(int i = 0; ch[i]!='\0'; i++)
    {
        if(ch[i] >= 'a' && ch[i] <= 'z' || ch[i]>= 'A' && ch[i] <= 'Z'){
            new_string += ch[i];
        }
    }
    cout << "After operation string is : " << new_string << endl;

    return 0;
}