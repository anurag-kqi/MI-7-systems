// Program to perform operation of queue

#include <iostream> 
#include <queue> 
using namespace std; 
  
int main() 
{ 
    int c = 0; 
    // Empty Queue 
    queue<int> myqueue; 
    myqueue.push(10); 
    myqueue.push(20); 
    myqueue.push(30); 
    myqueue.push(40); 
    myqueue.push(50); 

    while (!myqueue.empty()) { 
        myqueue.pop(); 
        c++; 
    } 
    cout << c; 
} 

