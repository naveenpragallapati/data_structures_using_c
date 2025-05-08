#include <stdio.h>

void display(int arr[15], int n) {
	for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int arr[15], int low, int mid, int high) {
	int n1 = mid - low + 1;
    int n2 = high - mid;
    
    // Create temporary arrays
    int left[n1], right[n2];
    
    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[mid + 1 + i];
    }
    
    // Merge the temporary arrays back into arr[]
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    
    // Copy the remaining elements of left[], if any
    while (i < n1) {
        arr[k++] = left[i++];
    }
    
    // Copy the remaining elements of right[], if any
    while (j < n2) {
        arr[k++] = right[j++];
    }
}
void splitAndMerge(int arr[15], int low, int high) {
	if (low < high) {
        int mid = low + (high - low) / 2;
        
        // Recursively split and merge
        splitAndMerge(arr, low, mid);
        splitAndMerge(arr, mid + 1, high);
        
        // Merge the two sorted halves
        merge(arr, low, mid, high);
    }
}

void main() {
	int arr[15], i, n;
	printf("Enter array size : ");
	scanf("%d", &n);
	printf("Enter %d elements : ", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Before sorting the elements are : ");
	display(arr, n);
	splitAndMerge(arr, 0, n - 1);
	printf("After sorting the elements are : ");
	display(arr, n);
}

// description: This program implements the merge sort algorithm using recursion. It defines functions to display the array, merge two halves, and recursively split and merge the array. The main function takes user input for the array size and elements, sorts the array using merge sort, and displays the sorted array.