#include<stdio.h>

struct info
{
    int id_no;
    char name[20];
    char addr[20];
    int age;
};
struct info std[50];
void main()
{

    int i,n;
    printf("Enter the Number of Student:");
    scanf("%d", &n);
    //printf("Enter ID,NAME,ADDRESS and AGE:");
    for(i=0;i<n;i++)
    {
        printf("Now Enter student ID:");
        scanf("%d", &std[i].id_no);
        printf("Enter name of Student:");
        scanf("%s", &std[i].name);
        printf("Enter Address of Student:");
        scanf("%s", &std[i].addr);
        printf("Enter age of Student:");
        scanf("%d", &std[i].age);
        //scanf("%d%s%s%d", &std[i].id_no,std[i].name,std[i].addr,std[i].age);
    }
    printf("Student Information:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t%s\t%d\n", &std[i].id_no,std[i].name,std[i].addr,std[i].age);
    }

}
