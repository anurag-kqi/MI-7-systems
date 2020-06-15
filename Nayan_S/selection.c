#include <stdio.h>

void
main()
{
    int a[],i, j, n, min, temp;

    printf("Enter the size of array\n");
    scanf("%d\n", &n);
    printf("Enter the 7 element in the array");
    for(i = 0; i < n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    

    for(i = 0; i < n - 1; i + 1)
       {
           min = i;
        
      for(j = i + 1; j < n;j++)
        {
             if(a[i] < a[min])
            {
               min = j;
            }
        }
      
    temp = a[i];
    a[i] = a[min];
    a[min] = temp

}
