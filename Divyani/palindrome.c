/*program to find palindrome of string*/

#include <stdio.h>
#include <string.h>

void
main()
{
    char string1[20];
    int i, length;
    int flag = 0;
    
    printf("Enter a string: \n");
    scanf("%s", string1);
    
    length = strlen(string1);
    
    for ( i=0 ; i < length ; i++ ){
      if ( string1[i] != string1[length-i-1] ){
      flag = 1;
       break;
      }
   }  
   
   if ( flag ){
        printf("string is not a palindrome", string1);
   }    
    else{
        printf("string is a palindrome", string1);
    }
}   

