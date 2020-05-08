//Program to print reverse string 
#include<stdio.h>
#include<conio.h>
#include<string.h>
   
   main()
    {
    char s[100];
    printf("Enter a string to reverse\n");
    gets(s);
    strrev(s);
    printf("Reverse of string is %s\n", s);
    getch();
    }