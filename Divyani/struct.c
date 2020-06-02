/*structure program*/

#include <stdio.h>
/* Created a structure here. The name of the structure is
  StudentData*/
  
struct StudentData {
    char *stud_name;
    int stud_id;
    int stud_age;
};

void 
main()
{
     /* student is the variable of structure StudentData*/
     struct StudentData student;

     /*Assigning the values of each struct member here*/
     student.stud_name = "Steve";
     student.stud_id = 1234;
     student.stud_age = 30;

     /* Displaying the values of struct members */
     printf("Student Name is: %s", student.stud_name);
     printf("\nStudent Id is: %d", student.stud_id);
     printf("\nStudent Age is: %d", student.stud_age);
}
