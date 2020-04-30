#include <stdio.h>

int 
main()
{
	int nl = 0, nb = 0, nt = 0, ch;

	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
		  nl++;

		if (ch == ' ')
		  nb++;

		if (ch == '\t')
		  nt++;
		printf("new lines:%d \n Tabs:%d \n Blank space:%d", nl, nt, nb);		
	}
	return 0;
}
