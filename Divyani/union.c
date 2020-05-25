/* Program to find union oeration work */

#include <stdio.h>

//defining a union
union unionEmp {
  
   char name[32];
   float salary;
   int emp_Id;
} uEmp;

//defining a struct
struct structEmp {
   
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

