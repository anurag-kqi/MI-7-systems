#include <stdio.h>

void
main()
{
	int a, b;
	int sum, sub, div, mult;

	printf("Enter number:");
	scanf("%d %d", &a, &b);
	sum = a + b;
	sub = a - b;
	div = a / b;
	mult = a * b;
	printf("\nAddition=%d", sum);
	printf("\nSubstraction=%d", sub);
	printf("\nDivision=%d", div)
	printf("\nMultiplication=%d", mult);
} 
