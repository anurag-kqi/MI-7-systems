/*Program of cpp to find square root of number*/

#include<bits/stdc++.h> 
using namespace std; 
 
int sqrt(int N) 
{  
    if (N == 0 || N == 1) 
    return N; 
  
    int start = 1, end = N, ans; 
    while (start <= end) 
    { 
      int root = (start + end) / 2;
      if (root * root == N)
        return root;

      if (root * root < N) {
        start = root + 1;
        ans = root;
      }
      else 
        end = root - 1; 
    } 
    return ans; 
}  

int 
main() 
{ 
    int N = 4;
    cout << sqrt(N) << endl; 
    return 0; 
} 