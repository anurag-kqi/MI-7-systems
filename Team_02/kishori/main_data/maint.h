#define MAINTENANCE_DATAFILE "maintenance.txt"

struct maintData
{
   int index;
   int flat_num1;
   int water_bill;
   int electricity_bill;
};

struct maintenance
{
     struct maintData sd;
     struct maintenance *next;
     struct maintenance *prev;
 };
