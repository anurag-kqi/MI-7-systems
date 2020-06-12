#include<stdio.h>
struct Node
{

	struct Node *prev;
	int BID;
	int OID;
	char bName[15];
	char oName[16];
	char bAdd[31];
	char bType[13];
	char contact[10];
	char email[21];
	struct Node *next;
};

void SortedLinks(struct Node **H, struct Node x);

int hash_at_int(int key,int size);

void Insert_Row(struct Node *H[], struct Node key , int size);

struct Node *Print_Hash(struct Node *p);

struct Node *Print_DB(struct Node p);

void delete_BID(struct Node **H, struct Node key);



