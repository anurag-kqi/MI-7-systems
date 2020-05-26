#include<iostream>
#include<iomanip>
using namespace std;
struct data
{   
    string name;
    int Salary;
    int age;
};
void input(struct data *I,int i){
        cout<< "-> insert name of "<<i<<":";
        getline(cin,I->name);
        cout<< "-> insert Age of "<<i<<":";
        cin>>I->age;
        cout<< "-> insert Salary of "<<i<<":";
        cin>>I->Salary;
        cout<<endl;

}

int main(){
    cout<< left;
    cout<< setw(30) << "        MI-Batch-2020        "<<"\n";
        for(int i = 0; i < 29 ;i++){
            if(i==0||i==12||i==18||i==28)
                cout<<"+";
            cout<<"-";
        }
        cout<<endl;/* from line 30 - 55  it just creates a initial table*/
        cout<<setw(1)<<"|"<<setw(12)<< "<Name>" << setw(1)<< "|" << setw(6) << "<Age>" <<  setw(1) << "|" <<setw(10) << 
            "<Salary>" <<  setw(1) << "|" <<"\n";
        for(int i = 0; i < 29 ;i++){
            if(i==0||i==12||i==18||i==28)
                cout<<"+";
            cout<<"-";
        }
        cout<<endl;
        cout<<setw(1)<<"|"<<setw(12)<< "Siddhant" << setw(1) << "|" <<setw(6) << "22" << setw(1) << "|" << setw(10) << 
            "503200.00" <<  setw(1) << "|" <<"\n"<<
        setw(1)<<"|"<<setw(12)<< "Raju" << setw(1) << "|" << setw(6) << "-" <<  setw(1) << "|" << setw(10) << 
            "502400.00" <<  setw(1) << "|" <<"\n"<<
        setw(1)<<"|"<<setw(12)<< "Rani" <<  setw(1) << "|" << setw(6) << "25" <<  setw(1) << "|" << setw(10) << 
            "50000.00" <<  setw(1) << "|" <<"\n"<<
        setw(1)<<"|"<<setw(12)<< "Alice" <<  setw(1) << "|" << setw(6) << "24" << setw(1) << "|" << setw(10) << 
            "500120000" <<  setw(1) << "|" << "\n"<<
        setw(1)<<"|"<<setw(12)<< "Bob" << setw(1) << "|" << setw(6) << "22" <<  setw(1) << "|" <<setw(10) << 
            "500000.00" <<  setw(1) << "|"  <<"\n"<<
        setw(1)<<"|"<<setw(12)<< "Sid" <<  setw(1) << "|" <<setw(6) << "24" << setw(1) << "|" << setw(10) << 
            "500230.00" <<  setw(1) << "|" <<"\n";
        for(int i = 0; i < 29 ;i++){
            if(i==0||i==12||i==18||i==28)
                cout<<"+";
            cout<<"-";
        }
        cout<<endl;
        // from here structure is initiated and all the entries will be asked to user
        struct data *inserts[10];
        for(int i = 0; i<10 ; i++){
            input(inserts[i],i); //this asks user to give input to array of structures;
        }
            // after taking desired number of input code from line 62-85 was intended to print table again
        for(int i = 0; i < 29 ; i++){
            if(i==0||i==12||i==18||i==28)
                cout<<"+";
            cout<<"-";
        }
        cout<<endl;
        cout<<setw(1)<<"|"<<setw(12)<< "<Name>" << setw(1)<< "|" << setw(6) << "<Age>" <<  setw(1) << "|" <<setw(10) << 
            "<Salary>" <<  setw(1) << "|" <<"\n";
        for(int i = 0; i < 29 ;i++){
            if(i==0||i==12||i==18||i==28)
                cout<<"+";
            cout<<"-";
        }
        cout<<endl;
        for(int i = 0; i<10 ;i++){
            cout<<setw(1)<<"|"<<setw(12)<< inserts[i]->name << setw(1) << "|" <<setw(6) << inserts[i]->age << setw(1) << "|" << setw(10) << 
            inserts[i]->Salary <<  setw(1) << "|" <<"\n";
        }
        for(int i = 0; i < 29 ;i++){
            if(i==0||i==12||i==18||i==28)
                cout<<"+";
            cout<<"-";
        }

 return 0;
}