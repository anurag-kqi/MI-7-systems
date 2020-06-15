/* Recursive function to find nth value of fibonaccis series*/

#include <stdio.h>

int fibonacci(int);

int
main()
{
    int n, f;
    printf("Enter a number: \n");
    scanf("%d", &n);

    f = fibonacci(n);
    printf("%d\n", f);

    return 0;
}

int fibonacci(int n)
{
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return (fibonacci(n - 1)) + (fibonacci(n - 2));
    }
}
