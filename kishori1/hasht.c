#include<stdio.h>

#include<stdlib.h>

/* Node for storing an item in a Doubly Linked List*/
#define size 10
struct node

{

	int key;

	int value;

	struct node *next;

	struct node *prev;

};

struct arrayitem


{
	struct node *head;

	/* head pointing the first element of Linked List at an index of Hash table */

	struct node *tail;

};
struct arrayitem *array;
int size = 0;
int max = 10;

int hashcode(int key)

{
	return (key % size);

}
void insert(int key, int value)
  {
		int index = hashcode(key);

/* Extracting Linked List at a given index */

	struct node *list = (struct node*) array[index].head;

	/* Creating an item to insert in the hash table */

	struct node *item = (struct node*) malloc(sizeof(struct node));

	item->key = key;

	item->value = value;

	item->next = NULL;

	item->prev = NULL;

  if (list == NULL)

        {
		/* Absence of Linked List at a given index of Hash table */

printf("\n  %d (key) and %d (value) has been inserted  \n", key, value);

		array[index].head = item;

		array[index].tail = item;

		size++;
}
else

{

/* A Linked List is present at given index of Hash table */
int find_index = find(list, key);

if (find_index == -1){
*Key not found in existing Linked List

*Adding the key at the end of the Linked List

*/

item->prev = array[index].tail;

array[index].tail->next = item;

array[index].tail = item;

size++;

printf("\n %d (key) and %d (value) has been inserted \n", key, value);

}
else {

  /*

   *Key already present in Linked List

   *Updating the value of already existing key

  */
//struct node *element = get_element(list, find_index);

  //element->value = value;
}
}
}
int main()

{

	int choice, key, value;



	array = (struct arrayitem*) malloc(max * sizeof(struct arrayitem*));

	//init_array();



	do {

		printf("Implementation of Hash Table in C chaining with Doubly Linked List \n\n");

		printf("MENU-: \n1.Inserting item in the Hash Table"

                              "\n2.Removing item from the Hash Table"

                              "\n3.Check the size of Hash Table"

                              "\n4.Display a Hash Table"

		       "\n\n Please enter your choice-:");



		scanf("%d", &choice);



		switch(choice)

                {

									case 1:



									      printf("Inserting element in Hash Table\n");

									      printf("Enter key and value-:\t");

									      scanf("%d %d", &key, &value);

									      insert(key, value);



									      break;
												default:



			 printf("Wrong Input\n");



}



printf("\n Do you want to continue-:(press 1 for yes)\t");

scanf("%d", &c);



}while(c == 1);



}
