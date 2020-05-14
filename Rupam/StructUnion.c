//Program For Structure and Union

#include<stdio.h>
 
int  
main() 
 {
   struct student
    {
      char name[30];
      int rollno;
      float percentage;
    };

   union details {
      struct student s1;
    };
   union details set;
 
    printf(" Enter details: ");

    printf(" \nEnter name : ");
    scanf("%s", set.s1.name);

    printf(" \nEnter roll no : ");
    scanf("%d", &set.s1.rollno);

    printf(" \nEnter percentage :");
    scanf("%f", &set.s1.percentage);
 

    printf("\nThe student details are : \n ");
    printf("\name : %s", set.s1.name);
    printf("\nRollno : %d", set.s1.rollno);
    printf("\nPercentage : %f", set.s1.percentage);
 
    return 0;
  }
