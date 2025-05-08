#include <stdio.h>

void display(int arr[15], int n) {
	for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void heapify(int arr[], int n, int i)  { 
	int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        // Swap arr[i] and arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }	
}	
void heapsort(int arr[], int n) {
	// Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Extract elements one by one from the heap
    for (int i = n - 1; i >= 1; i--) {
        // Swap the root (max element) with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        // Heapify the root element
        heapify(arr, i, 0);
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
	heapsort(arr,n);
	printf("After sorting the elements are : ");
	display(arr, n);
}

// description : This program implements heapsort algorithm to sort an array of integers. It first builds a max heap from the input array and then repeatedly extracts the maximum element from the heap, placing it at the end of the array. The process continues until all elements are sorted. The program also includes a function to display the array before and after sorting.