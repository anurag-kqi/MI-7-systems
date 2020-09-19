//C++ program to insert element in vector at specified position
#include<iostream>
#include<vector>
using namespace std;
#define MAX 50

int 
main() { 
    int n, key, pos, input;    
    vector <int> vec;
    cout << "Enter no. of elements: ";
    cin >> n;
    cout << "\nEnter elements: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> input; 
        vec.push_back(input);
    }

    cout << "\nVector Before Insertion" << endl;
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }   

    cout << "\nEnter element and postion to insert in vector: ";
    cin >> key >> pos;
    
    vec.insert(vec.begin() + pos, key) ;
    
    cout << "\nVector After Insertion" << endl;
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    } 
}