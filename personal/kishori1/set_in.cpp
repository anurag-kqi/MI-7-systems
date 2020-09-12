/*program of set to insert the iterator insert() function in STL*/

#include <bits/stdc++.h> 
using namespace std; 

int
main() 
{ 
    set<int> sp; 
  
    // Function to insert elements 
    sp.insert(1); 
    sp.insert(4); 
    sp.insert(2); 
    sp.insert(5); 
    sp.insert(3); 
  
    cout << "The elements in set are: "; 
    for (auto it = sp.begin(); it != sp.end(); it++) {
        cout << *it << " "; 
    }
    return 0; 
} 