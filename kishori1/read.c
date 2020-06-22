#include <stdio.h>
int
main()
{
  FILE *fp;
  char ch;
  fp=fopen("soc_mg.c","w");
  printf("input line and press EOF");
  while((ch = getchar())!=EOF)
  {
    putc(ch, fp);
  }
  fclose(fp);
  return 0;
}
