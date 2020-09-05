// Vector array sort
#include <algorithm> 
#include <array> 
#include <iostream> 
#include <vector> 
using namespace std; 

#define N 3 


void print(vector<array<int, N> > vect) 
{     
	for (array<int, N> i : vect) { 
		for (auto x : i) 
			cout << x << " "; 
		cout << endl; 
	} 
} 

int main() 
{ 
	vector<array<int, N> > vect; 
	vect.push_back({ 1, 2, 3 }); 
	vect.push_back({ 10, 20, 30 }); 
	vect.push_back({ 30, 60, 90 }); 
	vect.push_back({ 10, 20, 10 }); 

	cout << "Vector of arrays before sorting: \n"; 
	print(vect); 
	
	sort(vect.begin(), vect.end()); 
	cout << "Vector of arrays after sorting: \n"; 
	print(vect); 	
	return 0; 
} 
