//Program to demonstrate operation of set

#include <iostream> 
#include <set> 
#include <iterator> 
  
using namespace std; 
  
int main() 
{ 
    // empty set container 
    set <int, greater <int> > s1;         
  
    // insert elements in random order 
    s1.insert(400); 
    s1.insert(300); 
    s1.insert(600); 
    s1.insert(200); 
    s1.insert(500); 
   
    // printing set s1 
    set <int, greater <int> > :: iterator it; 
    cout << "\nThe set s1 is : "; 
    for (it = s1.begin(); it != s1.end(); ++it) 
    { 
        cout << '\t' << *it; 
    } 
    cout << endl; 
  
    // assigning the elements from s1 to s2 
    set <int> s2(s1.begin(), s1.end()); 
  
    // print all elements of the set s2 
    cout << "\nThe set s2 after assign from s1 is : "; 
    for (it = s2.begin(); it != s2.end(); ++it) 
    { 
        cout << '\t' << *it; 
    } 
    cout << endl; 
  
    return 0; 
  
} 