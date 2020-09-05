/*sorting vector of arrays*/

#include <algorithm> 
#include <array> 
#include <iostream> 
#include <vector> 
using namespace std; 
  
#define N 3 
  
/* Function to print vector of arrays*/ 
void print(vector<array<int, N> > vect) 
{ 
    for (array<int, N> i : vect) { 
        for (auto x : i) 
            cout << x << " "; 
        cout << endl; 
    } 
} 

int 
main() 
{ 
    vector<array<int, N> > vect; 
    vect.push_back({ 1, 2, 3 }); 
    vect.push_back({ 10, 20, 30 }); 
    vect.push_back({ 30, 60, 90 }); 
    vect.push_back({ 10, 20, 10 }); 

/*Taking another input vector array*/
    // vector<array<int, N> > vect; 
    // vect.push_back({ 7, 2, 9 }); 
    // vect.push_back({ 5, 20, 11 }); 
    // vect.push_back({ 6, 16, 19 }); 
    
      cout << "Vector of arrays"
         << " before sorting: \n"; 
    print(vect); 
  
    /* defined in algorithm header in C++ STL */
    sort(vect.begin(), vect.end()); 
  
    cout << "Vector of arrays"
         << " after sorting: \n"; 
    print(vect); 
  
    return 0; 
} 