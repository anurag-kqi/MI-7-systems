#include <iostream>
using namespace std;
#define MAX 60

void BUBBLESORT(int [],int);
void QUICKSORT(int [], int, int);
int DIV(int [], int, int);
bool BINARYSEARCH(int [], int, int);

void BUBBLESORT(int a[],int n) {
    int i, j,temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
           if(a[j]>a[j+1]){
             temp= a[j],a[j]=a[j+1],a[j+1]=temp;
           }
        }
    }
 }

int DIV(int a[], int l, int u) {
    int i,j,p,temp;
    p = a[l];
    i = l;
    j = u + 1;
    do {
        do {
             i++;
        } while(a[i] < p && i <= u);
        do {
            j--;
        } while(p < a[j]);
        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
     } while (i < j);
     a[l] = a[j];
     a[j] = p;
     return(j);
 }

void QUICKSORT(int a[], int l, int u) {
    int i, n;
    if(l < u) {
        i = DIV(a,l,u);
        QUICKSORT(a,l,i-1);
        QUICKSORT(a,i+1,u);
     }
 }

bool BINARYSEARCH(int a[], int key, int n) {
     int s,e,mid;
     s = 0;
     e = n - 1;
     mid = (s + e) / 2;
     while (a[mid] != key && s <= e) {
         if (key > a[mid]) {
             s = mid + 1;
         } else {
             e = mid - 1;
         }
         mid = (s + e) / 2;
     }
     if (s <= e) {
         return true;
     }
     return false;
 }

int
main(){
     int n,ch,i,a[MAX], key, result;
     cout<<"Enter Size of Elements"<<endl;
     cin>>n;
     cout<<"Enter Number of Elemets"<<endl;
     for(i=0; i<n; i++)
     cin>>a[i];

    while(1){
            cout<<"\n1.BUBBLE SORT\n2.QUICK SORT\n3.BINARYSEARCH"<<endl;
            cout<<"CHOOSE YOUR OPTION"<<endl;
            cin>>ch;
            switch(ch)
            {
            case 1 : BUBBLESORT(a,n);
                     cout<<"BUBBLE SORTED LIST IS:"<<endl;
                     for(i=0; i<n; i++){
                     cout<<a[i]<<"\t";
                     }
                     cout<<"\n\n";
                     break;

            case 2 : QUICKSORT(a,0,n-1);
                     cout<<"QUICK SORTED LIST IS is"<<endl;
                     for (i = 0; i < n; i++) {
                     cout<<a[i]<<"\t";
                      }
                     cout<<"\n\n";
                     break;
             case 3 :cout<<"ENTER ELEMET TO SEARCH: ";
                     cin>>key;
                     BUBBLESORT(a,n);
                     result = BINARYSEARCH(a,key,n);
                     if (result == false) {
                     cout<<"\nElement not found....\n";
                     } else {
                     cout<<"\nElement is found....\n";
                     }
                     break;
             case 4 :exit(0);
                     break;
             default:cout<<"YOU ENTERED WRONG CHOICE"<<endl;
                     break;
                 }
             }
    return 0;
 }
