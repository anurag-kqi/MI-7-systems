#include<stdio.h>
#include<string.h>

int main()
{
    int num,i;
    char str[10];
    printf("Enter any number\n");
    scanf("%d", &num);

    for (i = 0; num > 0; i++) {
      int temp;
      temp = num % 10;
      str[i] = temp;
      num = num / 10;
      printf("For loop");
    }
    str[i] = '\0';

    printf("%c\n", str);

    return 0;
}
