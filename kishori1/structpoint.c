/* Displaying person information by using pointer*/

#include <stdio.h>

struct person
{
int age;
float weight;
};

int
main()
{
  struct person *personptr, person1;
  personptr = &person1;

  printf("enter age: ");
  scanf("%d", &personptr->age);

  printf("enter weight: ");
  scanf("%f", &personptr->weight);

  printf("displaying: \n");
  printf("age: %d\n", personptr->age);
  printf("weight: %f", personptr->weight);
  return 0;
}
