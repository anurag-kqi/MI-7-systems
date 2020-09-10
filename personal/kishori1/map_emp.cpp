/*program of map emplace() and map maz_Size() function in STL*/

#include <bits/stdc++.h>
using namespace std;

int
main()
{
    //Declaring the map
    map <int, int> mp, mp2;

    //insert element in random number
    mp.emplace(50, 12);
    mp.emplace(10, 11);
    mp.emplace(50, 4);
    mp.emplace(500, 22);
    mp.emplace(10, 12);

    //print the element
    cout << "\nThe map element: \n"; 
    cout << "KEY \tELEMENT\n";
    for (auto itr = mp.begin(); itr!=mp.end();  ++itr) {
        cout << itr->first << '\t' << itr->second << '\n'; 
    }

    // max size of Non-empty map 
    cout << "The max size of mp is " << mp.max_size(); 
  
    // max size of Empty-map 
    cout << "\nThe max size of mp2 is " << mp2.max_size(); 
    return 0; 
}