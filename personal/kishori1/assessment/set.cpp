/*C++ code to demonstrate the working of insert() on set*/

#include <bits/stdc++.h>
using namespace std;

int
main()
{
    set <int> sp;

    sp.insert(10);
    sp.insert(40);
    sp.insert(11);
    sp.insert(5);
    sp.insert(8);

    cout << "set elements are: ";

    for(auto itr = sp.begin(); itr !=sp.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}
