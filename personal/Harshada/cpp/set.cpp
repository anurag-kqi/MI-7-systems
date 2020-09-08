//program to insert and delete elements from the set
#include <iostream>
#include <set>
using namespace std;

/* first create a variable of set
   add element using insert() function
  delete element using erase() function  */

int main()
{
    int n, i, num;
    set<int> set1;
    set<int>::iterator it_1, it_2;

    std::cout << "how many elements do you want to enter" << '\n';
    std::cin >> n;

    std::cout << "enter the elements" << '\n';
    for (i = 0; i < n; i++) {
        std::cin >> num;
        set1.insert(num);  // to insert element into set
    }
    // insertion of elements into set
    // set1.insert(20);
    // set1.insert(70);
    // set1.insert(60);
    // set1.insert(3);
    // set1.insert(54);

    // priting elements after insertion
    std::cout << "elements after insertion" << '\n';
    for (it_1 = set1.begin(); it_1 != set1.end(); it_1++) {
        std::cout << *it_1 << '\n';
    }

    // deleting elements from set
    //set1.erase(20);
    std::cout << "element to be deleted" << '\n';
    std::cin >> num;
    set1.erase(num);

    // printing after deletion of elements
    std::cout << "elements after deletion of element" << '\n';
    for (it_1 = set1.begin(); it_1 != set1.end(); it_1++) {
        std::cout << *it_1 << '\n';
    }
    return 0;
}
