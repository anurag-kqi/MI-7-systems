#include <stdio.h> 

struct Student
{
  char Student_Name[50];
  float First_Year_Marks;
  float Second_Year_Marks;
    
};

void PassBy_Value(struct Student Students);

int main()
{
  struct Student Student1;

  printf("\nPlease Enter the Student Name \n");
  scanf("%s",&Student1.Student_Name);
  
  printf("\nPlease Enter Student Inter First Year Marks \n");
  scanf("%f",&Student1.First_Year_Marks);
  
  printf("\nPlease Enter Student Inter Second Year Marks \n");
  scanf("%f",&Student1.Second_Year_Marks);
  
  PassBy_Value(Student1);   
  return 0;
}

void PassBy_Value(struct Student Students)
{
  float Sum, Average;

  Sum = Students.First_Year_Marks + Students.Second_Year_Marks;
  Average = Sum/2;
  
  if(Average > 900)
  {
    printf("\n %s is Eligible for Scholorship",Students.Student_Name); 
  }
  else
  {
    printf("\n %s is Not Eligible for Scholorship",Students.Student_Name); 
  }

}
