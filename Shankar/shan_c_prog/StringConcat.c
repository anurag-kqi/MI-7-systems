/* C Program to Concat Two Strings without Using Library Function */

#include <stdio.h>
#include <string.h>

void concat(char[], char[]);   //function decleration

int 
main() {
    char s1[50], s2[30];           //declare character array
    printf("\nEnter String 1 :");
    fgets(s1, sizeof s1, stdin);
    printf("\nEnter String 2 :");
    fgets(s2, sizeof s2, stdin);
    concat(s1, s2);
    printf("\nConcated string is :%s", s1);
    return (0);
}

void 
concat(char s1[], char s2[]) {
    int i, j;
    i = strlen(s1)-1;
	
    for (j = 0; s2[j] != '\0'; i++, j++) {
    	s1[i] = s2[j];
    }
    s1[i] = '\0';
}
