#include <stdio.h>

// Function to implement Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int n;
    // Input: Number of elements in the array
    scanf("%d", &n);
    
    int arr[n], i;
    // Input: Elements of the array
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Call the selectionSort function to sort the array
    selectionSort(arr, n);
    
    // Output: Sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
