//store array in to file

#include <stdio.h>
#include <stdlib.h>
void
writeArray()
{
    int arr[50];
    int n, i;

    printf("\n________________________________________________________");
    printf("\n\n\tEnter number of elements: ");
    scanf("%d", &n);

    FILE *fptr;
    fptr = (fopen("student.txt", "w"));
    if(fptr == NULL) {
    printf("Error!");
    exit(1);
    }

    printf("\n________________________________________________________");
    printf("\n\n\tEnter elements: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    	fprintf(fptr, "%d ", arr[i]);
    }
    printf("\n________________________________________________________");
    fclose(fptr);
}
