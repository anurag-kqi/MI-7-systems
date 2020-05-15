#include <stdio.h>
#include <string.h>

struct student
{
    int id;
    char name[20];
    float percentage;
};
int
main()
{
    int i;
    struct student record1={1,"sakshi",83.25};
    struct student record2={2,"tejas",87.45};
    
    printf("record of student1:\n");
    printf(" id is : %d\n", record1.id);
    printf(" name is : %s\n", record1.name);
    printf(" percentage is : %f\n", record1.percentage);
    
    
    printf("record of student2:\n");
    printf(" id is : %d\n", record2.id);
    printf(" name is : %s\n", record2.name);
    printf(" percentage is :n%f\n", record2.percentage);


    return 0;
}
