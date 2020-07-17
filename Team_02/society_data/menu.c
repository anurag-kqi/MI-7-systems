#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "soc.h"

// struct socData
// {
//   int index;
//   char owner_name[30];
//   int flat_num;
//   int owner_contact;
// };

struct socData soc;
//extern void insert_soc(owner_name, flat_num, owner_contact);
extern void insert_soc(struct socData soc_data);

extern void display_soc();
extern void delete_soc(int flat_num);
extern void update_soc(int flat_num);
extern void search_soc(int flat_num);

//file read functions
extern void read_soc();
extern void write_soc(struct socData soc);

//main menu function
void menus()
{
  int flat_num, owner_contact, index, ch;
  char owner_name;
  //char owner_name[30], complaints_name[50], suggestions_name[50], visitor_name[30];
  //int flat_num, flat_num1, new_flat_num, flat_number, new_flat_number, owner_contact, visitor_contact,TimeIn,TimeOut, water_bill, electricity_bill, new_water_bill, new_electricity_bill, vehicle_num, new_vehicle_num, ch;
  while(1) {

      printf("\n MANAGEMENT DATA");
      printf("\n1.insert data\n2.Display data\n3.update data\n4.search data\n6.Exit");
      printf("\nEnter your choice(1-6) : ");
      scanf("%d", &ch);
      switch(ch) {
          case 1:printf("\nINSERT IN TO");
                 printf("\n1.Society data\n2.Maintenance data\n3.visitor data\n4.complaints data\n5.Exit(0)");
                 printf("\n\nEnter your choice to insert(1-5):");
                 scanf("%d", &ch);

                  switch(ch)
                  {
                      case 1: printf("\n\tEnter Index : ");
                	      scanf("\t\n %d", &soc.index);
                              printf("\n\tEnter owner_name : ");
                              scanf("\t\n %[^\n]%*c", soc.owner_name);
                              printf("\n\tEnter flat_num : ");
                              scanf("\t\n%d", &soc.flat_num);
                              printf("\n\tEnter owner_contact : ");
                              scanf("\t\n %d", &soc.owner_contact);
                              //insert_soc(struct society soc_data);
                              insert_soc(soc);
                              write_soc(soc);
				                      //read_soc();
        	                    break;
                              case 5: exit(0);

                      default: printf("\n\n\tWrong Choice!!\n");
                  }
                      break;

          case 2:printf("\nDISPLAY SOCIETY DATA");
                 printf("\n1.society data\n2.maintenance data\n3.visitor data\n4.complaint data\n5.Exit(0)");
                 printf("\n\nEnter your choice to display(1-4):");
                 scanf("%d", &ch);

                  switch(ch)
                  {
                      case 1:
                      

                      display_soc();
                //       read_soc();
                              break;

                                        /*  case 2: display_maintenance_D();
                                                  break;
                                          case 3: display_visitors_D();
                                                  break;
                                          case 4: display_complaints_D();
                                                  break;*/
                      case 5: exit(0);

                      default: printf("Wrong Choice!!");
                  }
                      break;

        /*  case 3: printf("\n\n\t---- DELETE FROM ----");
                  printf("\n\n\t1.SOCIETY DATA\n\t3.EXIT");
                  printf("\n\n\tEnter your choice to delete(1-3) : ");
                  scanf("\t %d", &ch);

                    switch(ch)
                    {
                        case 1: printf("\n\n\tEnter flat  number for Delete : ");
                                scanf("\t %d", &flat_num);
        				                delete_soc(flat_num);
                                break;
                                //case 2: delete_teacher();
                                        //break;
                                case 3: exit(0);

                                default: printf("\n\n\tWrong Choice!!\n");
                            }
                            break;*/

            case 3: printf("\n\n\t---- UPDATE FROM ----");
                    printf("\n\n\t1.SOCIETY DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to update(1-3) : ");
                    scanf("\t %d", &ch);
                      switch(ch)
                      {
                          case 1: printf("\n\n\tEnter flat number for Update : ");
                                  scanf("\t %d", &flat_num);
        				                  update_soc(flat_num);
                                  break;

                          case 3: exit(0);

                          default: printf("\n\n\tWrong Choice!!\n");
                      }
                          break;

        	  case 4: printf("\n\n\t---- SEARCH FROM ----");
                    printf("\n\n\t1.SOCIETY DATA\n\t3.EXIT");
                    printf("\n\n\tEnter your choice to search(1-3) : ");
                    scanf("\t %d", &ch);

                      switch(ch)
                      {
                            case 1: printf("\n\n\tEnter flat number for Search : ");
                                    scanf("\t%d", &flat_num);
        				                    search_soc(flat_num);
                                    break;

                            case 3: exit(0);

                            default: printf("\n\n\tWrong Choice!!\n");
                            }
                            break;

            case 6: exit(0);

        	    default: printf("\n\n\tWrong Choice!!\n");
            }
          };
        }
