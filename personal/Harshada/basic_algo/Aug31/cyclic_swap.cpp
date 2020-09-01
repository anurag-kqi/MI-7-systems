// program to swap numbers in cyclic order
#include <iostream>
using namespace std;

void cyclic_swap(int* a, int* b, int* c)
{
    int* temp;
    temp = a;
    a = b;
    b = c;
    c = temp;

    std::cout << "values after swap" <<'\n';
    std::cout << *a << " " << *b << " " << *c << '\n';

}

int main()
{
    int  a = 10, b = 20, c = 30;

    std::cout << "values before swap" <<'\n';
    std::cout << a << " " << b << " " << c << '\n';
    cyclic_swap(&a, &b, &c);
    return 0;
}
