// sort array in lexicographical order
#include <iostream>
using namespace std;

void string_sort(string ch[], int n)
{
	int i, j;
    string temp;
	for (i = 0; i <= n - 1; i++) {
        for (j = i + 1; j <= n; j++) {
            if (ch[i] > ch[j]) {
                temp = ch[i];
                ch[i] = ch[j];
                ch[j] = temp;
            }
        }
    }    
}

int main () {
    int n, i;
    string ch [100];
    cout << "Enter number of words : ";
    cin >> n;
    cout << "Enter " << n << " words : ";
    for (i = 0; i <= n; ++i) {
        getline(cin, ch[i]);
    }
    string_sort(ch, n);    
    
    for(i = 0; i <= n; i++) {
        cout << ch[i] << endl;
    }
    return 0;
}