// cpp program to print lucas number
#include <iostream>
using namespace std;

int lucas(int n)
{
    int a = 2, b = 1, c, i;

    std::cout << "\n" << a << '\n' << b << "\n";

    if (n == 0)
        return a;

    std::cout << "Lucase series is" << '\n';
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        std::cout << b << '\n';
    }
    return 0;
}

int main()
{
    int n;
    std::cout << "Enter a number" << '\n';
    std::cin >> n;
    lucas(n);
    return 0;
}
