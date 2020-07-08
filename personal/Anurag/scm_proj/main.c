#include <stdio.h>

extern void
hello_student(char *name);

main()
{
    printf("I am main again\n");
    hello_student("anurag");
}
