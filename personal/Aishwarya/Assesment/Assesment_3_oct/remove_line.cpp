#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>
using namespace std;

int 
main() {
    FILE *fp1, *fp2;
    char ch;
    int delete_line, temp = 1;

    fp1 = fopen("remove.txt", "r");
    ch = getc(fp1);

    while(ch != EOF) {
        cout << ch;
        ch = getc(fp1);
    }

    rewind(fp1);

    cout << "\n Enter line number of the line to be deleted: ";
    cin >> delete_line;
    fp2 = fopen("replica.c", "w");
    ch = getc(fp1);

    while (ch != EOF) {
        ch = getc(fp1);
        if (ch == '\n')
            temp++;
            if (temp != delete_line) {
                putc(ch, fp2);
            }
    }

    fclose(fp1);
    fclose(fp2);

    remove("remove.txt");
    rename("replica.c", "remove.txt");

    cout << "\n The contents of file after being modified are as follows:\n";
    fp1 = fopen("remove.txt", "r");
    ch = getc(fp1);

    while (ch != EOF) {
        cout << ch;
        ch = getc(fp1);
    }
    
    fclose(fp1);
    return 0;
}