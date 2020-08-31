#include <iostream>
#include <string.h>
using namespace std;
#define MAX 50

int
main () {
    int vow, con, num, spc, i;
    vow = con = num = spc = 0;
    char str[MAX];
    cout << "Enter any string to find no. of vowels, numbers, consonants and special character in that: ";
    cin.getline(str, MAX);
    for (i = 0; str[i] != '\0'; i++) {
        if ( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ) {
            vow++;
        } else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            con++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            num++;
        } else if (str[i] == ' ') {
            spc++;
        }
    }
    cout << "No. of Vowels in string is: "<< vow << endl;
    cout << "No. of Consononets in string is: "<< con << endl;
    cout << "No. of Numbers in string is: "<< num << endl;
    cout << "No. of Spaces in string is: "<< spc << endl;

    return 0;
}