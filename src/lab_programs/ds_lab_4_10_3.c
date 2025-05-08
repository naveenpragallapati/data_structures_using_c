#include<stdio.h>
void main() {
	int a[20], i, n, j, temp, pos;
	printf("Enter value of n : ");
	scanf("%d", &n);
	// Read array elements
	for (i = 0; i < n; i++) {
		printf("Enter element for a[%d] : ", i);
		scanf("%d", &a[i]);
	}

	// Display array elements before sorting
	printf("Before sorting the elements in the array are\n");
	for (i = 0; i < n; i++) {
		printf("Value of a[%d] = %d\n", i, a[i]);
	}

	// Insertion sort logic
	for (i = 1; i < n; i++) {
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}

	// Display array elements after sorting
	printf("After sorting the elements in the array are\n");
	for (i = 0; i < n; i++) {
		printf("Value of a[%d] = %d\n", i, a[i]);
	}
}
// description: This program implements the insertion sort algorithm to sort an array of integers in ascending order. It first takes the number of elements and the elements themselves as input, then sorts them using the insertion sort technique, and finally displays the sorted array.