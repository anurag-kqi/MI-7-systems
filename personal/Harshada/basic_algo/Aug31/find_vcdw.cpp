// program to find number of vowels, consonants,
// special symbols, digits and white spaces

#include <iostream>
using namespace std;

void find(string str)
{
    int i, vow = 0, cons = 0, dig = 0, ws = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            dig++;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') ||
                 (str[i] >= 'A' && str[i] <= 'Z')) {

            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
                str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
                str[i] == 'O' || str[i] == 'U') {

                vow++;
            }
            else
                cons++;
        }
        else if (str[i] == ' ') {
            ws++;
        }
    }
    std::cout << "digits = " << dig << '\n';
    std::cout << "vowels = " << vow << '\n';
    std::cout << "consonants = " << cons << '\n';
    std::cout << "white spaces = " << ws << '\n';
}

int main()
{
    string str;

    std::cout << "enter a string" << '\n';
    getline (cin, str);

    find(str);
    return 0;
}
