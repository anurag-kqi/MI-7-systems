/*School Mnagement Systems*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
#include <ctype.h>

=======
>>>>>>> 047907378d8f1e116c31bb81adb750348a6c9145
#define size 9
struct student 
{
    int id;
    char name[30];
    int class;
    char address[50];
    int contact;
    struct student *next;
    struct student *prev; 
};

struct teacher
{
    char department[30];
    struct student stud;
    struct teacher *next;
    struct teacher *prev; 
};
    struct student *chain[size];

    //student operations
    void insert_stud(int id, char name[], int class, char address[], int contact);
    void display_stud();
    void delete_stud(int id);
    void update_stud(int id);
    void search_stud(int id);

    //teacher operations
    //insert_teacher();
    //display_teacher();
    //delete_teacher();
    //update_teacher();
    //search_teacher();

//init array of list to NULL
void init()
{
    int i;
    for(i = 0; i < size; i++) {
        chain[i] = NULL;
    }
}

void insert_stud(int id, char name[], int class, char address[], int contact) 
{ 
    //create a newnode with value
    struct student *newNode = malloc(sizeof(struct student));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->class = class;
    strcpy(newNode->address, address);
    newNode->contact = contact;
    newNode->next = NULL;
    newNode->prev = NULL;

    //calculate hash key
    int key = id % size;  
    
    if(chain[key] == NULL) {  
        newNode->next = NULL;  
        newNode->prev = NULL;  
        chain[key] = newNode;  
    }  
    else {  
        struct student *temp = chain[key]; 

        while(temp->next != NULL){  
            temp = temp->next;  
        }  
        temp->next = newNode;  
        newNode->prev = temp;  
        newNode->next = NULL;  
    }  
    printf("\n\nNode inserted Successfully...!\n");  
}

/*void delete_stud(int id)
{
    int key = id % size;
    struct student *temp = chain[key], *toDelete;
    //if(temp != NULL)
    //{
        if(temp->id == id)
        {
            toDelete = temp;
            temp = temp->next;
            temp->prev = NULL;
            free(toDelete);
        }
        else
        {
            while(temp->next != NULL)
            {
                if(temp->next->id == id)
                {
                    toDelete = temp->next;
                    temp->next = toDelete->next;
                    toDelete->next->prev = temp;  
                    free(toDelete);
                }
                temp = temp->next;
            }
        }
    //}
}*/

void delete_stud(int id)  
{  
    int key = id % size;
    struct student *ptr = chain[key], *toDelete;  
  
    if(ptr == NULL) {  
        printf("\n List is Empty !!!");  
    }  
    else if(ptr->id == id && ptr->next == NULL) {  
        ptr = NULL;   
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
    else {  
	while(ptr->next != NULL) {
            if(ptr->next->id == id) {

                toDelete = ptr->next;  
        	ptr->next = toDelete->next;  
        	toDelete->next->prev = ptr;  
        	free(toDelete);  
            }
            ptr = ptr->next;
        }	
        printf("\nnode deleted successfully\n");  
    }     
}

void display_stud()
{
    int i;

    for(i = 0; i < size; i++) {
        struct student *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp) {
            printf("%d %s %d %s %d -->",temp->id, temp->name, temp->class, temp->address, temp->contact);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


<<<<<<< HEAD
void search_stud(int id)  
{  
    struct student *ptr;  
    int i=0, flag; 
    
    int key = id % size; 

    ptr = chain[key];   
    if(ptr == NULL) {  
        printf("\nEmpty List\n");  
    }  
    else {   
        
        //printf("\nEnter item which you want to search?\n");   
        //scanf("%d",&item);  
        while (ptr != NULL) {  
            if(ptr->id == id) {  
                printf("\nitem found at location %d ", i+1); 
                printf("\n\nStudent Id - %d\nStudent Nmae - %s\nStudent Class - %d\nStudent Address - %s\nStudent Contact - %d", 
                       ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact); 
                flag = 0;  
                break;  
            }   
            else {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1) {  
            printf("\nItem not found\n");  
        }  
    }              
} 

void update_stud(int id)  
{  
    struct student *ptr;  
    int i=0, flag; 
    
    int key = id % size; 

    ptr = chain[key];   
    if(ptr == NULL) {  
        printf("\nEmpty List\n");  
    }  
    else {   
          
        while (ptr != NULL) {  
            if(ptr->id == id) {  
                printf("\nStudent old Data !!!"); 
                printf("\n\nStudent Id - %d\nStudent Nmae - %s\nStudent Class - %d\nStudent Address - %s\nStudent Contact - %d", 
                       ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact); 

		printf("\nStudent New Data !!!");
		
		int id, contact, class;
    		char name[30], address[50];

		printf("Enter ID, Name, Class, Address, Contact respectively : ");
		scanf("%d %s %d %s %d", &id, &name, &class, &address, &contact);

		ptr->id = id;
    		strcpy(ptr->name, name);
    		ptr->class = class;
    		strcpy(ptr->address, address);
    		ptr->contact = contact;
    		
		printf("\n\nStudent Id - %d\nStudent Nmae - %s\nStudent Class - %d\nStudent Address - %s\nStudent Contact - %d", 
                       ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact); 
		printf("\nStudent Record Updated Successfully !!!");
                flag = 0;  
                break;  
            } 
	    else {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next; 
        } 
	 
        if(flag==1) {  
            printf("\nItem not found\n");  
        }  
    }     
          
} 
int 
=======
    ptr = chain[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {


        while (ptr != NULL) {
            if (ptr->id == id) {
                printf("\n\n\tStudent id found at location %d ", i+1);
                printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d",
                       ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact);
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

//SEARCH teacher data from TEACHER hash table
void search_teacher(int id)
{
    struct teacher *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = chaint[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {


        while (ptr != NULL) {
            if (ptr->id == id) {
                printf("\n\n\tTeacher id found at location %d ", i+1);
                printf("\n\n\tTeacher Id - %d\n\tTeacher Nmae - %s\n\tTeacher Department - %s\n\tTeacher Contact - %d",
                       ptr->id, ptr->name, ptr->department, ptr->contact);
                flag = 0;
                break;
            } else {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if (flag==1) {
            printf("\n\n\tTeacher id not found\n");
        }
    }
}

//UPDATE student data from STUDENT hash table
void update_stud(int id)
{
    struct student *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = chain[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {

        while (ptr != NULL) {
            if (ptr->id == id) {
                printf("\n\n\tStudent old Data !!!\n");
                printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d",
                       ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact);

		printf("\n\n\tStudent New Data !!!\n");

		int id, contact;
    		char name[30], class[10], address[50];

		printf("\n\tEnter Same ID : ");
		scanf("\t %d", &id);
		scanf("\t %[^\n]%*c", name);
		for (i=0; name[i]!= '\0'; i++) 
    		{ 
       		    if (isalpha(name[i]) != 0) 
            	        alpha++; 
  
  	      	    else if (isdigit(name[i]) != 0) 
            		digit++; 
    		} 
    		if(alpha == 0 && digit > 0)
    		{
		    printf("Enter characters only\n");
    		} else{
		    printf("\n\tEnter New Class : ");
		    scanf("\t %s", class);
		    printf("\n\tEnter New Address : ");
		    scanf("\t %s", address);
		    printf("\n\tEnter New Contact : ");
		    scanf("\t %d", &contact);

		    ptr->id = id;
    		    strcpy(ptr->name, name);
    		    strcpy(ptr->class, class);
    		    strcpy(ptr->address, address);
    		    ptr->contact = contact;
    		
		    printf("\n\n\tStudent Id - %d\n\tStudent Nmae - %s\n\tStudent Class - %s\n\tStudent Address - %s\n\tStudent Contact - %d", 
                           ptr->id, ptr->name, ptr->class, ptr->address, ptr->contact); 
		    printf("\n\n\tStudent Record Updated Successfully !!!\n");
                    flag = 0; 
		} 
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
}

//UPDATE teacher data from TEACHER hash table
void update_teacher(int id)
{
    struct teacher *ptr;
    int i=0, flag;

    int key = id % size;

    ptr = chaint[key];
    if (ptr == NULL) {
        printf("\n\n\tEmpty List\n");
    } else {

        while (ptr != NULL) {
            if (ptr->id == id) {
                printf("\n\n\tTeacher old Data !!!\n");
                printf("\n\n\tTeacher Id - %d\n\tTeacher Nmae - %s\n\tTeacher Department - %s\n\tTeacher Contact - %d",
                       ptr->id, ptr->name, ptr->department, ptr->contact);

		printf("\n\n\tTeacher New Data !!!\n");

		int id, contact;
    		char name[30], department[30];

		printf("\n\tEnter Same ID : ");
		scanf("\t %d", &id);
		printf("\n\tEnter New Name : ");
		scanf("\t %[^\n]%*c", name);
		for (i=0; name[i]!= '\0'; i++) 
    		{ 
       		    if (isalpha(name[i]) != 0) 
            		alpha++; 
  
        	    else if (isdigit(name[i]) != 0) 
            		digit++; 
    		} 
    		if(alpha == 0 && digit > 0)
    		{
		    printf("Enter characters only\n");
    		} else{
		    printf("\n\tEnter New Department : ");
		    scanf("\t %s", department);
		    printf("\n\tEnter New Contact : ");
		    scanf("\t %d", &contact);

		    ptr->id = id;
    		    strcpy(ptr->name, name);
    		    strcpy(ptr->department, department);
    		    ptr->contact = contact;

		    printf("\n\n\tTeacher Id - %d\n\tTeacher Nmae - %s\n\tTeacher Department - %s\n\tTeacher Contact - %d",
                           ptr->id, ptr->name, ptr->department, ptr->contact);
		    printf("\n\n\tTeacher Record Updated Successfully !!!\n");
                    flag = 0;
		}
                break;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr -> next;
        }

        if (flag == 1) {
            printf("\n\n\tTeacher id not found\n");
        }
    }

}

int
>>>>>>> 8349fba854ca053ac783d4d7d603829ff740c309
main()
{
    int ch, id, contact, class;
    char name[30], address[50];

    //init array of list to NULL
    init();
    while(1) {

        printf("\n\n---- SCHOOL MANAGEMENT SYSTEM MENU ----");
        printf("\n\n1.ADD ENTRY\n2.DISPLAY DATA\n3.DELETE ENTRY\n4.UPDATE ENTRY\n5.SEARCH ENTRY\n6.EXIT\n\n");
        printf("\nEnter your choice(1-6) : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                    printf("\n---- INSERT IN TO ----");
                    printf("\n1.STUDENT DATA\n2.TEACHER DATA\n3.EXIT");
                    printf("\n\nEnter your choice to insert(1-3):");
                    scanf("%d", &ch);
 
                    switch(ch)
                    {
<<<<<<< HEAD
                        case 1: printf("\n\n\tEnter ID : ");
				scanf("\t %d", &id);
				printf("\n\tEnter Name : ");
				scanf("\t %[^\n]%*c", name);
				for (i=0; name[i]!= '\0'; i++) 
    				{ 
       					 if (isalpha(name[i]) != 0) 
            					alpha++; 
  
        				 else if (isdigit(name[i]) != 0) 
            					digit++; 
    				} 
    
    				if(alpha == 0 && digit > 0)
    				{
					printf("Enter characters only\n");
    				}  
    				else
    				{
       				    printf("\n\tEnter Class : ");
				    scanf("\t %s", class);
				    printf("\n\tEnter Address : ");
				    scanf("\t %s", address);
				    printf("\n\tEnter Contact : ");
				    scanf("\t %d", &contact);
				    insert_stud(id, name, class, address, contact);
    				}
				
                                break;

<<<<<<< HEAD
<<<<<<< HEAD
=======
                        case 2: printf("\n\n\tEnter ID : ");
				scanf("\t %d", &id);
				printf("\n\tEnter Name : ");
				scanf("\t %[^\n]%*c", name);
				for (i=0; name[i]!= '\0'; i++) 
    				{ 
       				    if (isalpha(name[i]) != 0) 
            			        alpha++; 
  
        			    else if (isdigit(name[i]) != 0) 
            				digit++; 
    				} 
    				if(alpha == 0 && digit > 0)
    				{
				    printf("Enter characters only\n");
    				} else{
				    printf("\n\tEnter Department : ");
				    scanf("\t %s", department);
				    printf("\n\tEnter Contact : ");
				    scanf("\t %d", &contact);
				    insert_teacher(id, name, department, contact);
				}
                                break;
>>>>>>> 8349fba854ca053ac783d4d7d603829ff740c309

=======
=======
                        case 1: printf("Enter ID, Name, Class, Address, Contact respectively : ");
				scanf("%d %s %d %s %d", &id, &name, &class, &address, &contact);
				insert_stud(id, name, class, address, contact);
                                break;
                        //case 2: insert_teacher();
                               //break;
>>>>>>> parent of 88fe938... validation name
>>>>>>> 047907378d8f1e116c31bb81adb750348a6c9145
                        case 3: exit(0);

                        default: printf("Wrong Choice!!");
                    }
                    break;
 
            case 2: printf("\n---- DISPLAY DATA ----");
                    printf("\n1.STUDENT DATA\n2.TEACHER DATA\n3.EXIT");
                    printf("\n\nEnter your choice to display(1-3):");
                    scanf("%d", &ch);
 
                    switch(ch)
                    {
                        case 1: display_stud();
                                break;
                        //case 2: display_teacher();
                               // break;
                        case 3: exit(0);

                        default: printf("Wrong Choice!!");
                    }
                    break;
 
            case 3: printf("\n---- DELETE FROM ----");
                    printf("\n1.STUDENT DATA\n2.TEACHER DATA\n3.EXIT");
                    printf("\n\nEnter your choice to delete(1-3):");
                    scanf("%d", &ch);
 
                    switch(ch)
                    {
                        case 1: printf("Enter Student ID for Delete : ");
                                scanf("%d",&id);
				delete_stud(id);
                                break;
                        //case 2: delete_teacher();
                                //break;
                        case 3: exit(0);

                        default: printf("Wrong Choice!!");
                    }
                    break;

           case 4: printf("\n---- UPDATE FROM ----");
                    printf("\n1.STUDENT DATA\n2.TEACHER DATA\n3.EXIT");
                    printf("\n\nEnter your choice to update(1-3):");
                    scanf("%d", &ch);
 
                    switch(ch)
                    {
                        case 1: printf("Enter Student ID for Update : ");
                                scanf("%d",&id);
				update_stud(id);
                                break;
                        //case 2: update_teacher();
                                //break;
                        case 3: exit(0);

                        default: printf("Wrong Choice!!");
                    }
                    break;

	    case 5: printf("\n---- SEARCH FROM ----");
                    printf("\n1.STUDENT DATA\n2.TEACHER DATA\n3.EXIT");
                    printf("\n\nEnter your choice to search(1-3):");
                    scanf("%d", &ch);
 
                    switch(ch)
                    {
                        case 1: printf("Enter Student ID for Search : ");
                                scanf("%d",&id);
				search_stud(id);
                                break;
                        //case 2: search_teacher();
                                //break;
                        case 3: exit(0);

                        default: printf("Wrong Choice!!");
                    }
                    break;

            case 6: exit(0);
                    
	    default: printf("Wrong Choice!!");
        }
    }
    return 0;
}
