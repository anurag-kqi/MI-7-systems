/*COMPLEXITY OF BUBBLE SORT, QUICK SORT AND BINARY SEARCH ALGORITHM*/

COMPLEXITY: 
1. Time complexity:Time complexity is commonly estimated by counting the number of elementary operations performed by the algorithm. 

A. BUBBLE SORT: The Bubble sort algorithm compares each pair of elements in an array and swaps them if they are out of order until the entire array is sorted. 
   For each element in the list, the algorithm compares every pair of elements.

   1. Time complexity: To calculate the complexity of the bubble sort algorithm, it is useful to determine how many comparisons each loop performs. 
   For each element in the array, bubble sort does n−1 comparisons.

   When i=1 no comparisons are made by the program. When i=2 one comparison is made by the program. When i=3 two comparisons are made, and so on. 
   Thus, we can conclude that when i=n n−1 comparisons are made. Hence, in an array of length n it does 1+2+3+4+⋯+(n−2)+(n−1).
   (n−1)(n−1+1)​ / 2 = 2n(n−1)​ / 2 = n*n

   Time complexity is O(n2).
   Space complexity is O(1).

B. QUICK SORT: The quicksort technique is done by separating the list into two parts. Initially, a pivot element is chosen by partitioning algorithm. 
   The left part of the pivot holds the smaller values than the pivot, and right part holds the larger value. 
   After partitioning, each separate lists are partitioned using the same procedure.

   1. Time complexity: the algorithm takes O(n log n) comparisons to sort n items. 

C. BINARY SEARCH: Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half. 
   Repeatedly check until the value is found or the interval is empty.

   1. Time complexity: O(Log n)
