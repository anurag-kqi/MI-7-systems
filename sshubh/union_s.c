#include<stdio.h>
union job
{
//union type
char name[93];
float salary ;
int workerno;
}
 j;

 struct structjob
 {
 char name[55];
 float salary;
 int workerno;
 }
 sjob;

int main()
{
printf("=%d bytes", sizeof(j));
printf("\n size of struct = %d byte",sizeof(sjob));
return 0;
}
