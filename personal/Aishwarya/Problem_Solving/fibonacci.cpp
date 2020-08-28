#include <iostream>
using namespace std;


void nterm (int);
void number (int);

void nterm (int n) {
    int  t1 = 0, t2 = 1, nextTerm = 0;
    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i)
    {
        if(i == 1)
        {
            cout << " " << t1;
            continue;
        }
        if(i == 2)
        {
            cout << " " << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout << nextTerm << " ";
    }
}

void number (int n) {
        
    int  t1 = 0, t2 = 1, nextTerm = 0;
    cout << "Fibonacci Series: " << t1 << " " << t2 << " ";
    
    nextTerm = t1 + t2;

    while(nextTerm <= n) {
        cout << nextTerm << " ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
}



int 
main () {
    int ch,n;
    while (1) {
        cout<<"\n\nMENU\n1. Upto N terms\n2. Upto certain number\n3. Exit\nEnter your choice: ";
        cin>>ch;
        switch (ch) {
        case 1:
                cout << "Enter the number of terms: ";
                cin >> n;
                nterm(n);
                break;
        
        case 2:
                cout << "Enter number that upto you want to print fibonacci series: ";
                cin >> n;
                number(n);
                break;

        case 3:
                exit(0);
                break;

        default:
                cout<<"You entered wrong choice....\n";
                break;
        }
    }
    
}