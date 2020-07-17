Q1: How to declare a variable or function and use it across different files?

- A variable or function is defined only and only in one file.
- Any other file looking to use the variable or function need to have an
  extern declaration. 
- extern declaration need to have type for variables and types for all the 
  parameters for functions

  For example:
  file1.c

  int my_sum(int i, int j) {
      int sum = i + j;
      printf("sum %d", sum);
      return sum;
  }

  file2.c, want to use this my_sum function, need to have following declaration:

  extern int my_sum(int, int); 


Q2: If you need to define a struct type or some other data type in one file and use it across multiple files, what is the right thing to do?
- Don't define such struct definition in any .c files. Define it in the .h and then include that .h file in all the .c files requiring that type.

For example: 
struct studentData {
    int id;
    char name[80];
    int contact;
}

Define this in student.h  file and then include student.h in all .c files using studentData. 