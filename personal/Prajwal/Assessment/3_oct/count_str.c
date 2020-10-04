#include <stdio.h>

void main() 
{ 
    FILE *fptr; 
    char ch; 
    int word = 0;
    int character = 1;    
    fptr = fopen("str.txt", "r"); 
    if(fptr == NULL) 
    { 
        printf("Error..."); 
    } 
    else 
        { 
          ch = fgetc(fptr); 
          printf(" The content of the file are : "); 
          while(ch != EOF) 
            { 
                printf("%c", ch); 
                if(ch ==' '||ch =='\n')
                    { 
                        word++; 
                    }
                    else
                    {
                        character++; 
                    }
                ch = fgetc(fptr); 
            }
        printf("\n The number of words in the  file are : %d\n",word); 
        printf(" The number of characters in the  file are : %d\n\n",character-1);         
        } 
    fclose(fptr); 
}
