/* program for pointers to structure*/
#include <stdio.h>

struct person {
    int age;
    int weight;
    char name[20];
};

int
main()
{
    struct person *p1;
    struct person p2 = {24, 50, "shubh"};
    p1 = &p2;

    printf("Name: %s\n", p2.name);
    printf("Age: %d\n", p2.age);
    printf("weight; %d \n\n\n\n", p2.weight);

    printf("value of pointer p1 = %d\n", p1);
    printf("address of variavle p2 = %d\n\n\n", &p2);

    printf("Name: %s\n", p1->name);
    printf("Age: %d\n", p1->age);
    printf("weight; %d \n", p1->weight);
    return 0;
}
