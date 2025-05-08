#include<stdio.h>

void main() {
    int a[20], i, n, j, small, index;

    printf("Enter value of n : ");
    scanf("%d", &n);

    // Read the array elements
    for (i = 0; i < n; i++) {
        printf("Enter element for a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    // Display elements before sorting
    printf("Before sorting the elements in the array are\n");
    for (i = 0; i < n; i++) {
        printf("Value of a[%d] = %d\n", i, a[i]);
    }

    // Selection Sort using the smallest element method
    for (i = 0; i < n - 1; i++) {
        small = a[i];
        index = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < small) {  // Find the smallest element in the unsorted part
                small = a[j];
                index = j;
            }
        }
        // Swap the found smallest element with the current element at i
        a[index] = a[i];
        a[i] = small;
    }

    // Display elements after sorting
    printf("After sorting the elements in the array are\n");
    for (i = 0; i < n; i++) {
        printf("Value of a[%d] = %d\n", i, a[i]);
    }
}
