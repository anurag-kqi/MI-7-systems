/*cpp program of illustrate array name as pointer*/

#include <bits/stdc++.h> 
using namespace std; 
  
void array_pointer() 
{ 
    /* Declare an array */
    int val[3] = { 8, 10, 15}; 
    int *ptr; 
  
    /* Assign address of val[0] to ptr*/ 
    ptr = val ; 
    cout << "Elements of the array are: "; 
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2]; 
    return; 
} 

int 
main() 
{ 
    array_pointer(); 
    return 0; 
} 

