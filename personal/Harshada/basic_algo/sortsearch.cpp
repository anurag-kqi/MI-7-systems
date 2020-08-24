#include <iostream>
using namespace std;

int* bsort(int a[10]);
//void qsort(int []input, int n);
bool bsearch(int *arr);

int
main ()
{
    bool result;
    int i, ele, *arr;
    int a[10] = {10, 5, 4, 26, 86, 3, 14, 0, 32, 8};

    // to display input list
    std::cout << "\ninput list...\n";
    for (i = 0; i < 10; i++) {
        std::cout << a[i] << "\t";
    }

    //bubble sort
    arr = bsort(a);

    //Quick sorting
    //qsort(a);

    //binary search
    result = bsearch(arr);
    if (result == true) {
        std::cout << "number is found" << '\n';
    }
    else {
        std::cout << "number is not found" << '\n';
    }

    return 0;
}

//bubble sort
int* bsort(int a[10])
{
    int i, j, temp, pass = 0;
    std::cout << "\n";

    for (i = 0; i < 10; i++) {
        for (j = (i+1); j < 10; j++) {
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        pass++;
    }

    std::cout << "\n\nsorted list by bubble sort " << "\n";
    for(i = 0; i < 10; i++) {
        std::cout << a[i] << "\t";
    }

    std::cout << "\nnumber of passes = " << pass << endl;

    return (a);
}


// quick sorting
// void
// qsort(int a[10])
// {
//
// }

//binary search
bool
bsearch(int *arr)
{
    int num, first = 0, last = 9, middle;

    middle = (first + last) / 2;

    std::cout << "\n\nenter a number that you want to search\n";
    std::cin >> num;

    while (first <= last) {
        middle = (first + last) / 2;

        if (arr[middle] == num) {
            std::cout << "\nif loop";
            break;
        }
        else if (arr[middle] < num) {
            first = middle + 1;
            std::cout << "\nelse if loop1";
        }
        else {
            last = middle - 1;
            std::cout << "\nelse if loop2";
        }
    }

    if (first > last) {
        return false;
    }
    return true;
}
