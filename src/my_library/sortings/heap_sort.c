#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements in the array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to heapify a subtree rooted at index `i`
// `n` is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr, i, largest); // Swap root with the largest
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Function to build a max heap from the array
void buildHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    buildHeap(arr, n); // Build max heap

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root (largest) to the end
        swap(arr, 0, i);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}