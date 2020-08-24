/*Program of binary search in cpp*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

      /*If the element is present at the middle return mid*/
        if (arr[mid] == x)
            return mid;

      /*If element is smaller than mid, then narrow to left interval*/
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

      /*Else the element can only be present in right interval*/
        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int
main(void)
{
    int arr[] = {2, 8, 5, 22, 8};
    int x = 22;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array\n"
                   : cout << "Element is present at index " << result;
    return 0;
}
