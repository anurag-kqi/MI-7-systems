//Structure Program

#include <stdio.h>
#include <string.h>              `
#include <stdlib.h>

struct Books  {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
 };

void
printBook( struct Books book );

int
main( )
 {
   struct Books Book1;
   struct Books Book2;

   strcpy( Book1.title, " Harry Potter ");
   strcpy( Book1.author, " Elazin Plot ");
   strcpy( Book1.subject, " The Dark Donuld Secretes ");
   Book1.book_id = 1234;

   strcpy( Book2.title, " Way to success ");
   strcpy( Book2.author, " Swami Vivekanand ");
   strcpy( Book2.subject, " Will Power ");
   Book2.book_id = 1126;

   printBook( Book1 );

   printBook( Book2 );

   return 0;
}

void
printBook( struct Books book ) {

   printf( "Book title : %s\n ", book.title);
   printf( "Book author : %s\n ", book.author);
   printf( "Book subject : %s\n ", book.subject);
   printf( "Book book_id : %d\n ", book.book_id);
}
