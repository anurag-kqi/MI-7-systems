//Store information of n number pf Employee using structures

#include <stdio.h>
#include <stdlib.h>
struct empDetails {
    int empID;
    double salary;
    char empName[30];
    char designation[30];
};

int 
main() {
    struct empDetails *ptr;
    int i, noOfRecords;
    printf("Enter the number of records: ");
    scanf("%d", &noOfRecords);

    // Memory allocation for noOfRecords structures
    ptr = (struct empDetails *)malloc(noOfRecords * sizeof(struct empDetails));
    for (i = 0; i < noOfRecords; ++i) {
        printf("\nEnter the Employee ID, Name, Designation and Salary respectively:\n");
	scanf("%d %s %s %lf", &(ptr + i)->empID, &(ptr + i)->empName, &(ptr + i)->designation, &(ptr + i)->salary);
    }

    printf("\nDisplaying Information:\n");
    for (i = 0; i < noOfRecords; ++i) {
	printf("%d\t%s\t%s\t%lf\n", (ptr + i)->empID, (ptr + i)->empName, (ptr + i)->designation, (ptr + i)->salary);
    }
    return 0;
}
