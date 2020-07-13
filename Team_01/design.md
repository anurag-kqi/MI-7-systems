Project : School Management System

A. Project Modules :
  1. structure :

    - There should be two parts for each type of records,   
      on disk and in memory
    - There are two structures student and teacher

     struct studDisk {
        int id;
        int index;
        char name[30];
        char class[10];
        char  address[50];
        int contact;
      }
      struct student {
        struct studDisk stud;
        struct student next*;
        struct student prev*;
      }

      struct teacherDisk {
          int id;
          int index;
          char name[30];
          char department[50];
          int contact;
        }
        struct teacher {
          struct teacherDisk tchr;
          struct teacher next*;
          struct teacher prev*;
        }

  2. Reading of records at the start of the program:

    - read_stud/read_teacher function, taking student data file as
      an argument.
    - open the data file using open(fiename, O_RDONLY).
    - read all the records using following structure
      struct studDisk std;
    - insert record into hash table using function insert_stud()/insert_teacher();
    - close the file

  3. Add / insert of new record:

    record should not be exist in the hash table with the same id
    - you will have incore student record where you have
      collected data based on the input from user
    - you need to first set the index of this record. T
      1. You know the number of records (num_records)already    present.
      set index for the new recor (student.std.index = num_records)
      2. Increment the global num_record by 1
      3. open the file with O_CREATE | O_RDWR | O_APPEND, 0644
      4. write(fd, &student.std, sizeof(struct student_disk))
      5. close the file

  4. Update of the record:

    - First update the data in the hash table element
    - You open the file in the O_RDWR mode
    - Get the index from student record (index = student.std.index)
    - lseek(fd, index * sizeof(struct student_disk), 0)
    - write (fd, &student.std, sizeof(...))
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
    - to display file records use function read_stud() /
      read_teacher();
    - to display hash table travers the hash table upto end
      display all the records.

B. Project Files:  

  1. school_management.c
     - it contains main() function and function calls
          - init_stud();
          - init_teacher();
          - read_stud();
          - read_teacher();
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
          - STUDENT
          - TEACHER
          - EXIT
    - every main menu contain sub menu

  3. stud_scm.c
     - it contains defination of functions used in project
          - init_stud();
          - insert_stud();
          - delete_stud();
          - display_stud();
          - search_stud();
          - update_stud();

  4. teacher_scm.c
     - it contains defination of functions used in project
          - init_teacher();
          - insert_teacher();
          - delete_teacher();
          - display_teacher();
          - search_teacher();
          - update_teacher();

 5. stud_persistency.c
    - it contains functions used for persistency
          - read_stud();
          - write_stud();
          - modify_stud();
          - del_stud();

 6. stud_persistency.c
    - it contains functions used for persistency
          - read_teacher();
          - write_teacher();
          - modify_teacher();
          - del_teacher();

 7. Makefile
    - it contain commands required for compile and run the
      program
    - commands :
          - make build (for compile)
          - ./scm (for run)
          - make clean (to remove .o files/ output files)
