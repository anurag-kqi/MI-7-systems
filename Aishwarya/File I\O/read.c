#include <stdio.h>
#include <stdlib.h>

int main()
{
   int add;
   FILE *fptr;

   if ((fptr = fopen("C:\\file.txt","r")) == NULL){
       printf("Error! opening file");
       exit(1);
   }

   fscanf(fptr,"%d", &add);

   printf("\nAddition is = %d\n", add);
   fclose(fptr); 
  
   return 0;
}
