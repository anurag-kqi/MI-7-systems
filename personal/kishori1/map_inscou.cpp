#include <bits/stdc++.h>
using namespace std;

int
main()
{
    map <int, int> mp;

    /*insert element with particular key value*/
    mp.insert({1, 100});
    mp.insert({20, 200});
    mp.insert({5, 300});
    mp.insert({6, 300});

    cout << "KEY\tELEMENT\n"; 
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) { 
        cout << itr->first << '\t' << itr->second << '\n'; 
    } 

    if (mp.count(20)) 
        cout << "\nThe key 20 is present\n"; 
    else
        cout << "The key 20 is not present\n"; 
  
    // checks if key 100 is present or not 
    if (mp.count(100)) 
        cout << "The key 100 is present\n"; 
    else
        cout << "The key 100 is not present\n"; 
  
    return 0; 

}
