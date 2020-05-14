#include <stdio.h>

struct bike {
    char name[20];
    int milage;
};

void bike_data(struct bike b);

int
main()
{
    struct bike b1;

    printf("Enter bike name\n");
    scanf("%[^\n]%*c", &b1.name);

    printf("Enter milage\n");
    scanf("%d", &b1.milage);

    bike_data(b1);    //passing structure as argument

    return 0;
}

void bike_data(struct bike b) {
    printf("\nDisplaying information...\n");
    printf("Bike Name: %s\n", b.name);
    printf("Bike Milage: %d\n", b.milage);
}
