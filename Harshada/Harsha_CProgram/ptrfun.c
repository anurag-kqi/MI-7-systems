#include <stdio.h>

int function(int *a, int *b);

int
main()
{
    int a = 10, b = 20, c;
    printf("a = %d, b = %d\n\n", a, b);

    c = function(&a, &b);

    printf("vaues in main function a = %d, b = %d\n\n", a, b);
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
