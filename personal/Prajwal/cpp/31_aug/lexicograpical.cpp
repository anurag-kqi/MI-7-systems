
#include <iostream>
using namespace std;

void bubbleSort(string ch[], int n)
{
	int i, j;
    string temp;
	for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (ch[i] > ch[j]) {
                temp = ch[i];
                ch[i] = ch[j];
                ch[j] = temp;
            }
        }
    }
    // cout << "\nSorted chay bubble sort: \n";
    // for (i = 0; i < n; i++)
	// 	cout << ch[i] << " ";
	// cout << endl << endl;
}

int main () {
    int n, i;
    string ch [100];
    cout << "Enter number of words : ";
    cin >> n;
    cout << "Enter " << n << "words : ";
    for (i = 0; i < n; i++) {
        getline(cin, ch[i]);
    }
    bubbleSort(ch, n);

    for(i = 0; i < n; i++) {
        cout << ch[i] << endl;
    }
    return 0;
}