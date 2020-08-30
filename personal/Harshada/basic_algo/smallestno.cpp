//Find smallest number with sum of digits is equal n and divisible by 10^n
#include <iostream>

/*
first check number is equal to 0 or not
to calculate sum of digits of number is equal to number
  - find reminder of number while dividing with 9
  - print reminder
  - divide number with 9
  - and add (print) quatient number of 9 after reminder
to make number divisible by 10^n, add n number of 0 at the end of the number

*/

void smallestno(int n)
{
    int i;
    //check number is zero or not
    if (n == 0) {
        std::cout << "0" << '\n';
    }

    //sum of digits of number is equal to number
    if ((n % 9) != 0) {
        std::cout << (n % 9);
    }
    for (i = 1; i <= (n / 9); i++) {
        std::cout << "9";
    }

    //to make number divisible by 10^n
    for (i = 1; i <= n; i++) {
        std::cout << "0";
    }
}

int main()
{
    int n;

    std::cout << "Enter a number" << '\n';
    std::cin >> n;

    smallestno(n);
    return 0;
}
