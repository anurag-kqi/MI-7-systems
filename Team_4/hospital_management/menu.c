#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hosp.h"

//declarations for patient data
struct patData pat;
extern int num_records;
extern void read_pat();
extern void write_pat(struct patData pat);
extern void insert_pat(struct patData pat_data);
//extern void delete_pat_file(struct patData delete);
extern void display_pat();
extern void search_pat(int id);
extern void update_pat(int id);
extern void delete_pat(int id);

//declarations for doctor data
struct docData doc;
extern int num_record;
extern void read_doc();
extern void write_doc(struct docData doc);
extern void insert_doc(struct docData doc_data);
//extern void update_pat_file(struct patData update);
//extern void delete_pat_file(struct patData delete);
extern void display_doc();
extern void search_doc(int id);
extern void update_doc(int id);
extern void delete_doc(int id);

//main menu function
void menus()
{
    int id, ch;
    while(1) {
        printf("\n==================================================================");
        printf("\n\t\t PATIENT DATA\n");
        printf("\n\t1. Insert Data\n\t2. Display Data\n\t3. Search Data\n\t4. Update Data\n\t5. Delete Data\n\t6. Exit");
        printf("\n\n\tEnter your choice(1-6) : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                    printf("\n==================================================================");
                    printf("\n\t\tINSERT IN TO\n");
                    printf("\n\t1. Patient Data\n\t2. Doctor Data\n\t3. Exit(0)");
                    printf("\n\n\tEnter your choice to insert(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1:
                                printf("\n==================================================================");
                                printf("\n\t\tINSERT PATIENT DATA\n");
                                printf("Index: %d", num_records);
                                pat.index = num_records;
                                printf("\n\tEnter ID : ");
                                scanf("\t\n%d", &pat.id);
                                printf("\n\tEnter Name : ");
                                scanf("\t\n %[^\n]%*c", pat.name);
                                printf("\n\tEnter Age : ");
                                scanf("\t\n%d", &pat.age);
                                printf("\n\tEnter Blood Group : ");
                                scanf("\t\n %[^\n]%*c", pat.bloodgrp);
                                printf("\n\tEnter Address : ");
                                scanf("\t\n %[^\n]%*c", pat.address);
                                printf("\n\tEnter Contact : ");
                                scanf("\t\n %d", &pat.contact);
                                printf("\n\tEnter Symptoms : ");
                                scanf("\t\n %[^\n]%*c", pat.symptoms);
                                insert_pat(pat);
                                write_pat(pat);
                                num_records++;
    			                break;

                        case 2:
                                printf("\n==================================================================");
                                printf("\n\t\tINSERT DOCTOR DATA\n");
                                printf("Index: %d", num_record);
                                doc.index = num_record;
                                printf("\n\tEnter ID : ");
                                scanf("\t\n%d", &doc.id);
                                printf("\n\tEnter Name : ");
                                scanf("\t\n %[^\n]%*c", doc.name);
                                printf("\n\tEnter Address : ");
                                scanf("\t\n %[^\n]%*c", doc.address);
                                printf("\n\tEnter Contact : ");
                                scanf("\t\n %d", &doc.contact);
                                insert_doc(doc);
                                write_doc(doc);
                                num_record++;
                                break;

                        case 3: exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

            case 2:
                    printf("\n==================================================================");
                    printf("\n\t\tDISPLAY DATA\n");
                    printf("\n\t1. Patient Data\n\t2. Doctor Data\n\t3. Exit(0)");
                    printf("\n\n\tEnter your choice to insert(1-3):");
                    scanf("%d", &ch);

                    switch(ch)
                    {
                        case 1:
                                display_pat();
                                break;

                        case 2:
                                display_doc();
                                break;

                        case 3:
                                exit(0);

                        default: printf("Wrong Choice!!");
                    }
                    break;

            case 3:
                    printf("\n==================================================================");
                    printf("\n\t\tSEARCH DATA FROM\n");
                    printf("\n\t1. Patient Data\n\t2. Doctor Data\n\t3. Exit(0)");
                    printf("\n\n\tEnter your choice to insert(1-3):");
                    scanf("\t %d", &ch);

                    switch(ch)
                    {
                        case 1:
                                printf("\n==================================================================");
                                printf("\n\n\tEnter Patient ID for Search : ");
                                scanf("\t%d", &id);
                                search_pat(id);
                                break;

                        case 2:
                                printf("\n==================================================================");
                                printf("\n\n\tEnter Doctor ID for Search : ");
                                scanf("\t%d", &id);
                                search_doc(id);
                                break;

                        case 3:
                                exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

            case 4:
                  printf("\n==================================================================");
                  printf("\n\t\tUPDATE DATA FROM\n");
                  printf("\n\t1. Patient Data\n\t2. Doctor Data\n\t3. Exit(0)");
                  printf("\n\n\tEnter your choice to insert(1-3):");
                  scanf("\t %d", &ch);
                    switch(ch)
                    {
                        case 1:
                                printf("\n\n\tEnter Patient ID for Update : ");
                                scanf("\t %d", &id);
      				            update_pat(id);
                                break;
                        case 2:
                                printf("\n\n\tEnter Doctor ID for Update : ");
                                scanf("\t %d", &id);
                                update_doc(id);
                                break;
                        case 3:
                                exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                        break;

            case 5:
                    printf("\n==================================================================");
                    printf("\n\t\tDELETE DATA FROM\n");
                    printf("\n\t1. Patient Data\n\t2. Doctor Data\n\t3. Exit(0)");
                    printf("\n\n\tEnter your choice to insert(1-3):");
                    scanf("\t %d", &ch);

                    switch(ch)
                    {
                        case 1:
                                printf("\n\n\tEnter Patient ID for  Delete : ");
                                scanf("\t %d", &id);
        				        delete_pat(id);
                                break;

                        case 2:
                                printf("\n\n\tEnter Doctor ID for  Delete : ");
                                scanf("\t %d", &id);
                                delete_doc(id);
                                break;

                        case 3:
                                exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

            case 6:
                    exit(0);

                    default: printf("\n\n\tWrong Choice!!\n");
        }
    };
}
