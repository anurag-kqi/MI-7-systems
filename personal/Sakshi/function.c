#include<stdio.h>

void swap(int a, int b); 

int 
main()
{
    int m = 10, n = 2;
 
    printf(" values before swap  m = %d \nand n = %d", m, n);
    swap(m, n);                         
}
 
void swap(int a, int b)
{ 
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    printf(" \nvalues after swap m = %d\n and n = %d", a, b);
}
