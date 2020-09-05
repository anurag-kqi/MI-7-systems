#include <algorithm> 
#include <array> 
#include <iostream> 
#include <vector> 

using namespace std; 
  
void print(vector<array<int, 3> > vect) 
{ 
     for (array<int, 3> i : vect) { 
        for (auto x : i) 
            cout << x << " "; 
        cout << endl; 
    } 
} 
  
int main() 
{ 
    vector<array<int, 3> > vect; 
    vect.push_back({ 1, 2, 3 }); 
    vect.push_back({ 10, 20, 30 }); 
    vect.push_back({ 30, 60, 90 }); 
    vect.push_back({ 10, 20, 10 }); 
  
    sort(vect.begin(), vect.end()); 
  
    cout << "Vector of arrays after sorting: \n"; 
    print(vect); 
  
    return 0; 
} 
