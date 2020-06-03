#include<stdio.h>

int main()
{
int a[20],i,n;
printf("Enter no. of elements: ");
scanf("%d",&n);
printf("\nEnter elements: \n");
for(i=0;i<n;i++)
{
  scanf("%d",&a[i]);
}

printf("\nPrinting elements with location......\n");
for(i=0;i<n;i++)
{
  printf("a[%d] = %d \n",i,a[i]);
}

}
