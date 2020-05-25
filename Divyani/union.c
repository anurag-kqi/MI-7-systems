/* Pogram to find union oeration work */

#include <stdio.h>

union unionEmp {

   //defining a union
   char name[32];
   float salary;
   int emp_Id;
   
} uEmp;

struct structEmp {

   //defining a struct
   char name[32];
   float salary;
   int emp_Id;
   
} sEmp;

void
main()
{
   printf("\nsize of union :- %d bytes", sizeof(uEmp));
   printf("\nsize of structure :- %d bytes", sizeof(sEmp));
}

