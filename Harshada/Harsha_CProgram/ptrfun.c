#include <stdio.h>

int function(int *a, int *b);

int
main()
{
    int m = 10, n = 20, c;
    printf("a = %d, b = %d\n\n", m, n);

    c = function(&m, &n);

    printf("vaues in main function m = %d, n = %d\n\n", m, n);
    return 0;
}

int
function(int *a, int *b)
{
    printf("vaues in function a = %d, b = %d\n", *a, *b);
    int c;
    c = *a + *b;
    *a = 50;
    *b = 60;
    printf("output in function c = %d\n", c);
    printf("vaues in function a = %d, b = %d\n\n", *a, *b);
    return c;
}
