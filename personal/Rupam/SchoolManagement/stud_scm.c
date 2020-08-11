/*School Mnagement Systems*/

#include "head.h"

struct student *chain[size];
struct student_disk readStud;

void read_stud();
void write_stud(struct student_disk stud);
void delete_stud_file(struct student_disk stud_data);
void update_stud_file(struct student_disk stu_data);
void insert_stud(struct student_disk readStud);
void display_stud();
void search_stud(int id);
void update_stud(int id);
void delete_stud(int id);

int num_records;

//init array of list to NULL
void
init_stud()
{
    int i;
    for(i = 0; i < size; i++) {
        chain[i] = NULL;
    }
}

//Read the student data from STUDENT text file
void
read_stud()
{
    num_records = 0;
    int fd;
    fd = open(STUDENT_DATAFILE, O_RDWR | O_CREAT, 0644);
    if(fd < 0) {
        perror("read failed");
    }
    while (read(fd, (void *)&readStud, sizeof(struct student_disk))) {
        printf("%d\t%d\t%s\t%s\t%s\t%d\n", readStud.index, readStud.id, readStud.name, readStud.class, readStud.address, readStud.contact);
        insert_stud(readStud);
        num_records = ++num_records;
    }
    printf("num_records = %d\n", num_records);
    close(fd);
}

//Write the student data into STUDENT text file
void
write_stud(struct student_disk stud)
{
    int fd;

    fd = open(STUDENT_DATAFILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("file open failed...");
    }
    write(fd, (void *)&stud, sizeof(struct student_disk));
    close(fd);
}

//insert values into STUDENT hash table
void
insert_stud(struct student_disk readStud)
{
    //create a newnode with value
    struct student *newNode = malloc(sizeof(struct student));
    newNode->std.index = readStud.index;
    newNode->std.id = readStud.id;
    strcpy(newNode->std.name, readStud.name);
    strcpy(newNode->std.class, readStud.class);
    strcpy(newNode->std.address, readStud.address);
    newNode->std.contact = readStud.contact;
    newNode->next = NULL;
    newNode->prev = NULL;
    //calculate hash key
    int key = readStud.id % size;

    if (chain[key] == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        chain[key] = newNode;
    } else {
          struct student *temp = chain[key];

          while (temp->next != NULL) {
              temp = temp->next;
          }
          temp->next = newNode;
          newNode->prev = temp;
          newNode->next = NULL;
      }
}

//DISPLAY data of STUDENT hash table
void
display_stud()
{
    int i;
    int index = 0;
    struct student *temp;
    printf("\n_______________________________________________________________________________\n\n");
    printf("INDEX.\tSR.\tSTUD_NAME\tCLASS\tADDRESS\t\tCONTACT\n\n");
    for(i = 0; i < size; i++) {
        temp = chain[i];
        while(temp) {
            printf("%d. ", index);
            printf("\t%d\t%s\t\t%s\t%s\t\t%d\n", temp->std.id, temp->std.name, temp->std.class, temp->std.address, temp->std.contact);
            temp = temp->next;
            index++;
        }
    }
}

//DELETE values from STUDENT text file
void
delete_stud_file(struct student_disk stud)
{
    int fd;
    struct student_disk temp;

    fd = open(STUDENT_DATAFILE, O_RDWR);

    lseek (fd, (num_records - 1) * sizeof (struct student_disk), SEEK_SET);
    read(fd, &temp, sizeof(struct student_disk));
    temp.index = stud.index;
    lseek(fd, temp.index * sizeof(struct student_disk), SEEK_SET);
    write(fd, &temp, sizeof(struct student_disk));
    num_records --;
    ftruncate(fd, num_records * sizeof(struct student_disk));
    printf("\n\n\tdelete successful\n");
    close(fd);
    
}

//DELETE values from STUDENT hash table
void
delete_stud(int id)
{
    int key = id % size;
    struct student *ptr = chain[key], *toDelete;

    if (ptr == NULL) {
        printf("\n\n\tList is Empty !!!\n");
    }
    else if (ptr->std.id == id) {
      delete_stud_file(ptr->std);
        chain[key] = chain[key]->next;
        //chain[key]->prev = NULL;
        ptr->next = NULL;
        free(ptr);
    } else {
      delete_stud_file(ptr->next->std);
      	  while (ptr->next != NULL) {
              if (ptr->next->std.id == id) {
                  toDelete = ptr->next;
                  if (toDelete->next == NULL) {
                      ptr->next = NULL;
                      free(toDelete);
                      return;
                      } else {
                            ptr->next = toDelete->next;
                            toDelete->next->prev = toDelete->prev;
                            free(toDelete);
                        }
              }
              ptr = ptr->next;
          }
      }
}

//SEARCH Student data from STUDENT hash table
void
search_stud(int id)
{
    struct student *ptr;
    int i=0, flag;
    int key = id % size;

    ptr = chain[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
          while (ptr != NULL) {
              if (ptr->std.id == id) {
                  printf("\n\n\tStudent id found at location %d ", i+1);
                  printf("\n\n\tStudent Prev - %p\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d\n\tStudent next - %p", ptr->prev, ptr->std.id, ptr->std.name, ptr->std.class, ptr->std.address, ptr->std.contact, ptr->next);
                  flag = 0;
                  break;
              } else {
                    flag=1;
                }
              i++;
              ptr = ptr -> next;
          }
          if (flag==1) {
              printf("\n\n\tStudent id not found\n");
          }
      }
}

//UPDATE student data from STUDENT hash table
void
update_stud(int id)
{
    struct student *ptr;
    int i=0, flag;
    int key = id % size;

    ptr = chain[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {
          while (ptr != NULL) {
              if (ptr->std.id == id) {
                  printf("\n\n\tStudent old Data !!!\n");
                  printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d",
                         ptr->std.id, ptr->std.name, ptr->std.class, ptr->std.address, ptr->std.contact);

  		            printf("\n\n\tStudent New Data !!!\n");

                  int id, contact;
                      char name[30], class[10], address[50];

                  printf("\n\tEnter Same ID : ");
                  scanf("\t %d", &id);
                  printf("\n\tEnter New Name : ");
                  scanf("\t %[^\n]%*c", name);
                  printf("\n\tEnter New Class : ");
                  scanf("\t %s", class);
                  printf("\n\tEnter New Address : ");
                  scanf("\t %s", address);
                  printf("\n\tEnter New Contact : ");
                  scanf("\t %d", &contact);

      		        ptr->std.id = id;
      		        strcpy(ptr->std.name, name);
      		        strcpy(ptr->std.class, class);
      		        strcpy(ptr->std.address, address);
      		        ptr->std.contact = contact;

  		            printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d",
                  ptr->std.id, ptr->std.name, ptr->std.class, ptr->std.address, ptr->std.contact);
  		            printf("\n\n\tStudent Record Updated Successfully !!!\n\n");
                      flag = 0;
                  //printf("AAA: %d id %d index %d name %s\n", __LINE__, ptr->std.id, ptr->std.index, ptr->std.name);
                  break;
              } else {
                    flag = 1;
                }
              i++;
              ptr = ptr -> next;
          }
          if (flag == 1) {
              printf("\n\n\tStudent id not found\n");
          }
      }
      update_stud_file(ptr->std);
}

//update from STUDENT text file
void
update_stud_file(struct student_disk stu_data)
{
    int fd;
    fd = open(STUDENT_DATAFILE, O_RDWR , 0644);
    lseek (fd, stu_data.index * sizeof (struct student_disk), SEEK_SET);
    if (write(fd, &stu_data, sizeof(struct student_disk)) < 0) {
        perror("write failed");
        exit(1);
    }
    close(fd);
}
