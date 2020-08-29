#include <iostream>
using namespace std;

int main() {
    int i, j, k, num, val;
    std::cout << "Enter a number of rows" << '\n';
    std::cin >> num;

    for (i = 0; i < num; i++) {
        for (j = 1; j <= (num - i); j++) {
            std::cout << " ";
        }
        for (k = 0; k <= i; k++) {
            if (k == 0 || i == 0) {
                val = 1;
            }
            else {
                val = val * (i - k + 1) / k;
            }
            std::cout << val << " ";
        }

        std::cout << '\n';
    }
    std::cout << '\n';
    return 0;
}
