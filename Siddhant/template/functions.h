#include <stdio.h>

typedef struct nodeElement {
  int s;
  char name[20]; 
  char address[20];
} nodeElement;

void write_in(nodeElement B);

void read_in(nodeElement Businesses[],int fd1);

void delete(int del_id, int size, nodeElement Businesses[]); 
