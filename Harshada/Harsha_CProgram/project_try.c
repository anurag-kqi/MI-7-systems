#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct student
{
    int id;
    int roll_num;
    char name[20];
    struct student *next;
};
struct student arr[SIZE], *temp, *element;

int hash_code(int);
struct student* init_ele();
void insert();
void update();
void delete_ele();
void search();


int
main()
{
    int ch;

    printf("implimention of hash table\n");
    printf("Menu:\n1.Insert\n2.Update\n3.Delete\n4.search\n5.Exit\n\n");

    printf("Enter your choice:");
    scanf("%d", &ch);

    switch (ch) {
      case 1: insert();
              break;

      case 2: update();
              break;

      case 3: delete_ele();
              break;

      case 5: search();
              break;

      case 6: exit(1);
              break;

      default: printf("Wrong choice\n\n");
    }
}

int
init_array()
{
    for (int i = 0; i < 3; i++) {
        arr[i].name[20] = NULL;
        arr[i].id = 0;
        arr[i].roll_num = 0;
    }
    return 0;
}

// struct student*
// init_ele()
// {
//     temp = (struct student*)malloc(sizeof(struct student));
//     printf("Enter Student Data:");
//     printf("Name: ");
//     scanf("%s", temp->name);
//
//     printf("\n ID:");
//     scanf("%d", &temp->id);
//
//     printf("Roll Number:");
//     scanf("%d", &temp->roll_num);
//
//     return temp;
// }

void
insert()
{
    int key;

    init_array();

    temp = (struct student*)malloc(sizeof(struct student));
    printf("\n\tEnter Student Data:\n");
    printf("Name: ");
    scanf("%s", temp->name);

    printf("ID:");
    scanf("%d", &temp->id);

    printf("Roll Number:");
    scanf("%d", &temp->roll_num);

    key = (temp->roll_num % SIZE);

    printf("Key = %d \n", key);




}
