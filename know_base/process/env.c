#include <stdlib.h>
#include <stdio.h>

void
main()
{
    char *home = getenv("HOME");

    printf("value of $HOME is %s\n", home);
}
