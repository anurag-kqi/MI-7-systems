// queue operations

#include <iostream>
#include <queue>
using namespace std;

int main () {

    queue <int> q;
    int a;
    cout << "Enter elements to enqueue in queue and '0' to stop enquing:" << endl;
    cin >> a;
    while(a) {
        q.push(a);
        cin >> a;
    }
    cout << "size of queue is : " << q.size() << endl; 
    cout << "first element in queue: " << q.front() << endl;
    cout << "Last element in queue: " << q.back() << endl;
    
    cout << "DeQueue operation in queue : "<< endl;
    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    cout << "After dequeue.." << endl;
    cout << "size of queue is : " << q.size() << endl; 
    return 0;
}