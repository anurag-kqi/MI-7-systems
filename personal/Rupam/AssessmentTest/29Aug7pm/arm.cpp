#include<iostream>
using namespace std;

int main()
{
	int n,num, a, rev=0;
	cout<<"Enter Any number";
	cin>>num;
	n=num;

	 while(n!=0)
	 {
		 a=n%10;
		 rev=rev+(a*a*a);
		 n=n/10;
	 }
	 if(rev == num)
	 {
	 cout<< num <<" is Armstrong Number"<<endl;
	
	 }
	 else{
		cout<< num <<"is not Armstrong Number"<<endl;
	 }
return 0;
}
