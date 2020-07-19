#define SOCIETY_DATAFILE "visitor.txt"

struct visData
{
   int index;
   char visitor_name[30];
   int vehicle_num;
   int new_vehicle_num;
   int visitor_contact;
   int TimeIn;
   int TimeOut;
};

struct visitor
{
     struct visData vd;
     struct visitor *next;
     struct visitor *prev;
 };
