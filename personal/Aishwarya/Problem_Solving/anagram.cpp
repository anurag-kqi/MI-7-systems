#include <iostream> 
#include <string.h>
#include <algorithm>
using namespace std; 

bool anagram(string, string);

bool anagram(string str1, string str2) 
{ 
    int n1 = str1.length(); 
    int n2 = str2.length(); 
  
    
    if (n1 != n2) 
        return false; 
  
    sort(str1.begin(), str1.end()); 
    sort(str2.begin(), str2.end()); 
  
    for (int i = 0; i < n1; i++) 
        if (str1[i] != str2[i]) 
            return false; 
  
    return true; 
} 
   
int main() 
{ 
    string str1, str2;
    int ch,res;
    cout<<"Enter two strings: ";
    cin>>str1>>str2; 
    res = anagram(str1, str2);
    if (res == true) 
        cout << "The two strings are anagram of each other\n"; 
    else
        cout << "The two strings are not anagram of each other\n"; 
  
    return 0; 
} 