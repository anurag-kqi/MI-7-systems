#include <stdio.h>
#include <string.h>
 
// Define Strcutre
struct student
{
           int id;
           char name[20];
           int mark;
};
 
int main()
{

struct student record; // Declare Strcutre Variable
 
// Assign Values for Strcutre Memebrs id,name and mark
record.id=1001;

// Assign Values name using strcpy function;
strcpy(record.name, "Harry");    
record.mark = 90;
 

printf("Student Id   : %d \n", record.id); //// Print Strcutre Memebrs Values
printf("Student Name : %s \n", record.name);
printf("Student Mark : %d \n", record.mark);

return 0;
}
