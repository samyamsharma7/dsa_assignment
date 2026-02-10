# DOCUMENTATION (prog_8.c)

## Logic

The program generates a list of `N` random integers in the range `[1, 1000]`, where `N` is provided by the user at a runtime. The user is then asked to choose one sorting algorithm among Bubble Sort, Selection Sort, Insertion Sort, and Merge Sort.

Each algorithm works as follows:
- **Bubble Sort:** Repeatedly compares adjacent elements and swaps them if they are in the wrong order.
- **Selection Sort:** Selects the minimum element from the unsorted part and places it at its correct position.
- **Insertion Sort:** Builds a sorted portion by inserting each element from the unsorted portion into its correct position.
- **Merge Sort:** Recursively divides the array into halves, sorts them, and merges the sorted halves back together.

Based on the selected algorithm, the array is sorted while counting the total number of comparisons and swaps performed. The array is displayed both before and after sorting. For Merge Sort, only comparisons are counted, as swapping is not directly applicable.

Global variables are used to keep track of comparisons and swaps during execution.

---

## Data Structure Implementation

An integer array is used to store the randomly generated numbers.

### Array Representation

- One-dimensional integer array to store `N` elements
- Size is decided at runtime using variable-length arrays

```c
    int a[n];
```

---

## Functions Used

1. `swap(int *x, int *y):`
    Swaps two integer values and increments the swap counter.

2. `bubbleSort(int a[], int n):`
    Sorts the array using Bubble Sort by repeatedly comparing adjacent elements and swapping them if required.

3. `selectionSort(int a[], int n):`
    Sorts the array by repeatedly selecting the minimum element from the unsorted portion and placing it in the correct position.

4. `insertionSort(int a[], int n):`
    Sorts the array by inserting each element into its correct position in the already sorted part of the array.

5. `merge(int a[], int l, int m, int r):`
    Merges two sorted subarrays into a single sorted array while counting comparisons.

6. `mergeSort(int a[], int l, int r):`
    Recursively divides the array and sorts it using the Merge Sort technique.

7. `printArray(int a[], int n):`
    Prints all elements of the array.

---

## main() Function

The `main()` function performs the following steps:
1. Reads the number of elements `N` from the user.
2. Generates `N` random integers between 1 and 1000.
3. Displays the array before sorting.
4. Prompts the user to select a sorting algorithm.
5. Sorts the array using the selected algorithm.
6. Displays the sorted array.
7. Prints the total number of comparisons and swaps.

```c
    switch(choice){
        case 1: bubbleSort(a, n); break;
        case 2: selectionSort(a, n); break;
        case 3: insertionSort(a, n); break;
        case 4: mergeSort(a, 0, n-1); break;
    }
```

---

## Sample Output

```c
    Enter number of elements: 7

    Array before sorting:
    42 468 335 501 170 725 479

    Choose sorting algorithm:
    1. Bubble Sort
    2. Selection Sort
    3. Insertion Sort
    4. Merge Sort
    Enter choice: 3

    Array after sorting:
    42 170 335 468 479 501 725

    Total comparisons: 12
    Total swaps: 6
```