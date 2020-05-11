/*simple program on nested structure*/
#include <stdio.h>

struct college {
    char col_name[40];
};

int
main()
{
    struct student_data {
        int id, roll_num;
        char name[20];
        struct college clg ;
    };

    struct student_data std = {101, 1, "Harshada", "MBES COEA"};

    printf("student name: %s\n", std.name);
    printf("student ID: %d\n", std.id);
    printf("student Roll number: %d\n", std.roll_num);
    printf("student college: %s\n", std.clg.col_name);
    return 0;
}
