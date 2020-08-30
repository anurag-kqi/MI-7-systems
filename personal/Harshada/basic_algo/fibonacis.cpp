#include <iostream>

int main()
{
    int n, i = 2;
    int arr[20];
    std::cout << "enter a number" << '\n';
    std::cin >> n;

    arr[0] = 0;
    arr[1] = 1;
    std::cout << arr[0] << " " << arr[1] << " ";
    for (i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        if (arr[i] <= n) {

        std::cout << arr[i] << " ";
        }
    }
    return 0;
}
