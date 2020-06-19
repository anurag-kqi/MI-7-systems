#include<stdio.h>
#include"database.h"
void Insert_Row(struct Node *H[], struct Node key , int size)
{	
	int c;
	int Index= hash_at_int(key.BID,size);
	SortedLinks(&H[Index],key);
}
