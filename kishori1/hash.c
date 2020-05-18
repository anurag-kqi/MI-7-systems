/* c program to insert a value in hash table*/

#include<stdio.h>
#define size 7

int arr[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
      arr[i] = -1;
}

void insert(int value)
{
    int key = value % size;
    if(arr[key] == -1) {
      arr[key] = value;
      printf("%d inserted at arr[%d]\n", value,key);
    }
    else {
      printf("Collision : arr[%d] has element %d already!\n",key,arr[key]);
      printf("Unable to insert %d\n",value);
    }
}

void print()
{
    int i;
    for(i = 0; i < size; i++)
      printf("arr[%d] = %d\n",i,arr[i]);
}

int
main()
{
    init();
    /*key = element % size of array*/
    insert(10);
    insert(4);
    insert(2);
    insert(3);

    printf("Hash table\n");
    print();
    printf("\n");
}
