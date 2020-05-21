#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

struct dataItem {
    int value, key;
};
struct dataItem hashArray[SIZE];

void insert_ele();
void delete_ele();
void display();

int
main()
{
    int ch;

    printf("Hash table operation:\n");
    printf("1.Insert in table\n");
    printf("2.Delete from table\n");
    printf("3.Display table\n");

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

}

void
delete_ele()
{

}

void
display()
{

}
