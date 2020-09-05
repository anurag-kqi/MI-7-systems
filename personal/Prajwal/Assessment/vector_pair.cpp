// C++ program to demonstrate vector of pairs 
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 
// #define N 3
#define MAX 50
int main() 
{ 
	
	vector< pair <int,int> > vect; 
    int arr[MAX], arr1[MAX], N;

    cout << "Enter size of array : ";
    cin >> N;
    cout << "Enter first array of size " << N <<  ":";
    for(int i = 0; i < N; i++) {
        cin >> arr[i];        
    }	
	
    cout << "Enter second array of size " << N <<  ":";
    for(int i = 0; i < N; i++) {
        cin >> arr1[i];        
    }
    	
	for (int i=0; i<N; i++) 
		vect.push_back( make_pair(arr[i],arr1[i]) ); 

	cout << "Before sorting.." << endl;
	for (int i=0; i<N; i++) 
	{ 		
		cout << vect[i].first << " " << vect[i].second << endl; 
	} 

    sort(vect.begin(), vect.end()); 
    cout << "After sorting.." << endl;
    for (int i=0; i<N; i++) 
	{ 		
		cout << vect[i].first << " " << vect[i].second << endl; 
	} 


	return 0; 
} 
