// vovels, digits and consonents in word

#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;
// logic
// find vovels in word
// display number of vovels and vovels in word
// take input as string
// compair each character is vovel or not
// if vovel, print it and make count = 1

int main () {
    char ch[100], sapces = ' ';
    int count = 0, count1 = 0, count2 = 0, count3 = 0;
    cout << "Enter single word : ";
    cin.get(ch,100);
    // ch = "Prajwal Yadav"
    int size = strlen(ch);
    // cout << "size = " << size;
    for(int i = 0; ch[i]!='\0'; i++)
    {
        if(ch[i]=='a' || ch[i]=='e' || ch[i]=='i' ||
           ch[i]=='o' || ch[i]=='u' || ch[i]=='A' ||
           ch[i]=='E' || ch[i]=='I' || ch[i]=='O' ||
           ch[i]=='U')
        {            
            count = count + 1;            
        }
    
        if (isdigit(ch[i])) {
               count1 = count1 + 1;
        }
        
        if (ch[i]== ' ') {
            count3 = count3 + 1;
        }

    }
    int con = size - (count + count1 + count3);
    cout << "\nThere are " << count << " vovels in word." << endl;
    cout << "\nThere are " << count1 << " digits in word." << endl;
    cout << "\nThere are " << count3 << " number of spaces in word." << endl;
    cout << "\nThere are " << con << " consonents in word." << endl;
    return 0;
}