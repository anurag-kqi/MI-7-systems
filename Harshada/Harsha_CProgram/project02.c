// hash table with linkes list

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct student {
    int id, roll_num;
    char name[20];
    struct student *next;
};
struct student *temp;

struct hash_table {
    struct student *value;
    int key;
};
struct hash_table arr[SIZE];

void init_array();
struct student* init_stud();
int hash_code();
void insert_ele();
void delete_ele();
void display();

int
main()
{
    int ch;

    printf("Hash table operation:\n\n");
    printf("1.Insert in table\n");
    printf("2.Delete from table\n");
    printf("3.Display table\n");

    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1: insert_ele();
                break;
        case 2: delete_ele();
                break;
        case 3: display();
                break;
    }
}

void
insert_ele()
{
  int index;

  // initialiszing array value to null and index to -1
  for (int i = 0; i < SIZE; i++) {
      arr[i].value = NULL;
      arr[i].key = -1;
  }

  temp = (struct student*)malloc(sizeof(struct student));
  printf("\n\tEnter Student Data:\n");
  printf("Name: ");
  scanf("%s", temp->name);

  printf("ID:");
  scanf("%d", &temp->id);

  printf("Roll Number:");
  scanf("%d", &temp->roll_num);

  temp->next = NULL;

  //create hash code that is key
  index = (temp->roll_num % SIZE);

  printf("\nindex = %d \n", index);

  //  inserting value  at hash code index
  if(arr[index].key == -1) {
      arr[index].value = temp;
      arr[index].key = index;

      printf("Name: %d\n", arr[index].value->name[20]);
      printf("Id: %d\n", arr[index].value->id);
      printf("Roll number: %d\n", arr[index].value->roll_num);

  }

}

void
delete_ele()
{

}

void
display()
{

}
