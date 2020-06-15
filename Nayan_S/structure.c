#include <stdio.h>
#include <conio.h>

struct book
{
   int bookid;
   char title[20];
   float price;
}

// Method definition to take values.
struct book input()
{
   struct book b;
   printf("Enter the BookId, title and price");
   scanf("%d", &b.bookid);
   gets(b.title);
   scanf("%f", b.price);
   return (b);
}

// Method Definition tp print values
void display(struct book b)
{
   printf("\n %d %s %f", b.bookid, b.title, b.price);
}

// Main Method
void
main()
{
  struct book b1;
  clrscr();
  b1 = input(); // Method calling
  display (b1); // Method calling
}
