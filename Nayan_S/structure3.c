#include <stdio.h>
#include <conio.h>

struct complex
{
    int real;
    float imag;
}

void add(complex c1, complex c2, complex *result)
{
    result -> real = c1.real + c2.real;
    result -> imag = c1.imag + c2.imag;   
}

void
main()
{
    complex c1, c2, result;

    printf("For 1st Part...\n");
    printf("Enter Real Number:");
    scanf("%d\n", c1.real);
    printf("Enter Imaginary Number:");
    scanf("%f\n", c1.imag);

    printf("For 2nd Part...\n");
    printf("Enter Real Number:");
    scanf("%d\n", c2.real);
    printf("Enter Imaginary Number:");
    scanf("%f\n", c2.imag);

    add(c1, c2, &result);

    printf("Result for Real No.: %d", result.real);
    printf("Result for Imaginary No.: %f", result.imag);
}
