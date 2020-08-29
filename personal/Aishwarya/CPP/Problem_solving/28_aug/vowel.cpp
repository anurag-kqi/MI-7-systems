#include <iostream>
#include <string.h>
using namespace std;
#define MAX 50

int
main () {
    /*char s;
    cout << "Enter any character to check vowel or not: ";
    cin >> s;

    if ( s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' ) {
        cout << s << " is a vowel." << endl;
    } else {
        cout << s << " is not a vowel." << endl;
    }*/
    int cnt = 0, i;
    char str[MAX];
    cout << "Enter any string to find no. of vowels in that: ";
    cin >> str;
    for (i = 0; str[i] != '\0'; i++) {
        if ( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ) {
            cnt++;
        } 
    }
    cout << "No. of Vowels in string is: "<< cnt << endl;
    return 0;
}