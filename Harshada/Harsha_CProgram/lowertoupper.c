#include <stdio.h>
int lower(int c) ;   //Functio initialization

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        putchar(lower(c));   //Function calling
    }

    return 0;
}
int lower(int c)    //Function declaration
{
    int x = c >= 'A' && c <= 'Z' ? (c + 'a') - 'A' : c;
    return x;
}
