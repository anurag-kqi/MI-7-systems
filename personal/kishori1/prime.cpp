/*check the number is prime is not*/

#include <bits/stdc++.h>
using namespace std;

int 
main()
{
int i, n;
for (i = 2; i < n; i++) {
  cout << "enter the number:";
  cin >> n;
  if (n % i == 0) {
    cout << n <<" is not prime number ";
    break;
  }
  else {
    cout << n <<" is prime number ";
    break;
  }
}
return 0;
}


