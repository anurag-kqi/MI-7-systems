
/* C++ program to read and print employee information using multiple inheritance.*/

#include <iostream>
#include <stdio.h>
using namespace std;

class basicInfo
{
    protected:  
        char    name[30];
        int     empId;
        char    gender;
    public:
        void getBasicInfo(void)
        {
            cout << "Enter Name: "; 
            cin.getline(name,30);
            cout << "Enter Emp. Id: ";
            cin  >> empId;
            cout << "Enter Gender: ";
            cin  >> gender;
        }
};
 
class deptInfo
{
    protected:  
        char    deptName[30];
        char    assignedWork[30];
    public:
        void getDeptInfo(void)
        {
            cout << "Enter Department Name: "; 

            cin.getline(deptName,30);
            cout << "Enter assigned work: ";
        
            cin.getline(assignedWork,30);
            
        }
};
 
class employee:private basicInfo, private deptInfo
{
    public:
        void getEmployeeInfo(void){
            cout << "Enter employee's basic info: ";
            getBasicInfo();     
            cout << "Enter employee's department info: ";
             getDeptInfo();      
        }
        void printEmployeeInfo(void)
        {
            cout << "Employee's Information is: "  ;
            cout << "Basic Information...:"  ;
            cout << "Name: "      << name  ;      
            cout << "Employee ID: " << empId ;        
            cout << "Gender: "        << gender ;
             
            cout << "Department Information...:" ;
            cout << "Department Name: "           << deptName ; 
            cout << "Assigned Work: "             << assignedWork; 
            
        }
};
 
int main()
{
    employee emp;
     
    emp.getEmployeeInfo();
    emp.printEmployeeInfo();
     
    return 0;
}




    


    




 


