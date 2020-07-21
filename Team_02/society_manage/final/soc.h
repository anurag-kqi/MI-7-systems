#define SOCIETY_DATAFILE "society.txt"
#define MAINTENANCE_DATAFILE "maintenance.txt"
#define VISITOR_DATAFILE "visitor.txt"
#define COMPLAINT_DATAFILE "complaint.txt"

//structure for Society Data
struct socData{
    int index;
    char owner_name[30];
    int flat_num;
    int owner_contact;
};
struct society{
    struct socData sd;
    struct society *next;
    struct society *prev;
 };

//structure for maintenance data
struct maintData{
    int index1;
    int flat_num1;
    int water_bill;
    int electricity_bill;
};
struct maintenance{
    struct maintData md;
    struct maintenance *next1;
    struct maintenance *prev1;
};

//structure for visitor data
struct visData{
    int index2;
    char visitor_name[30];
    int vehicle_num;
    int visitor_contact;
    int TimeIn;
    int TimeOut;
};
struct visitor{
    struct visData vd;
    struct visitor *next2;
    struct visitor *prev2;
 };

//structure for complaints Data
 struct comData {
    int index3;
    int flat_num3;
    char complaints_name[50];
    char suggestions_name[50];
 };
 struct complaint {
    struct comData cd;
    struct complaint *next3;
    struct complaint *prev3;
 };
