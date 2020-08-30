#include <iostream>

int main()
{
    int i, num, n, revers, reminder;

    for (num = 1; num < 500; num++) {
        revers = 0;
        n = num;
        while (n != 0) {
            reminder = n % 10;
            revers = (revers * 10) + reminder;
            n = n / 10;
        }
        if (revers == num) {
            std::cout << " " << num;
        }
    }
    return 0;
}
