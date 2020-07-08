/* Program to find hash operation using hash function */

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int h[TABLE_SIZE] = {NULL};

void insert() {

   	int key,index,i,hkey;
 	printf("\n Enter a value to insert into hash table\n");
 	scanf("%d", &key);
 
 	hkey = key % TABLE_SIZE; 
 
 	for (i=0; i<TABLE_SIZE; i++) {

     	   index = (hkey+i) % TABLE_SIZE;

     	if (h[index] == NULL) {
        	h[index] = key;
         	break;
     	 }
    }
        if (i == TABLE_SIZE) {

     	 printf("\n Element cannot be inserted\n");
     }
}

void search() {

 	int key,index,i,hkey;
 	printf("\nenter search element\n");
 	scanf("%d", &key);
 
 	hkey = key % TABLE_SIZE;
 
 	for(i=0; i<TABLE_SIZE; i++) {
 
 	   index = (hkey+i) % TABLE_SIZE;
 
        if(h[index] == key) {
        
     	   printf("value is found at index %d", index);
     	   break;
 	 }
    }
 	 if(i == TABLE_SIZE) {
 	   printf("\n value is not found\n");
 	 }
}

void display() {

  	int i;
        printf("\n Elements in the hash table are \n");

  	for(i=0; i< TABLE_SIZE; i++) {

  	printf("\nat index %d \t value =  %d", i, h[i]);
  }

}

void
main()
{
    	int opt,i;
    	while(1)
    	{
        	 printf("\n 1. Insert \n");
       	 printf("\n 2. Display \n");
       	 printf("\n 3. Search  \n");
       	 printf("\n 4.Exit \n");
       	 printf("\n Enter your option \n");
       	 scanf("%d", &opt);
 	       switch(opt)
 	       {
 	           case 1:
 	               insert();
 	               break;
 	           case 2:
 	               display();
 	               break;
 	           case 3:
 	               search();
 	               break;
 	           case 4:exit(0);
 	       }
 	 }
}
