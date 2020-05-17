/*program to allocate memory by using malloc*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main()
{
char name[100];
char *description;
strcpy(name, "Aditi Noor");

/*allocate memory dynamically*/
description = (char*)malloc(200 * sizeof(char) );

if(description == NULL) {
  fprintf(stderr, "error - unable to allocate required memory\n");
}
else {
  strcpy(description, "Aditi Noor in class 10th");
}
printf("Name = %s\n", name);
printf("Description: %s\n", description);
}
