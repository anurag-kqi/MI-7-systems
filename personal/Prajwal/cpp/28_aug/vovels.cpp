// vovels 
#include <iostream>
using namespace std;
// logic
// determine is input character is vovel or not
// take a single character as input
// compair it and if vovel print else print it is consonent

int main () {
    char ch;
    cout << "Enter character to search whether it is vovel or not : ";
    cin >> ch;
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
    || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        cout << ch << " is vovel" << endl;
    }
    else{
        cout << ch << " is consonent" << endl;
    }
    return 0;
}