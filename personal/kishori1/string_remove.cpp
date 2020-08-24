/*cpp program of removing double characters in string*/

#include <bits/stdc++.h> 
using namespace std; 
  
char *remove_duplicate(char str[], int n) 
{ 
   int index = 0;    
   for (int i = 0; i < n; i++) { 
         
     /*Check if str[i] is present before it */ 
     int j;   
     for (j = 0; j < i; j++) {  
        if (str[i] == str[j]) {
           break;
        }
     } 
       
     /* If not present, then add it*/
     if (j == i) { 
        str[index++] = str[i];
     } 
   } 
   return str; 
} 
  
int 
main() 
{ 
   char str[] = "bigg boss\n"; 
   int n = sizeof(str) / sizeof(str[0]); 
   cout << remove_duplicate(str, n); 
   return 0; 
} 