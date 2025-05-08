#include <stdio.h>

int partition(int arr[15], int lb, int ub);

void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)  // Corrected loop condition
        printf("%d ", arr[i]);
    printf("\n");
}

void quickSort(int arr[], int low, int high) {
    int j;
    if (low < high) {  // Condition to check if more than one element exists
        j = partition(arr, low, high);
        quickSort(arr, low, j - 1);  // First partition call
        quickSort(arr, j + 1, high);  // Second partition call
    }
}

int partition(int arr[], int lb, int ub) {
    int pivot, down = lb, up = ub, temp;
    pivot = arr[lb];  // Assign the pivot element as the first element
    while (down < up) {
        // Move down until we find an element greater than or equal to pivot
        while (arr[down] <= pivot && down <= ub) {
            down++;
        }
        // Move up until we find an element less than or equal to pivot
        while (arr[up] > pivot && up >= lb) {
            up--;
        }
        // Swap the elements at down and up if they are in the wrong order
        if (down < up) {
            temp = arr[up];
            arr[up] = arr[down];
            arr[down] = temp;
        }
    }
    // Swap the pivot element with the element at 'up' to place it in the correct position
    arr[lb] = arr[up];
    arr[up] = pivot;
    return up;
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