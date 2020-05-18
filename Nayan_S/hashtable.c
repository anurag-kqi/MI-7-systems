#include <stdio.h> 

struct pair
{
    int valu, key;
}

void
main()
{
    int size, i, temp;
    
    printf("Enther the size of the table");
    scanf("%d", &size);

    struct pair hash_table[size];
    printf("Enter the elements:");
    for(i = 0; i < size; i++)
       {
           scanf("%d",&temp);
           hash_table[temp % size].value = temp;
           hast_table[temp % size].key = temp % size;
       }

    printf("\n");
    display(hast_table, size);
    int a = 0;// to stop debugging (optional).
}

void display(struct pair[], int size)
{
   int i;

   printf("value\key\n");
    for(i = 0; i < size; i++)
      {
          printf("%d\t%d\n", ar[i].value, ar[i].key);
      }
}
