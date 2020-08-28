#define PATIENT_DATAFILE "patient.txt"
#define DOCTOR_DATAFILE "doctor.txt"

//structure for patient Data
struct patData {
    int index;
    int id;
    char name[30];
    int age;
    char bloodgrp[10];
    char address[50];
    int contact;
    char symptoms[40];
};

struct patient {
    struct patData patd;
    struct patient *next;
    struct patient *prev;
 };

 //structure for doctor DATA
 struct docData {
    int index;
    int id;
    char name[20];
    char address[50];
    int contact;
 };

 struct doctor {
    struct docData docd;
    struct doctor *next;
    struct doctor *prev;
 };
