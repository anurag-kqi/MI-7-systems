Persistency layer for various modules:

High Level design:

Need to support following operations from persistency point of view:
1. Read the records from the data file at the time of loading of the program
2. Add a new record by appending the new record at the end of the file
3. Upadate an existing record by inplace modification of the file
4. Delete the record by replacing the record to be deleted with the last record 
   in the file and then truncate the file with one record

Detailed Design:

1. Record structure: (Please record all the on-disk record formats here)

    There should be two parts for each type of records, on disk and in memory

    For example for student:
        //on disk structure
        struct student_disk {
            int id; //user provided ID
            int index; //location of this record in the data file
            char name[MAXLEN];
            char phone[MAXLEN];
        }
        //in memory structure
        struct student {
            struct student_disk std;
            struct student *next, *prev;
        }

2. Reading of records at the start of the program:

    student_load function, taking student data file as an argument.
    - open the data file using open(fiename, O_RDONLY), no need to create file it does not exist.
    - read all the records using following structure
        struct student_disk std; // allocating memory on the stack or you might do malloc
        num_record = 0;
        while (read(fd, &std, sizeof(student_disk))) {
            student = malloc(sizeof (studnet));
            student.std = std;
            student.next = NULL;
            student.prev = NULL;
            //add student to hash table, need to make sure the hashing code is modified to take name from student.std.name
            num_record++:
        }
        save the number of records (num_record) in a global field for the student
    - close the file

3. Add / insert of new record:
    You must check that record does not exist in the hash table with the same id, if you want to apply that constraint
    - you will have incore student record where you have collected data based on the input from user
    - you need to first set the index of this record. T
        1. You know the number of records (num_records) already present. 
            set index for the new recor (student.std.index = num_records)
        2. Increment the global num_record by 1
        3. open the file with O_CREATE | O_RDWR | O_APPEND, 0644
        4. write(fd, &student.std, sizeof(struct student_disk))
        5. close the file

4. Update of the record:
    - You have located the record in memory from the hash table, no linear search of records on disk
    - First update the data in the hash table element
    - You open the file in the O_RDWR mode, no need to create file
    - Get the index from student record (index = student.std.index)
    - lseek(fd, index * sizeof(struct student_disk), 0)
    - write (fd, &student.std, sizeof(...))
    - close the file

5. Delete of the record:
    - What is the main challenge in removing record from file?
      - in memory you can free any node in the hash table, but on disk file needs 
        to be contiguous, you can't delete a record in the middle of the file
    - solution:
        - swap you record with the last record
        - make sure you update the index for the last record properly
        - truncate the file by one record

    - For example: you have 10 records in your data file, and you want to delete record number 4
    - num_record = 10
    - index of record to be deleted is 4
    - you can't find the last record in hash table, because you don't have the id for the record
    - So go to disk and read the last record:
        - open(file, O_RDWR)
        - lseek ((num_record - 1) * sizeof (student_disk), 0)
        - read the last record
    - set the index of the last record as 4 (std.index = 4)
    - write the record at the 4th record location on the disk:    
        - lseek ( 4 * sizeof (student_disk), 0)
        - write the updated last record there
    - find the last record in hash table, because you now have the ID for the record and update the index to that in memory record to 4
    - remove the last record:
        - num_record --;
        - ftrucate(fd, num_record * sizeof (student_disk)
    - close the file

Test cases:
- how are you testing that your code is working
- test1:
    add, update, delete
- test2:
    add, exit, start, update, stop, start
- test3:
    start, delete, stop, start, list

