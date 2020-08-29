// vovels in word

#include <iostream>
using namespace std;
// logic
// find vovels in word
// display number of vovels and vovels in word
// take input as string
// compair each character is vovel or not
// if vovel, print it and make count = 1

int main () {
    string ch;
    int count = 0;
    cout << "Enter single word : ";
    cin >> ch;
    for(int i = 0; ch[i]!='\0'; ++i)
    {
        if(ch[i]=='a' || ch[i]=='e' || ch[i]=='i' ||
           ch[i]=='o' || ch[i]=='u' || ch[i]=='A' ||
           ch[i]=='E' || ch[i]=='I' || ch[i]=='O' ||
           ch[i]=='U')
        {
            cout << ch[i] << " is vovel" << endl;
            count = count + 1;
            count;
        }
    }
    cout << "There are " << count << " vovels in word.. " << endl;
    return 0;
}