Project : Society Management System

A. Project Modules :
  1. structure :

    - There should be two parts for each type of records,
      on disk and in memory
    - There are four structures society, maintenance, visitors and complaints.

     struct socDisk {
        int flat_num;
        int index;
        int new_flat_num;
        char owner_name[30];
        int owner_contact;
      }
      struct society {
        struct socDisk soc;
        struct society next*;
        struct society prev*;
      }

      struct mainDisk {
        int flat_num1;
        int index;
        int water_bill;
        int electricity_bill;
        int new_water_bill;
        int new_electricity_bill;
      }
        struct maintenance {
          struct mainDisk main;
          struct maintenance next*;
          struct maintenance prev*;
        }

      struct visitDisk {
          int vehicle_num;
          int index;
          char visitor_name[30];
          int new_vehicle_num;
          int visitor_contact;
          int TimeIn;
          int TimeOut;

          }
          struct visitors {
            struct visitDisk main;
            struct visitors next*;
            struct visitors prev*;
          }

      struct compDisk {
          int flat_number;
          int index;
          char complaints_name[50];
          char suggestions_name[50];
          int new_flat_number;
      }
          struct complaints {
          struct compDisk comp;
          struct complaint next*;
          struct complaints prev*;
          }

  AA>> Please mention the structure to keep track of num_records

  2. Reading of records at the start of the program:

    - read_soc/read_main/read_visit/read_comp function, taking society data files as
      an argument. 
    - open the data file using open(fiename, O_RDONLY).
    - read all the records using following structure
      struct soDisk std; AA>> change the name of the field
    - insert record into hash table using function insert_society()/insert_maintenance()/insert_visitors()/insert_complaints();
    - close the file

  3. Add / insert of new record:

    record should not be exist in the hash table with the same id
    - you will have incore student record where you have
      collected data based on the input from user
    - you need to first set the index of this record. T
      1. You know the number of records (num_records)already present.
      set index for the new recor (society.std.index = num_records)
      2. Increment the global num_record by 1
      3. open the file with O_CREATE | O_RDWR | O_APPEND, 0644
      4. write(fd, &society.std, sizeof(struct soc_disk))
      5. close the file

  4. Update of the record:

    - First update the data in the hash table element
    - You open the file in the O_RDWR mode
    - Get the index from student record (index = society.std.index)
    - lseek(fd, index * sizeof(struct soc_disk), 0)
    - write (fd, &societyt.std, sizeof(...))
    - close the file

  5. Delete of the record:

    - open the file open(file, O_RDWR)
    - swap you record with the last record
    - make sure you update the index for the last record properly
    - truncate the file by one record
    - close the file

  6. Search Record:

    - once you have file records in to the hash table
    - take the id from user which you want to Search
    - srearch in to hash table
    - if search id == hash table id then display msg element is present
    - else display element is not present

  7. Display Records:

    - you can display hash table or file Records
    - to display file records use function read_society() /
      read_maintenance()/read_visitors()/read_complaints();
    - to display hash table travers the hash table upto end
      display all the records.

B. Project Files:

  1. society_management.c
     - it contains main() function and function calls
          - init_society();
          - init_maintenance();
          - init_visitors();
          - init_complaints();
          - read_society();
          - read_maintenance();
          - read_visitors();
          - read_complaints();
          - menus();
  2. menu.c
     - it contains switch statement of menus and function
       calls
     - main menus :
          - INSERT
          - DISPLAY
          - DELETE
          - SEARCH
          - UPDATE
          - EXIT
     - sub menus :
          - SOCIETY
          - MAINTENANCE
          - VISITORS
          - COMPLAINTS
          - EXIT
    - every main menu contain sub menu

  3. society_scm.c
     - it contains defination of functions used in project
          - init_society();
          - insert_society();
          - delete_society();
          - display_society();
          - search_society();
          - update_society();

  4. maintenance_scm.c
     - it contains defination of functions used in project
          - init_maintenance();
          - insert_maintenance();
          - delete_maintenance();
          - display_maintenance();
          - search_maintenance();
          - update_maintenance();

  5. visitors_scm.c
     - it contains defination of functions used in project
          - init_visitors();
          - insert_visitors();
          - delete_visitors();
          - display_visitors();
          - search_visitors();
          - update_visitors();

  6. complaints_scm.c
     - it contains defination of functions used in project
          - init_complaints();
          - insert_complaints();
          - delete_complaints();
          - display_complaints();
          - search_complaints();
          - update_complaints();

 7. society_persistency.c
    - it contains functions used for persistency
          - read_society();
          - write_society();
          - modify_society();
          - del_society();

 8. maintenance_persistency.c
    - it contains functions used for persistency
          - read_maintenance();
          - write_maintenance();
          - modify_maintenance();
          - del_maintenance();

 9. visitors_persistency.c
    - it contains functions used for persistency
          - read_visitors();
          - write_visitors();
          - modify_visitors();
          - del_visitors();

 10. complaints_persistency.c
    - it contains functions used for Persistency
          - read_complaints();
          - write_complaints();
          - modify_complaints();
          - del_complaints();

 11. Makefile
    - it contain commands required for compile and run the
      program
    - commands :
          - make build (for compile)
          - ./scm (for run)
          - make clean (to remove .o files/ output files)
