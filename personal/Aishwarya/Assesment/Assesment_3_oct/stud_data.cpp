#include <iostream>
using namespace std;

struct student {
    char name[50];
    int roll;
    float age;
} s[5];

int 
main() {
    cout << "Enter information of students: " << endl;
    for(int i = 0; i < 5; ++i) {
        s[i].roll = i+1;
        cout << "For roll number: " << s[i].roll << "," << endl;

        cout << "Enter name: ";
        cin >> s[i].name;

        cout << "Enter age: ";
        cin >> s[i].age;

        cout << endl;
    }

    cout << "Displaying Information: " << endl;

    for(int i = 1; i < 5; ++i) {
        cout << "\nRoll number: " << i+1 << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Age: " << s[i].age << endl;
    }

    return 0;
}