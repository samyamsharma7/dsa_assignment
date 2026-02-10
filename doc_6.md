# DOCUMENTATION (prog_6.c)

## Logic

A heap is a complete binary tree that satisfies the heap property.

In a **Max Heap**, the value of each parent node is greater than or equal to the values of its child nodes.
In a **Min Heap**, the value of each parent node is smaller than or equal to the values of its child nodes.

The program builds both a Min Heap and a Max Heap from an unsorted array using the heapify process. Heap construction is performed by calling the heapify function starting from the last non-leaf node and moving up to the root node.

---

## Data Structure Implementation

The heap is implemented using an array.

For an element stored at index `i`:
- The left child is located at index `2*i + 1`
- The right child is located at index `2*i + 2`

This array-based representation efficiently models a complete binary tree.

---

## Functions Used

1. `swap(int *a, int *b):`
    Swaps the value of two integer variables using a temporary variable.

2. `maxHeapify(int arr[], int n, int i):`
    Mantains the Max Heap property for the subtree rooted at index `i`. If the parent node is smaller than any of its children, it is swapped with the largest child and heapify is applied recursively.

3. `minHeapify(int arr[], int n, int i):`
    Maintains the Min Heap property for the subtree rooted at index `i`. If the parent node is larger than any of its children, it is swapped with the smallest child and heapify is applied recursively.

4. `printArray(int arr[], int n):`
    Prints the elements of the array representing the heap.

---

## main() Function

The `main()` function demonstrates the construction of both Min Heap and Max Heap from an unsorted array:
1. Defines an unsorted array of integers.
2. Builds a Max Heap by applying `maxHeapify()` starting from the last non-leaf node.
3. Displays the Max Heap.
4. Builds a Min Heap using `minHeapify()` in a similar manner.
5. Displays the Min Heap.

```c
    int data[] = {12, 11, 13, 5, 6, 7};
```

After heap construction:
- The Max Heap places the largest element at the root.
- The Min Heap places the smallest element at the root.

---

## Sample Output

```c
    Max Heap: 13 11 12 5 6 7
    Min Heap: 5 6 7 11 12 13
```
