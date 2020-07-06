#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*file pointer*/
FILE *fptr;

/*society operations*/
extern void insert_society_D(char owner_name[], int flat_num, int owner_contact);
extern void display_society_D();
extern void search_society_D(int flat_num);
extern void update_society_D(int flat_num, int new_flat_num);
extern void delete_society_D(int flat_num);

/*maintenance operations*/
extern void insert_maintenance_D(int flat_num1, int water_bill, int electricity_bill);
extern void display_maintenance_D();
extern void search_maintenance_D(int flat_num1);
extern void update_maintenance_D(int water_bill, int electricity_bill,int new_water_bill, int new_electricity_bill) ;
extern void delete_maintenance_D(int flat_num1);

/*visitors operations*/
extern void insert_visitors_D(char visitor_name[], int vehicle_num, int visitor_contact, int TimeIn, int TimeOut);
extern void display_visitors_D();
extern void search_visitors_D(int vehicle_num);
extern void update_visitors_D(int vehicle_num, int new_vehicle_num);
extern void delete_visitors_D(int vehicle_num);

/*complaints operations*/
extern void insert_complaints_D(int flat_number, char complaints_name[],char suggestions_name[]);
extern void display_complaints_D();
extern void search_complaints_D(int flat_number);
extern void update_complaints_D(int flat_number, int new_flat_number);
extern void delete_complaints_D(int flat_number);

/*file read functions*/
extern void read_society_D();
extern void read_maintenance_D();
extern void read_visitors_D();
extern void read_complaints_D();

extern void write_society_D(char owner_name[30], int flat_num, int owner_contact);
extern void write_maintenance_D(int flat_num1, int water_bill, int electricity_bill);
extern void write_visitors_D(char visitor_name[], int vehicle_num, int visitor_contact, int TimeIn, int TimeOut);
extern void write_complaints_D(int flat_number, char complaints_name[],char suggestions_name[]);

/*main menu function*/
void menu()
{
  char owner_name[30], complaints_name[50], suggestions_name[50], visitor_name[30];
  int flat_num, flat_num1, new_flat_num, flat_number, new_flat_number, owner_contact, visitor_contact,TimeIn,TimeOut, water_bill, electricity_bill, new_water_bill, new_electricity_bill, vehicle_num, new_vehicle_num, ch;
  while(1) {

      printf("\n MANAGEMENT DATA");
      printf("\n1.insert data\n2.Display data\n3.search data\n4.update data\n5.delete data\n6.Exit");
      printf("\nEnter your choice(1-6) : ");
      scanf("%d", &ch);
      switch(ch) {
          case 1:printf("\nINSERT IN TO");
                 printf("\n1.Society data\n2.Maintenance data\n3.visitor data\n4.complaints data\n5.Exit(0)");
                 printf("\n\nEnter your choice to insert(1-5):");
                 scanf("%d", &ch);

                  switch(ch)
                  {
                      case 1: //fptr = (fopen("society_D.txt","a+"));
                              printf("\n\n\tEnter owner_name : ");
                              scanf("\t %[^\n]%*c", owner_name);
                              printf("\n\tEnter flat_num : ");
                              scanf("\t %d", &flat_num);
                              printf("\n\tEnter owner_contact : ");
                              scanf("\t %d", &owner_contact);
                              write_society_D(owner_name, flat_num, owner_contact);
				                      read_society_D();
        	                    break;

                      case 2: //fptr = (fopen("maintenance_D.txt","a+"));
                              printf("\n\n\tEnter flat_num1 : ");
                              scanf("\t %d", &flat_num1);
                              printf("\n\n\tEnter water_bill : ");
                              scanf("\t %d", &water_bill);
                              printf("\n\tEnter electricity_bill : ");
                              scanf("\t %d", &electricity_bill);
                              write_maintenance_D(flat_num1, water_bill, electricity_bill);
				                      read_maintenance_D();
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
                              write_visitors_D(visitor_name, vehicle_num, visitor_contact, TimeIn, TimeOut);
				                      read_visitors_D();
                              break;

                      case 4: //fptr = (fopen("complaints_D.txt","a+"));
                              printf("\n\tEnter complainter's flat_number : ");
                              scanf("\t %d", &flat_number);
                              printf("\n\n\t Enter the complaints_name : ");
                              scanf("\t %[^\n]%*c", complaints_name);
                              printf("\n\n\t Enter the suggestions_name : ");
                              scanf("\t %[^\n]%*c", suggestions_name);
                              write_complaints_D(flat_number, complaints_name, suggestions_name);
				                      read_complaints_D();
                              break;
                      case 5: exit(0);


                      default: printf("Wrong Choice!!");
                   }
                  break;

          case 2: printf("\nDISPLAY SOCIETY DATA");
                  printf("\n1.society data\n2.maintenance data\n3.visitor data\n4.complaint data\n5.Exit(0)");
                  printf("\n\nEnter your choice to display(1-4):");
                  scanf("%d", &ch);

                  switch(ch)
                  {
                      case 1: display_society_D();
                              break;

                      case 2: display_maintenance_D();
                              break;
                      case 3: display_visitors_D();
                              break;
                      case 4: display_complaints_D();
                              break;
                      case 5: exit(0);

                      default: printf("Wrong Choice!!");
                  }
                  break;

          case 3: printf("\nSEARCH");
                  printf("\n1.Society data\n2.Maintenance data\n3.visitors data\n4.complaints data\n5.EXIT");
                  printf("\n\nEnter your choice to search(1-5):");
                  scanf("%d", &ch);
                  switch(ch)
                  {
                      case 1: printf("enter flat_num for search:");
                              scanf("%d",&flat_num);
                              search_society_D(flat_num);
                              break;
                      case 2: printf("enter flat_num1 for search:");
                              scanf("%d",&flat_num1);
                              search_maintenance_D(flat_num1);
                              break;
                      case 3: printf("enter vehicle_num for search:");
                              scanf("%d",&vehicle_num);
                              search_visitors_D(vehicle_num);
                              break;
                      case 4: printf("enter complainter's flat_number for search:");
                              scanf("%d", &flat_number);
                              search_complaints_D(flat_number);
                              break;
                      case 5: exit(0);
                      default: printf("Wrong Choice");
                      }
                      break;
          case 4: printf("\nupdate");
                  printf("\n1.Society data\n2.Maintenance data\n3.visitors data\n4.complaints data\n5.EXIT");
                  printf("\n\nEnter your choice to search(1-5):");
                  scanf("%d", &ch);

                  switch(ch)
                 {
                   case 1: printf("\n\n\tEnter old flat_num : ");
                           scanf("\t %d", &flat_num);
                           printf("\n\n\tEnter new_flat_num for Update : ");
                           scanf("\t %d", &new_flat_num);
                           update_society_D(flat_num, new_flat_num );
                           break;
                   case 2: printf("\n\n\tEnter water_bill for Update : ");
                           scanf("\t %d", &water_bill);
                           printf("\n\n\tEnter new_water_bill for Update : ");
                           scanf("\t %d", &new_water_bill);
                           printf("\n\n\tEnter electricity_bill for Update : ");
                           scanf("\t %d", &electricity_bill);
                           printf("\n\n\tEnter new_electricity_bill for Update : ");
                           scanf("\t %d", &new_electricity_bill);
                           update_maintenance_D(water_bill, electricity_bill, new_water_bill, new_electricity_bill);
                           break;
                   case 3: printf("\n\n\tEnter vehicle_num for Update : ");
                           scanf("\t %d", &vehicle_num);
                           printf("\n\n\tEnter new_vehicle_num for Update : ");
                           scanf("\t %d", &new_vehicle_num);
                           update_visitors_D(vehicle_num, new_vehicle_num);
                           break;
                   case 4: printf("\n\n\tEnter flat_number for Update : ");
                           scanf("\t %d", &flat_number);
                           printf("\n\n\tEnter new_flat_number for Update : ");
                           scanf("\t %d", &new_flat_number);
                           update_complaints_D(flat_number, new_flat_number);
                           break;
                   case 5: exit(0);

                   default: printf("\n\n\tWrong Choice!!\n");
               }
               break;

       case 5: printf("\nDELETE FROM");
               printf("\n1.Society DATA\n2.Maintenance data\n3.visitors data\n4.complaints data\n5.EXIT");
               printf("\n\nEnter your choice to delete(1-5):");
               scanf("%d", &ch);

               switch(ch)
               {
                   case 1: printf("enter flat_num for delete:");
                           scanf("%d",&flat_num);
                           delete_society_D(flat_num);
                           break;
                   case 2: printf("enter flat_num1 for delete:");
                           scanf("%d", &flat_num1);
                           delete_maintenance_D(flat_num1);
                           break;

                    case 3:
                           printf("enter vehicle_num for delete:");
                           scanf("%d", &vehicle_num);
                           delete_visitors_D(vehicle_num);
                           break;

                    case 4:
                           printf("enter complainter's flat_number for delete:");
                           scanf("%d", &flat_number);
                           delete_complaints_D(flat_number);
                           break;
                   case 5: exit(0);
                   default: printf("Wrong Choice");
               }
               break;
       case 6: exit(0);

             }
         };
        //eturn 0;
       }
