//Program to demonstrate insertion functionvof map

#include <iostream> 
#include <iterator> 
#include <map> 
  
using namespace std; 
  
int main() 
{ 
  
    // map is empty 
    map<int, int> demo; 
  
    // insert elements in random order 
    demo.insert(pair<int, int>(1, 400)); 
    demo.insert(pair<int, int>(2, 300)); 
    demo.insert(pair<int, int>(3, 600)); 
    demo.insert(pair<int, int>(4, 200)); 
   
    // printing the map demo
    map<int, int>::iterator it; 
    cout << "\nThe map demo is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (it =demo.begin(); it != demo.end(); ++it) { 
        cout << '\t' << it->first 
             << '\t' << it->second << '\n'; 
    } 
     return 0; 
} 
