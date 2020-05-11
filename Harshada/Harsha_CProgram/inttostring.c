#include<stdio.h>
#include<string.h>

int
main()
{
    int num, i = 0, len = 0, n;
    char str[10];

    printf("Enter any number\n");
    scanf("%d", &num);

    // To find length of number
    n = num;
    while (n > 0) {
        len++;
        n = (n / 10);
    }
    // convert integer to string
    for (i = 0; i < len; i++) {
        int temp;

        temp = (num % 10) + '0';
        str[len - (i + 1)] = temp;

        num = num / 10;
    }
    str[len] = '\0';

    printf("\nConverted into string\n");
    for (i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    return 0;
}
