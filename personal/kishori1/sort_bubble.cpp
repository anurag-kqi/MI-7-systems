/*Program of bubble sorting*/

#include <iostream>
using namespace std;

void swapping(int &a, int &b)
{
  /*swap the content of a and b*/
  int temp;
  temp = a;
  a = b;
  b = temp;
}
void display(int *array, int size)
{
  for(int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
void bubbleSort(int *array, int size)
{
  for(int i = 0; i < size; i++) {
    /*detect any swap is there or not*/
    int swaps = 0;
      for(int j = 0; j < size - i - 1; j++) {
        /*when the current item is bigger than next*/
        if(array[j] > array[j + 1]) {
          swapping(array[j], array[j + 1]);
          /*set swap flag*/
          swaps = 1;
        }
    }
    if(!swaps)
    /* No swap in this pass, so array is sorted*/
        break;
  }
}
int
main()
{
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;
  int arr[n];
  cout << "Enter elements:" << endl;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Array before Sorting: ";
  display(arr, n);
  bubbleSort(arr, n);
  cout << "Array after Sorting: ";
  display(arr, n);
}
