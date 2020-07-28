#include <stdio.h>
 
main(){
 
char ch;
int i;
 
printf ("Enter a phone number: ");
while ((ch = getchar()) != '\n');
 
i = ch;
 
if ('a' <= ch && ch <= 'c')
 i = 2;
if ('d' <= ch && ch <= 'f')
 i = 3;
if ('g' <= ch && ch <= 'i')
 i = 4;
if ('j' <= ch && ch <= 'l')
 i = 5;
if ('m' <= ch && ch <= 'o')
 i = 6;
if ('p' <= ch && ch <= 's')
 i = 7;
if ('t' <= ch && ch <= 'v')
 i = 8;
if ('w' <= ch && ch <= 'y')
 i = 9;
 
printf ("%d", i);
 
return 0;
}
