#include<iostream>

using namespace std;

int main(){
   int n,num,i,r, rev_no,p;
   std::cout<<"enter Start number";
   std::cin>>n;
   std::cout<<"enter Last Number ";
   std::cin>>p;
    for (num = 1; num <= p; num++){
        rev_no = 0;
        n = num;
        while (n != 0){
            r = n % 10;
            rev_no = rev_no * 10 + r;
            n = n / 10;
        }
        if (num == rev_no)
        std::cout<<    num<< "   "   ;
    }
    return 0;
}
