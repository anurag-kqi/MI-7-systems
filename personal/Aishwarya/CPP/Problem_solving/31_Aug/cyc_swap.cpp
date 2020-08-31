#include<iostream>
using namespace std;

void cyc_swap(int *a, int *b, int *c) {
   int temp;
   temp = *b;
   *b = *a;
   *a = *c;
   *c = temp;
}
int 
main() {
   int a, b, c;

   cout << "Enter the values of 3 numbers: "<<endl;
   cin >> a >> b >> c;

   cout << "Number values before cyclic swapping..." << endl;
   cout << "a = "<< a <<endl;
   cout << "b = "<< b <<endl;
   cout << "c = "<< c <<endl;

   cyc_swap(&a, &b, &c);

   cout << "Number values after cyclic swapping..." << endl;
   cout << "a = "<< a <<endl;
   cout << "b = "<< b <<endl;
   cout << "c = "<< c <<endl;

   return 0;
}