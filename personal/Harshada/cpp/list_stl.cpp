/*CPP program to return a reference to first and last element in list*/ 

 #include <bits/stdc++.h>
 using namespace std;

 int
 main()
 {
     /*creating the list*/
     list <int> demotest;

     /*add the element in list*/
     demotest.push_back(10);
     demotest.push_back(20);
     demotest.push_back(15);
     demotest.push_back(52);

     /*first element*/
     int first_ele = demotest.front();
     cout << "first element of list is: " << first_ele <<endl;

     int last_ele = demotest.back();
     cout << "last element of list is: " << last_ele <<endl;
     
     return 0;
 }