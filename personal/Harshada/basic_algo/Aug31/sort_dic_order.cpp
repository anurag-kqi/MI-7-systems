// sort elements in lexicographical order (dictionary order)
#include <iostream>
using namespace std;


/* - sort using bubble sort method
   - first select first element and compair it with secong element
   - if (first > second) then swap them
   - then compair second and third element
   - if (second > third) then swap them
   - continue this untile the end of an array
*/
int main()
{
    int i, j;
    char arr[] = {'a', 'g', 'A', 'r', '5', 'p', 'f', '0', '1'};

    std::cout << "unsorted list" << '\n';
    for (i = 0; i < 9; i++) {
        std::cout << arr[i] << " ";
    }

    for (i = 0; i < 9; i++) {
        for (j = i; j < 9; j++) {
            if (arr[i] >= arr[j]) {
                int temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    std::cout << '\n';
    std::cout << '\n'<< "sorted list in Lesicographical order" << '\n';
    for (i = 0; i < 9; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
