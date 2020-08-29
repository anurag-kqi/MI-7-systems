#include <iostream>
#include <string.h>
#include <algorithm> 
using namespace std; 

void per(string str, int l, int h) { 
	if (l == h) {
		cout << str << endl; 
    } else { 
		for (int i = l; i <= h; i++) { 
			swap(str[l], str[i]);  
			per(str, l+1, h); 
			swap(str[l], str[i]); 
		} 
	} 
} 
 
int 
main() { 
	string str;
    cout << "Enter any string: ";
    cin >> str; 
	int n = str.size(); 
    cout << "All possibole permutations of " << str << " are: " <<endl;
	per(str, 0, n-1); 
	return 0; 
} 

