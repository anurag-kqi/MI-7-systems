#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maint.h"//headher file which contains structure

struct maintData maint;

extern void insert_maint(struct maintData maint_data);
extern void search_maint(int flat_num1);
extern void update_maint_file(struct maintData update);
extern void read_maint();
extern void write_maint(struct maintData maint);
extern int num_records;
extern void display_maint();
extern void update_maint(int flat_num1);
//extern void delete_soc(int flat_num);

//main menu function
void menus()
{
  int flat_num1, water_bill, electricity_bill, index, ch;
    //char owner_name[30], complaints_name[50], suggestions_name[50], visitor_name[30];
  //int flat_num, flat_num1, new_flat_num, flat_number, new_flat_number, owner_contact, visitor_contact,TimeIn,TimeOut, water_bill, electricity_bill, new_water_bill, new_electricity_bill, vehicle_num, new_vehicle_num, ch;
  while(1) {

      printf("\n==================================================================");
      printf("\n\t\t MANAGEMENT DATA\n");
      printf("\n\t1. Insert Data\n\t2. Display Data\n\t3. Search Data\n\t4. Update Data\n\t5. Delete Data\n\t6. Exit");
      printf("\n\n\tEnter your choice(1-6) : ");
      scanf("%d", &ch);
      switch(ch) {
          case 1:
                printf("\n==================================================================");
                printf("\n\t\tINSERT IN TO\n");
                printf("\n\t1. Society Data\n\t2. Maintenance Data\n\t3. Visitor Data\n\t4. Complaints Cata\n\t5. Exit(0)");
                printf("\n\n\tEnter your choice to insert(1-5):");
                scanf("%d", &ch);

                  switch(ch)
                  {
                      case 2:
                              printf("\n==================================================================");
                              printf("\n\t\tINSERT MAINTENANCE DATA\n");
                              printf("Index: %d", num_records);
                              maint.index = num_records;
                              printf("\n\tEnter flat_num : ");
                              scanf("\t\n %d", &maint.flat_num1);
                              printf("\n\tEnter water_bill : ");
                              scanf("\t\n %d", &maint.water_bill);
                              printf("\n\tEnter electricity_bill :");
                              scanf("\t\n %d", &maint.electricity_bill);
                              insert_maint(maint);
                              write_maint(maint);
                              num_records++;
				                      break;
                      /*case 2:
                              printf("\n\n\tEnter flat_num1 : ");
                              scanf("\t %d", &flat_num1);
                              printf("\n\n\tEnter water_bill : ");
                              scanf("\t %d", &water_bill);
                              printf("\n\tEnter electricity_bill : ");
                              scanf("\t %d", &electricity_bill);
                              //write_maintenance_D(flat_num1, water_bill, electricity_bill);
				                      //read_maintenance_D();
                              break;

                      case 3: //fptr = (fopen("visitors_D.txt","a+"));
                              printf("\n\n\tEnter Visitors Name: ");
                              scanf("\t%[^\n]%*c",visitor_name);
                              printf("\n\t Enter Vehicle Number: ");
                              scanf("\t%d",&vehicle_num);
                              printf("\n\t Enter visitor contact: ");
                              scanf("\t%d",&visitor_contact);
                              printf("\n\tEnter Visitor TimeIn: ");
                              scanf("\t%d",&TimeIn);
                              printf("\n\tEnter Visitor TimeOut: ");
                              scanf("\t%d",&TimeOut);
                              //fprintf(fptr, "%s\n %d\n %d\n %d\n %d\n", visitor_name, vehicle_num, visitor_contact, TimeIn, TimeOut);
                              //fclose(fptr);
                              //write_visitors_D(visitor_name, vehicle_num, visitor_contact, TimeIn, TimeOut);
				                      //read_visitors_D();
                              break;

                      case 4: //fptr = (fopen("complaints_D.txt","a+"));
                              printf("\n\tEnter complainter's flat_number : ");
                              scanf("\t %d", &flat_number);
                              printf("\n\n\t Enter the complaints_name : ");
                              scanf("\t %[^\n]%*c", complaints_name);
                              printf("\n\n\t Enter the suggestions_name : ");
                              scanf("\t %[^\n]%*c", suggestions_name);
                              //write_complaints_D(flat_number, complaints_name, suggestions_name);
				                      //read_complaints_D();
                              break;*/
                      case 5: exit(0);

                      default: printf("\n\n\tWrong Choice!!\n");
                  }
                      break;

          case 2:
                printf("\n==================================================================");
                printf("\n\t\tDISPLAY DATA\n");
                printf("\n\t1. Society Data\n\t2. Maintenance Data\n\t3. Visitor Data\n\t4. Complaint Data\n\t5. Exit(0)");
                printf("\n\n\tEnter your choice to display(1-4):");
                scanf("%d", &ch);

                  switch(ch)
                  {
                      case 2:
                            display_maint();
                            break;

                      /*case 2:
                            display_maintenance_D();
                            break;

                      case 3:
                            display_visitors_D();
                            break;

                      case 4:
                            display_complaints_D();
                            break;*/

                      case 5: exit(0);

                      default: printf("Wrong Choice!!");
                  }
                      break;

            case 3:
                  printf("\n==================================================================");
                  printf("\n\t\tSEARCH DATA FROM\n");
                  printf("\n\t1. Society Data\n\t2. Maintenance Data\n\t3. Visitor Data\n\t4. Complaint Data\n\t5. Exit(0)");
                  printf("\n\n\tEnter your choice to search(1-3) : ");
                  scanf("\t %d", &ch);

                  switch(ch)
                  {
                      case 2:
                            printf("\n==================================================================");
                            printf("\n\n\tEnter flat number for Search : ");
                            scanf("\t%d", &flat_num1);
                            search_maint(flat_num1);
                            break;

                      /*case 2:
                            printf("enter flat_num1 for search:");
                            scanf("%d",&flat_num1);
                            search_maintenance_D(flat_num1);
                            break;

                      case 3:
                            printf("enter vehicle_num for search:");
                            scanf("%d",&vehicle_num);
                            search_visitors_D(vehicle_num);
                            break;

                      case 4:
                            printf("enter complainter's flat_number for search:");
                            scanf("%d", &flat_number);
                            search_complaints_D(flat_number);
                            break;*/

                      case 5:
                            exit(0);

                      default: printf("\n\n\tWrong Choice!!\n");
                  }
                        break;

            case 4:
                  printf("\n==================================================================");
                  printf("\n\t\tUPDATE DATA FROM\n");
                  printf("\n\t1. Society Data\n\t2. Maintenance Data\n\t3. Visitor Data\n\t4. Complaint Data\n\t5. Exit(0)");
                  printf("\n\n\tEnter your choice to update(1-5) : ");
                  scanf("\t %d", &ch);
                    switch(ch)
                    {
                        case 2: printf("\n\n\tEnter flat number for Update : ");
                                scanf("\t %d", &flat_num1);
      				                  update_maint(flat_num1);
                                break;

                        case 5: exit(0);

                        default: printf("\n\n\tWrong Choice!!\n");
                    }
                        break;

            case 5:
                    printf("\n==================================================================");
                    printf("\n\t\tDELETE DATA FROM\n");
                    printf("\n\t1. Society Data\n\t2. Maintenance Data\n\t3. Visitor Data\n\t4. Complaint Data\n\t5. Exit(0)");
                    printf("\n\n\tEnter your choice to delete(1-5) : ");
                    scanf("\t %d", &ch);

                      switch(ch)
                      {
                          case 2: printf("\n\n\tEnter flat  number for Delete : ");
                                  scanf("\t %d", &flat_num1);
          				                //delete_soc(flat_num);
                                  break;

                          case 5: exit(0);

                                  default: printf("\n\n\tWrong Choice!!\n");
                              }
                              break;

            case 6: exit(0);

        	    default: printf("\n\n\tWrong Choice!!\n");
            }
          };
        }
