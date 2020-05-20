#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct dataItem {
    int data, key;
};
struct dataItem *hashArray[SIZE];

void insert(int, int);
void display();

int
main()
{
    struct dataItem *temp = (struct dataItem*)malloc(sizeof(struct dataItem));
    temp->data = -1;
    temp->key = -1;

    insert(1, 20);
    display();
}

void
insert(int key, int data)
{
      struct dataItem *item = (struct dataItem*)malloc(sizeof(struct dataItem));
      item->data = data;
      item->key = key;
      printf("element %d is inserted at key %d\n", data, key);
      //get the hash
      int hashindex = (key % SIZE);

      // move in Array
      while (hashArray[hashindex] != NULL && hashArray[hashindex]->key != -1) {
          ++hashindex;
          hashindex = hashindex % SIZE;
      }
      hashArray[hashindex] = item;
}

void
display()
{
    int i = 0;

    for (i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL) {
            printf("(%d, %d)\n", hashArray[i]->key, hashArray[i]->data);
        }
        else {
            printf("----\n");
        }
    }
}
