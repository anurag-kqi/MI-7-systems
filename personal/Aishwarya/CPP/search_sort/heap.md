Heap Sort:

    - A heap is a complete binary tree.
    - In a complete binary tree, elements are filled level by level from left to right. Thus the bottom level may not be completely filled.

Prorperies of complete binary tree:

    - If the complete binary tree has height h then the number of node N will be
        2^h+1 - 1 >= N >= 2^h.
    - Height of complete binary tree = O(log N)
    - A complete binary tree can easily be reperesented using an array.
    - Elements of the tree are stored in the array level by level, from left to right, starting from 0 and working downword.
        The position of left child of i = 2 * i
        The position of right child of i = 2 * i + 1
        The position of parent of i =  i / 2

Types Of Heaps:

1. Max Heap:
    - A max heap is a complete binary tree with the property that the value of each node at least as large as the value at its children.
    - In max heap, we can find the largest element easily. Largest element is at the root.
2. Min Heap:
    - A min heap is a complete binary tree with the property that the value of each node at least as small as the value at its children.
    - In min heap, we can find the smallest element easily. Smallest element is at the root.
