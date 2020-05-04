#include <stdio.h>
int main()
{
    int c,d;
    d='\0';
    while((c=getchar())!=EOF)
        {
        if (c==' ')
            {
                d=getchar();
                if (d!=' ')
                    putchar(c);
            }
        putchar(c);
        }
	return 0;
}
