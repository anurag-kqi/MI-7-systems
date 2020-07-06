#include <stdio.h>

void main()
{
    FILE *fptr;
    char name[20];
    int age;
    int contact;

    /*  open for writing */
    fptr = fopen("E:\c files\Hash Table.txt", "w");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    printf("Enter the name \n");
    scanf("%s", name);
    fprintf(fptr, "Name    = %s\n", name);
    printf("Enter the age\n");
    scanf("%d", &age);
    fprintf(fptr, "Age     = %d\n", age);
    printf("Enter the Contact\n");
    scanf("%d", &contact);
    fprintf(fptr, "Contact  = %d\n", contact);
    fclose(fptr);
}
