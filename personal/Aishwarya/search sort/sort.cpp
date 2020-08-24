#include <iostream>
using namespace std;
#define MAX 60

void bubble_sort(int [], int);
void quick_sort(int [], int, int);
int part(int [], int, int);
bool binary_search(int [], int, int);

void bubble_sort(int a[], int n) {
    int i,j,temp;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n-i; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int part(int a[], int l, int u) {
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

void quick_sort(int a[], int l, int u) {
    int i, n;
    if(l < u) {
        i = part(a,l,u);
        quick_sort(a,l,i-1);
        quick_sort(a,i+1,u);
    }
    
}

bool binary_search(int a[], int key, int n) {
    int start,end,mid;
    start = 0;
    end = n - 1;
    mid = (start + end) / 2;
    while (a[mid] != key && start <= end) {
        if (key > a[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    if (start <= end) {
        return true;
    }
    return false;
}

int 
main() {
    int a[MAX], n, i, key, result, ch;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for (i = 0; i < n; i++) {
        cin>>a[i];
    }
    while(1) {
        cout<<"\n1. Bubble Sort\n2. Quick Sort\n3. Binary Search\n4. Exit\nEnter Your Choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
                bubble_sort(a,n);
                cout<<"Sorted Array is: ";
                for (i = 0; i < n; i++) {
                    cout<<a[i]<<"\t";
                }
                cout<<"\n\n";
                break;

        case 2:
                quick_sort(a,0,n-1);
                cout<<"Sorted Array is: ";
                for (i = 0; i < n; i++) {
                    cout<<a[i]<<"\t";
                }
                cout<<"\n\n";
                break;

        case 3:
                cout<<"Enter element to be searched: ";
                cin>>key;
                bubble_sort(a,n);
                result = binary_search(a,key,n);
                if (result == false) {
                    cout<<"\nElement not found....\n";
                } else {
                    cout<<"\nElement is found....\n";
                }
                
                break;
        
        case 4: exit(0);
        
        default:
                cout<<"You Entered Wrong Choice!!!!! Try Again";
                break;
        }
    }
    return 0;
}