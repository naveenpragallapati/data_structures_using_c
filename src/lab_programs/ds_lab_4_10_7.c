#include <stdio.h>

void display(int arr[15], int n) {
	for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int partition(int arr[15], int lb, int ub) {
	int pivot = arr[lb];  // Select the first element as pivot
    int start = lb;
    int end = ub;
    
    while (start < end) {
        // Move the start index forward while it's less than or equal to pivot
        while (arr[start] <= pivot && start <= ub) {
            start++;
        }
        
        // Move the end index backward while it's greater than pivot
        while (arr[end] > pivot && end >= lb) {
            end--;
        }
        
        // Swap if valid start and end indices are found
        if (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    
    // Swap the pivot with the end element to place it in the correct position
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    
    return end;
}
void quickSort(int arr[15], int low, int high) {
	 if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);
        
        // Recursively sort the two subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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
	quickSort(arr, 0, n - 1);
	printf("After sorting the elements are : ");
	display(arr, n);
}

// description: This program implements the Quick Sort algorithm to sort an array of integers. It includes functions for partitioning the array and recursively sorting the subarrays. The main function handles user input and displays the sorted array.