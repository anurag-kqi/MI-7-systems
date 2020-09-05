#include <algorithm> 
#include <array> 
#include <iostream> 
#include <vector> 

using namespace std; 

#define MAX 50
int main() { 
    vector< pair <int,int> > vect; 
    int arr[MAX], arr1[MAX], n, i; 
    cout << "Enter no. of elements in array: ";
    cin >> n;

    cout << "Enter elements in 1st array: ";
    for ( i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter elements in 2nd array: ";
    for ( i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    
    for ( i = 0; i < n; i++) {
        vect.push_back( make_pair(arr[i],arr1[i]) ); 
    }
  
    cout << "The vector before sort operation is:\n" ; 
    for (i = 0; i < n; i++) { 
        cout << vect[i].first << " " << vect[i].second << endl; 
  
    } 
  
    sort(vect.begin(), vect.end()); 
  
    cout << "The vector after sort operation is:\n" ; 
    for (int i=0; i<n; i++) { 
        cout << vect[i].first << " " << vect[i].second << endl; 
    } 
  
    return 0; 
} 