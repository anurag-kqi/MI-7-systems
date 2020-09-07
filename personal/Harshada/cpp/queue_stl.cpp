/*program of queue's different function in stl*/

#include <iostream>
#include <queue>
using namespace std;

/*program illustrate about the function of queue 
like push(), size(), pop(), front() and back()*/

void showq(queue <int> g)
{
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}
 int
 main()
 {
     queue <int> gquiz;

     /*insert the element in queue*/
     gquiz.push(11);
     gquiz.push(12);
     gquiz.push(20);
     gquiz.push(31);

     cout << "the queue gquiz is: ";
     showq(gquiz);

     cout << "\ngquiz.size() : " << gquiz.size(); 
     cout << "\ngquiz.front() : " << gquiz.front(); 
     cout << "\ngquiz.back() : " << gquiz.back(); 
  
     cout << "\ngquiz.pop() : "; 
     gquiz.pop(); 
     showq(gquiz); 
  
     return 0; 
} 
     
