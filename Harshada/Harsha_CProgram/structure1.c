/*simple program on nested structure*/
#include <stdio.h>

struct college {
    char col_name[40];
};
struct college clg ;
int
main()
{
    struct student_data {
        float fees;
        int id, roll_num;
        struct college clg ;
        char name[20];
    };

    struct student_data std = {4500.8, 101, 1, {"MBES COEA"}, "Harshada"};

    printf("student name: %s\n", std.name);
    printf("student ID: %d\n", std.id);
    printf("student Roll number: %d\n", std.roll_num);
    printf("student college: %s\n\n", std.clg.col_name);

    printf("size of structure college: %d\n", sizeof(struct college));
    printf("size of structure college: %d\n\n", sizeof(clg));

    printf("size of structure student_data: %d\n", sizeof(struct student_data));
    printf("size of structure student_data: %d\n", sizeof(std));

    return 0;
}
