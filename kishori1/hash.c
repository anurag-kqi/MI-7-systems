/* c program to insert, delet and search a value in hash table*/

#include<stdio.h>
#define size 10

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

void del(int value)
{
    int key = value % size;
    if(arr[key] == value)
        arr[key] = -1;
    else
        printf("%d not present in the hash table\n",value);
}

void search(int value)
{
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
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
    insert(12);
    insert(8);
    insert(13);
    insert(3);

    printf("Hash table\n");
    print();
    printf("\n");

    printf("Deleting value 12..\n");
    del(12);
    printf("After the deletion hash table\n");
    print();
    printf("\n");

    printf("Deleting value 5..\n");
    del(5);
    printf("After the deletion hash table\n");
    print();
    printf("\n");

    printf("Searching value 8..\n");
    search(8);
    printf("Searching value 12..\n");
    search(12);
    return 0;
}
