 // Program of Union

#include <stdio.h>

union item
{
	int x;
	float y;
	char z;
};

void 
main ()
{
	union item i1;

	i1.x = 5;
	i1.y = 30.5;
	i1.z = 'a';

	printf("\nx=%d", i1.x);
	printf("\ny=%f", i1.y);
	printf("\nz=%c", i1.z);
}
