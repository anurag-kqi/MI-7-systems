/* swap the two numbers without using third variable */

#include <bits/stdc++.h>
using namespace std;

int 
main()
{
int a = 13, b = 17;
cout <<"Before swap: a = " << a << " and b = " << b << endl;
a = a + b;
b = a - b;
a = a - b;
cout <<"After swap: a = " << a << " and b = " << b << endl;
return 0;
}
