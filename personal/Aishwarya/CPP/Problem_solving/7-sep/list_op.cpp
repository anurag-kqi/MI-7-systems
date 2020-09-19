// list operations

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main () {
    list<int> ls;
    int n, i, a;
    cout << "Enter number of elements to add in list: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        ls.push_back(a);
    }

    list<int>::iterator it;
    cout << "original list :" << endl;
    for (it = ls.begin(); it != ls.end(); it++)
        cout << "\t" << *it;
    cout << endl;
    cout << "first element : " << ls.front() << endl;
    cout << "last element : " << ls.back() << endl << endl;

    ls.push_front(1000);
    ls.push_back(2000);
    cout << "Modified list.." << endl;
    for (it = ls.begin(); it != ls.end(); it++)
        cout << "\t" << *it;
    cout << endl;
    cout << "first element : " << ls.front() << endl;
    cout << "last element : " << ls.back() << endl;

    return 0;
}