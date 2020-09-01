// program to access elements of an array using pointer

#include <iostream>
using namespace std;

/* the address of first element of an array is stored at ptr
      ptr = &arr[0];
   to access the second element increment ptr value by 1
      ptr++
      ptr++ = ptr + sizeof(int);
*/
int main()
{
    int arr[] = {54, 4, 8, 31, 6, 80};
    int* ptr = &arr[0];

    for (int i = 0; i < 6; i++) {
        std::cout << " " << *ptr;  //print value at the address stored at ptr
        ptr++;  // increment the address stored at ptr
    }
    return 0;
}
