#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,add;
    FILE *fptr;

    fptr = fopen("C:\\file.txt","w");

    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }

    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);

    add = a + b;
    
    fprintf(fptr,"%d",add);
    fclose(fptr);

    return 0;
}
