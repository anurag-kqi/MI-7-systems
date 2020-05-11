//C Program to store array in to file

#include <stdio.h>
int 
main() {
    int arr[50];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    FILE *fptr;
    fptr = (fopen("student.txt", "w"));
    if(fptr == NULL) {
    printf("Error!");
    exit(1);
    }

    printf("Enter elements: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    	fprintf(fptr, "%d ", arr[i]);
    }

    fclose(fptr);
    return 0;
}
