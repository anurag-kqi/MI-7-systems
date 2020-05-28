/*woking of pointer*/

#include <stdio.h>

void 
main()
{
   int *pc, c;
   
   c = 22;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c);//c=22
   
   pc = &c;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc);//c=22
   
   c = 11;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc);//c=11
   
   *pc = 2;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c);//c=2
}
