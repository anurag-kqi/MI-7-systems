#include <stdio.h>

/*1.8 count blanks,tabs and new lines*/

int main(void)
{
    /* initializes blank,tab,newline and c
    sets them all to 0*/
    int blank,tab,newline;
    int c;
    blank = 0;
    tab = 0;
    newline = 0;

    while((c = getchar()) != EOF)
        if (c =='\n')
            ++newline;
        if (c == ' ')
            ++blank;
        if (c == '\t')
            ++tab;
        printf("Blanks: %d\nTabs: %d\nLines: %d\n", blank, tab, newline);
        return 0;
}
