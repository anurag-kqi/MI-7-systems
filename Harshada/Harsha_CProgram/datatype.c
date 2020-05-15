#include <stdio.h>

int
main()
{
    int a;

    printf("Enter any type of data type\n");
    scanf("%d", &a);
    printf("entered value  %d", a);

    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
        printf("%d is a charter...\n");
    }
    else
        printf("Wrong choice\n");
    return 0;
}
