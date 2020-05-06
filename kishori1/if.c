#include <stdio.h>

int main()
{
    int num;

    printf("enter a number: \n");
    scanf("%d", &num);
    if (num > 0)
        printf("%d is a positive number \n", num);
    else if (num < 0)
        printf("%d is a negative number \n",num);
    else
        printf("0 is neither positive nor negative");
}
