
/* program to implement two-dimensional map and
inserting value through insert() */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    // First key type is a string
    map<string, map<int, int> > m;

    map<string, map<int, int> >::iterator itr;
    map<int, int>::iterator ptr;

    // to insert element into map
    m.insert(make_pair("first", map<int, int>()));
    m["first"].insert(make_pair(0, 5));

    m.insert(make_pair("second", map<int, int>()));
    m["second"].insert(make_pair(1, 10));

    m.insert(make_pair("third", map<int, int>()));
    m["third"].insert(make_pair(2, 20));

    for (itr = m.begin(); itr != m.end(); itr++) {

        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            cout << "First key is " << itr->first
                 << " And second key is " << ptr->first
                 << " And value is " << ptr->second << endl;
        }
    }
    return 0;
}
