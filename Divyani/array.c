/*program of array to print number*/

#include <stdio.h>  
void  
main()  
{  
    int arr[10]; 
    int i;  
       
       //Read and Print elements of an array:
     
     printf("Input 10 elements in the array :\n");  
         for (i=0; i<10; i++)  
         {  
	    printf("element - %d : ",i);
            scanf("%d", &arr[i]);  
         }  
     printf("\nElements in array are: ");  
         for (i=0; i<10; i++)  
         {  
            printf("%d", arr[i]);  
         }  
     printf("\n");	
}

