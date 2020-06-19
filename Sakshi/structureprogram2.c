
#include<stdio.h>
#define pi 3.14
float area(float);
int 
main()
{
    float r,ans;
    printf("enter the radius:n");
    scanf("%f",&r);
    ans=area(r);
    printf("the area is:%f",ans);
    return 0;
}
float area(float r)
{
     
    return pi*r*r ;
}