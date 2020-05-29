#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

struct student {
    int id, roll_num;
    char name[20];
};
struct student *head, *temp, *value;

struct hash_table {
    struct student *stud;
    int key;
};
struct hash_table *array;

int key, i;

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

    init_array();

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
init_array()
{
    array = (struct hash_table*) malloc(sizeof(struct hash_table));
    for (i = 0; i < SIZE; i++) {
        array[i].key = 0;
        array[i].stud = 0;
    }
}

struct student*
init_stud()
{
  temp = (struct student*)malloc(sizeof(struct student));
  printf("\n\t\tEnter student data\n: ");
  printf("Name: ");
  scanf("%s", &temp->name);
  printf("Id: ");
  scanf("%d", &temp->id);
  printf("Roll Number: ");
  scanf("%d", &temp->roll_num);

  return temp;
}

int
hash_code()
{
    key = (temp->roll_num % SIZE);
    return  key;
}
void
insert_ele()
{
    value = init_stud();
    int index = hash_code();
    printf("%d", index);
    
    if (array[index].stud == 0) {
        array[index].key = key;
        array[index].stud = value;
    }
    printf("%d", index);
}

void
delete_ele()
{

}

void
display()
{

}
