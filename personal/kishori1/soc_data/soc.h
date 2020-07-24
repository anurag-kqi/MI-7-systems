#define SOCIETY_DATAFILE "society.txt"

struct socData
{
   int index;
   char owner_name[30];
   int flat_num;
   int owner_contact;
};

struct society
{
     struct socData sd;
     struct society *next;
     struct society *prev;
 };
