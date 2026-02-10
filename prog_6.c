#include <stdio.h>
#define MAX_SIZE 10

// Function to swap two elements
void swap(int *a, int *b){
    
    int temp = *a;
    *a = *b;
    *b = temp;

}

// Max-Heapify: Ensures parent is greater than children
void maxHeapify(int arr[], int n, int i){

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }

}

// Min-Heapify: Ensures parent is smaller than children
void minHeapify(int arr[], int n, int i){

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }

    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }

}

void printArray(int arr[], int n){

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

}

int main(){

    int data[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(data) / sizeof(data[0]);
    
    // Build Max Heap
    int maxHeap[MAX_SIZE];
    for(int i=0; i<n; i++){
        maxHeap[i] = data[i];
    }
    
    for(int i = n / 2 - 1; i >= 0; i--){
        maxHeapify(maxHeap, n, i);
    }
    
    printf("Max Heap: ");
    printArray(maxHeap, n);

    // Build Min Heap
    int minHeap[MAX_SIZE];
    for(int i=0; i<n; i++){
        minHeap[i] = data[i];
    }

    for(int i = n / 2 - 1; i >= 0; i--){
        minHeapify(minHeap, n, i);
    }

    printf("Min Heap: ");
    printArray(minHeap, n);

    return 0;

}