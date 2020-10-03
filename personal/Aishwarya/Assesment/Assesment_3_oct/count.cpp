#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>
using namespace std;

int 
main() {
    int noc = 0, now = 0;
    FILE *fp;
    char ch;

    fp = fopen("count.txt","r");
    if(fp == NULL) {
          cout << "\n Invalid File Name. \n No such File or Directory ";
          exit(0);
     }
     
    ch = fgetc(fp);
    
    while(ch != EOF) {
        if(ch != ' ' && ch != '\n') { 
            noc++;
        } else {
            now++;
        }

        ch = fgetc(fp);
    }
    fclose(fp);

    cout << "\n Total No. of Characters  : " << noc;
    cout << "\n Total No. of Words       : " << now << endl;

    return 0;
}