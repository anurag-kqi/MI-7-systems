#include <iostream>
using namespace std;

int main()
{
    int num;

    std::cout << "Enter a number" << '\n';
    std::cin >> num;

    int n = num;
    int reminder, result = 0;

    while (n != 0) {
        reminder = n % 10;
        result = result + (reminder * reminder * reminder);
        n = n / 10;
    }
    if (result == num) {
        std::cout << num << " is amstrong number" << '\n';
    }
    else
        std::cout << num << " is not amstrong number" << '\n';

    return 0;
}
