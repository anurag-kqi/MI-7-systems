/*stack implimention using ststic array*/

#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5 //pre-process macro

int stack[CAPACITY],top = -1;

void push(int);
int pop();
int isEmpty();
int isFull();
void traverse();
void peek();

int
main()
{
    int ch, item;

    while (1) {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Travers\n");
        printf("5.Quit\n\n");

        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
          case 1 : printf("Enter element : ");
                   printf("\n");
                   scanf("%d", &item);
                   push(item);
                   break;

          case 2 : item = pop();
                   if (item == 0) {
                      printf("Stack is underflow\n\n");
                   }
                   else {
                      printf("Popped item : %d\n\n", item);
                   }
                   break;

          case 3 : peek();
                   break;

          case 4 : traverse();
                   break;

          case 5 : exit(0);

          default : printf("Invalid input\n\n");
        }

    }
}

void
push(int ele)
{
    if (isFull()) {
        printf("Stack is overflow\n\n");
    }
    else {
        top++;
        stack[top] = ele;
        printf("%d Pushed on stack\n\n", ele);
    }
}

int
isFull()
{
    if (top == (CAPACITY - 1)) {
        return 1;
    }
    else {
        return 0;
    }
}

int
pop()
{
    if (isEmpty()) {
        return 0;
    }
    else {
        return stack[top--];
    }
}

int
isEmpty()
{
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void
peek()
{
  if(isEmpty()) {
      printf("Stack is empty \n\n");
  }
  else {
      printf("Peek element : %d\n\n", stack[top]);
  }
}

void
traverse()
{
    if (isEmpty()) {
        printf("Stack is empty\n\n");
    }
    else {
        int i;
        printf("Stack element are : \n");

        for (i = 0; i <= top; i++) {
            printf("%d\n", stack[i]);
        }
        printf("\n\n");
    }
}
