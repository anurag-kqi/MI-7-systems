#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

struct student_disk stud;
struct teacher_disk teach;

//student hashtable operations
extern void display_stud();
extern void delete_stud(int id);
extern void update_stud(int id);
extern void search_stud(int id);
//teacher hashtable operations
extern void insert_teach(struct teacher_disk readTeach);
extern void display_teach();
extern void delete_teach(int id);
extern void update_teach(int id);
extern void search_teach(int id);
//file read functions
extern void read_stud();
extern void read_teach();
extern void write_stud(struct student_disk stud);
extern void write_teach(struct teacher_disk teach);
extern int num_records;
extern int num_record;
extern void delete_stud_file(struct student_disk stud_data);
extern void insert_stud(struct student_disk readStud);

//main menu function
void menus()
{
    int ch, id, index,j,digit,alpha;
    char name[30], address[50], class[10], department[30],contact[10]={0};

    while (1) {
	      printf("\n_______________________________________________________________________________");
        printf("\n\n\t---- SCHOOL MANAGEMENT SYSTEM MENU ----");
        printf("\n\n\t1.ADD ENTRY\n\t2.DISPLAY DATA\n\t3.DELETE ENTRY\n\t4.UPDATE ENTRY\n\t5.SEARCH ENTRY\n\t6.EXIT\n\n");
        printf("\n\tEnter your choice(1-6) : ");
        scanf("\t %d", &ch);
	      printf("\n_______________________________________________________________________________");
        switch (ch) {
            case 1:
                printf("\n\n\t---- INSERT IN TO ----");
                printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                printf("\n\n\tEnter your choice to insert(1-3) : ");
                scanf("\t %d", &ch);

                switch (ch) {
                    case 1: printf("\n\n\tIndex : %d" ,num_records);
                            stud.index = num_records;
                          	//scanf("\t %d", &stud.index);
                        		printf("\n\n\tEnter ID : ");
                        		scanf("\t %d", &stud.id);
                        		printf("\n\tEnter Name : ");
                        		scanf("\t %[^\n]%*c", stud.name);
					                  for (j=0; name[j]!= '\0'; j++)
    				                {
       		    		              if (isalpha(name[j]) != 0)
            	        		          alpha++;

  	      	    		            else if (isdigit(name[j]) != 0)
            				                digit++;
    				                }
    				                if(alpha == 0 && digit > 0)
    				                {
		    		                    printf("Enter characters only\n");
    				                } else{

                        		    printf("\n\tEnter Class : ");
                        		    scanf("\t %s", stud.class);
                        		    printf("\n\tEnter Address : ");
                        		    scanf("\t %[^\n]%*c", stud.address);
                        		        do{
                                        printf("\n\tEnter Contact : ");
                        		            scanf("\t %d", &stud.contact);
                                        if(strnlen(contact, 10) != 10)
				                                {
					                                  printf("You Entered Invalid Contact\nPlz Enter 10 Digit Valid contact number!\n");
				                                }
				                            }while(strnlen(contact, 10) != 10);
                        		        insert_stud(stud);
                                    write_stud(stud);
                                    num_records++;
                            }
                            break;
                    case 2: printf("\n\n\tIndex : %d" ,num_record);
                            teach.index = num_record;
					                  printf("\n\n\tEnter ID : ");
                        		scanf("\t %d", &teach.id);
                        		printf("\n\tEnter Name : ");
                        		scanf("\t %[^\n]%*c", teach.name);
                            for (j=0; name[j]!= '\0'; j++)
    				                {
       		    		              if (isalpha(name[j]) != 0)
            	        		          alpha++;

  	      	    		            else if (isdigit(name[j]) != 0)
            				                digit++;
    				                }
    				                if(alpha == 0 && digit > 0)
    				                {
		    		                    printf("Enter characters only\n");
    				                } else{

                        		    printf("\n\tEnter Department : ");
                        		    scanf("\t %[^\n]%*c", teach.department);
                        		    do{
                                    printf("\n\tEnter Contact : ");
                        		        scanf("\t %d", &teach.contact);
                                    if(strnlen(contact, 10) != 10)
				                            {
					                              printf("You Entered Invalid Contact\nPlz Enter 10 Digit Valid contact number!\n");
				                            }
				                        }while(strnlen(contact, 10) != 10);
                        		    insert_teach(teach);
			                          write_teach(teach);
                                num_record++;
                            }
                            break;
                    case 3: exit(0);
                    default: printf("\n\n\tWrong Choice!!\n");
                }
            break;
            case 2: printf("\n\n\t---- DISPLAY DATA ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to display(1-3) : ");
                    scanf("\t%d", &ch);

                    switch (ch)
                    {
                        case 1: display_stud();
                                break;
                        case 2: display_teach();
                                break;
                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

            case 3: printf("\n\n\t---- DELETE FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to delete(1-3) : ");
                    scanf("\t %d", &ch);

                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter Student id for Delete : ");
                                scanf("\t %d", &stud.id);
    				                    delete_stud(stud.id);
                                break;

                        case 2: printf("\n\n\tEnter Teacher id for Delete : ");
                                scanf("\t %d", &teach.id);
    				                    delete_teach(teach.id);
                                break;

                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

            case 4: printf("\n\n\t---- UPDATE FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to update(1-3) : ");
                    scanf("\t %d", &ch);

                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter Student ID for Update : ");
                                scanf("\t %d", &id);
				                        update_stud(id);
                                break;
                        case 2: printf("\n\n\tEnter Teacher ID for Update : ");
                                scanf("\t %d", &id);
				                        update_teach(id);
                                break;
                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

  	        case 5: printf("\n\n\t---- SEARCH FROM ----");
                    printf("\n\n\t1.STUDENT DATA\n\t2.TEACHER DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to search(1-3) : ");
                    scanf("\t %d", &ch);

                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter Student ID for Search : ");
                                scanf("\t%d", &id);
				                        search_stud(id);
                                break;
                        case 2: printf("\n\n\tEnter Teacher ID for Search : ");
                                scanf("\t%d", &id);
				                        search_teach(id);
                                break;
                        case 3: exit(0);
                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                    break;

            case 6: exit(0);
      	    default: printf("\n\n\tWrong Choice!!\n");
        }
    }
}
