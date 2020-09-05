#include <algorithm> 
#include <array> 
#include <iostream> 
#include <vector> 
#include <queue>
#include <stack>
using namespace std; 

bool checkSorted(int n, queue<int>& q) 
{ 
    stack<int> st; 
    int expected = 1; 
    int fnt; 
   
    while (!q.empty()) { 
        fnt = q.front(); 
        q.pop(); 
  
        if (fnt == expected) 
            expected++; 
  
        else { 
            if (st.empty()) { 
                st.push(fnt); 
            } 
  
            else if (!st.empty() && st.top() < fnt) { 
                return false; 
            } 
  
            else
                st.push(fnt); 
        } 
  
        while (!st.empty() && st.top() == expected) { 
            st.pop(); 
            expected++; 
        } 
    } 
  
    if (expected - 1 == n && st.empty()) 
        return true; 
  
    return false; 
} 
  
int main() 
{ 
    int n, i;
    queue<int> q; 
    cout << "How many elements you want to push into queue? : ";
    cin >> n;
    cout << "Enter elements: ";
    for (i = 0; i < n; i++) {
        cin >> i;
        q.push(i);
    }
  
    (checkSorted(n, q) ? (cout << "Yes") : (cout << "No")); 
  
    return 0; 
} 