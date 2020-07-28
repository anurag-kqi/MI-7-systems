#define STUDENT_DATAFILE "Student.txt"
#define TEACHER_DATAFILE "Teacher.txt"


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


//on disk structure
struct teacher_disk {
    int index;
    int id;
    char name[30];
    char department[30];
    int contact;
};

//in memory structure
struct teacher {
    struct teacher_disk tch;
    struct teacher *next;
    struct teacher *prev;
};
