#include <iostream>
using namespace std;

#define CAPACITY 6

int top = -1;

void print_stack(int stack[CAPACITY])
{
    std::cout << '\n' << "Stack " << '\n';
    for (int i = 0; i <+ top; i++) {
        std::cout << stack[i] << '\n';
    }
}

int isfull()
{
    if (top == (CAPACITY - 1)) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1) {
        return 1;
    }
    else
        return 0;
}

void push_ele(int stack[CAPACITY])
{
    int ele;

    std::cout << '\n' << "Enter Element: " ;
    std::cin >> ele;

    if (isfull()) {
        std::cout << '\n' << "stack is full" << '\n';
    }
    else {
        top++;
        stack[top] = ele;
        std::cout << '\n'<< "Element is added in stack" << "\n\n";
    }
}

int pop_ele(int stack[CAPACITY])
{
    int ele;
    if (isEmpty()) {
        std::cout << '\n' << "Stack is empty" << '\n';
    }
    else {
        ele = stack[top];
        top--;
        std::cout << "\n\n" << stack[top] << "  Element is deleted" << '\n';
    }
    return top;
}

void sort_stack(int stack[CAPACITY])
{
    std::cout << "sort" << '\n';
}
int main()
{
    int ch;
    int stack[CAPACITY];

    while (1) {
      std::cout << '\t' << "1. Push Element" << '\n';
      std::cout << '\t' << "2. Pop Element" << '\n';
      std::cout << '\t' << "3. Sort Stack" << '\n';
      std::cout << '\t' << "4. print Stack" << '\n';
      std::cout << '\t' << "5. Exit" << '\n';

      std::cout << '\n' << "Enter your choice: ";
      std::cin >> ch;

        switch (ch) {
          case 1: push_ele(stack);
                  break;

          case 2: pop_ele(stack);
                  break;

          case 3: sort_stack(stack);
                  break;

          case 4: print_stack(stack);

          case 5: exit(0);

          default:
                  std::cout << "Wrong choice" << '\n';
        }
    };
    return 0;
}
