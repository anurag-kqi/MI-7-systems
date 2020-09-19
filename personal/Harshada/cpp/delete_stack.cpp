
/* C++ code to delete middle of a stack
   without using additional data structure. */
#include<bits/stdc++.h>
using namespace std;

/* - first pop all elements of the stack
   - then push elements except the middle element*/

// Deletes middle of stack
void deleteMid(stack<char> &st, int n,
                          int curr=0)
{
   // If stack is empty or all items are traversed
   if (st.empty() || curr == n)
     return;

   // Remove top item
   int x = st.top();
   st.pop();

   // Remove other items
   deleteMid(st, n, curr+1);

   // Put all items back except middle
   if (curr != n/2) {
     st.push(x);
   }
}

//Driver function to test above functions
int main()
{
    stack<char> st;

    //push elements into the stack
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    st.push('5');
    st.push('6');
    st.push('7');

    deleteMid(st, st.size());

    // Printing stack after deletion of middle.
    while (!st.empty())
    {
        char p=st.top();
        st.pop();
        cout << p << " " << endl;
    }
    return 0;
}
