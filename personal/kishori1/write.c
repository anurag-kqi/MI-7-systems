# include <stdio.h>
# include <string.h>

int main( )
{
    FILE *fp ;
    char data[50];
    // opening an existing file
    printf( "Opening the file kishori.c in write mode" ) ;
    fp = fopen("kishori.c", "w") ;
    if ( fp == NULL )
    {
        printf( "Could not open file kishori.c" ) ;
        return 1;
    }
    printf( "\n Enter some text from keyboard” \
             “ to write in the file kishori.c" ) ;
    // getting input from user
    while ( strlen (fgets(data, 50, fp) ) > 0 )
    //if( fgets (str, 60, fp)!=NULL ) {
    {
        // writing in the file
        fputs(data, fp) ;
        fputs("\n", fp) ;
    }
    // closing the file
    printf("Closing the file test.c") ;
    fclose(fp) ;
    return 0;
}
