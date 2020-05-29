#include <stdio.h>
#include <string.h>

union student
{
            char name[20];
            char subject[20];
            float percentage;
}record;


int main()
{
            union student rec2;

            strcpy(record.name, "Ashwini");
            strcpy(record.subject, "IT");
            record.percentage = 90.50;

            printf(" Name       : %s \n", record.name);
            printf(" Subject    : %s \n", record.subject);
            printf(" Percentage : %f \n", record.percentage);
            printf("Union record2 values example\n");


       strcpy(rec2.name, "Ash");
       printf(" Name       : %s \n", rec2.name);

       strcpy(rec2.subject, "Maths");
       printf(" Subject    : %s \n", rec2.subject);

       rec2.percentage = 99.50;
       printf(" Percentage : %f \n", rec2.percentage);
            return 0;
}
