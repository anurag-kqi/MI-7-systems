//Bubble sort
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
	int i, j, temp;
	for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "\nSorted array bubble sort: \n";
    for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl << endl;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(int arr[], int l, int r, int key)
{
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}

int main()
{
    int arr[50], n, ch, key, result;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while(1) {
        cout << "\nMENU\n1. Bubble Sort\n2. Quick Sort\n3. Binary Search\n4. Exit\n\nEnter your choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1 :
                    bubbleSort(arr, n);
                    break;

            case 2 :
                    quickSort(arr, 0, n - 1);
                    cout << "\nSorted array QuickSort: \n";
                    for (int i = 0; i < n; i++)
                        cout << arr[i] << " ";
                    cout << endl << endl;
                    break;

            case 3 :
                    cout << "Enter element to search : ";
                    cin >> key;
                    result = binarySearch(arr, 0, n-1, key);
                    if (result == false) {
                        cout<<"\nElement not found....\n";
                    } else {
                        cout<<"\nElement is found....\n";
                    }
                    break;

            case 4 :
                    exit(0);

            default:
                    cout << "Wrong choice..\n";
                    break;
        }
    }
	return 0;
}
