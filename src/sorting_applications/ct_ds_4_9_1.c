#include <stdio.h>

void printArray(int arr[], int n) {
    // Print the array in the required format
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);        
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        
        // Print the array state after the third iteration
        if (i == 3) {
            printArray(arr, n);
        }
    }
}


int main() {
    int arr[30], i, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
	    scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}