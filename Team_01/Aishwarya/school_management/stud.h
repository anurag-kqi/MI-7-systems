#define STUDENT_DATAFILE "Student.txt"

//on disk structure
struct student_disk {
    int index;
    int id;
    char name[30];
    char class[10];
    char address[50];
    int contact;
};

//in memory structure
struct student {
    struct student_disk std;
    struct student *next;
    struct student *prev;
};

