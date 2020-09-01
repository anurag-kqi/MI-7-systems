#include <iostream> 
using namespace std;

void MaxHeapify(int heap[], int i, int n) {
	int j, temp;
	temp = heap[i];
	j = 2*i;
 
 	while (j <= n) {
		if (j < n && heap[j+1] > heap[j])
		j = j+1;
		if (temp > heap[j])
			break;

		else if (temp <= heap[j]) {
			heap[j/2] = heap[j];
			j = 2*j;
		}
	}
	heap[j/2] = temp;
	return;
}
void HeapSort(int heap[], int n) {
	int i, temp;
	for (i = n; i >= 2; i--) {
		temp = heap[i];
		heap[i] = heap[1];
		heap[1] = temp;
		MaxHeapify(heap, 1, i - 1);
	}
}
void create(int heap[], int n) {
	int i;
	for(i = n/2; i >= 1; i--)
		MaxHeapify(heap, i, n);
}
int 
main() {
	int n, i;
	cout << "\nEnter the number of data element to be sorted: ";
	cin >> n;
	n++;
	int heap[n];
	for(i = 1; i < n; i++) {
		cout << "Enter element " << i << ": ";
		cin >> heap[i];
	}

	cout << endl << "You entered: " << endl;
	for(i = 1; i < n; i++) {
		cout << "Element " << i << ": ";
		cout << heap[i] << endl;
	}
	create(heap, n-1);
	HeapSort(heap, n-1);

	cout<<"\nSorted Data: " << endl;
 
	for (i = 1; i < n; i++)
		cout << heap[i] << " ";
	cout << endl;
	return 0;
}