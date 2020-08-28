Time Complexity

- Time complexity of algorithm is the time required to run the program.
- Time complexity depends upon the amount of input.
- Time complexity depends on number of comparisons.

1. Time complexity of Bubble Sort algorithm:
- First we have to know how many comparisons are their for each loop.
- Their are two loops and each has n-1 comparisons.
- Best case :
    - when array is already sorted then best case time complexity occurs.
    - time complexity for best case : O(n)
    - Theie is no any swap occurs and only one iteration.
- Worst case :
    - In worst case array is already sorted but it is in decending order.
    - The iteration have to look till n element, at next iteration have to look till n-1 iteration and so on.
    - iteration till one comparions occur.
    - Big O = n + (n-1) + (n-2)... + 1
            = (n * (n + 1)) / 2
            = O(n^2) 
2. Time complexity for Quick sort algorithm : 
- Worst case : 
    - Worst case occurs when at each recursion we get next pivot to split arrays is at end of the array.
    - Time complexity for worst case : O(n^2)
- Best case : 
    - Best case occurs if the array has an odd number of elements and the pivot is in the middle after partitioning, and each partition has (n−1)/2.
    - Time complexity for Quick sort : O(nlogn)

3. Time complexity for Binary Search :
- In each iteration or in each recursive call, the search gets reduced to half of the array.
- Worst case :
    - Time complexity for binary search : O(log2n)
- Best case : 
    - This case occurs when their is only one comparison.
    - Time complexity for binary search : O(1)