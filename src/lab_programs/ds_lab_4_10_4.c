#include<stdio.h>

void main() {
	int a[20], i, n, j, small, index;
	printf("Enter value of n : ");
	scanf("%d", &n);
	// Write the code to read an array elements
	int temp;
	for (i = 0; i < n; i++) {
		printf("Enter element for a[%d] : ", i);
		scanf("%d", &a[i]);
	}	
	printf("Before sorting the elements in the array are\n");
	// Write the code to print the given array elements before sorting
	for (i = 0; i < n; i++) {
		printf("Value of a[%d] = %d\n", i, a[i]);
	}	
	// Write the code for selection sort smallest element method
	for (i = 0; i < n - 1; i++) {
		small = a[i];
		index = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < small) {
				small = a[j];
				index = j;
			}
		}
		// Swap a[i] and a[index] if needed
		if (index != i) {
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}
	printf("After sorting the elements in the array are\n");
	// Write the code to print the given array elements after sorting
	for (i = 0; i < n; i++) {
		printf("Value of a[%d] = %d\n", i, a[i]);
	}	
}
// description: This program implements selection sort using smallest element method. The program reads an array of integers, sorts it using selection sort, and prints the sorted array. The selection sort algorithm repeatedly finds the smallest element from the unsorted part of the array and swaps it with the first unsorted element.