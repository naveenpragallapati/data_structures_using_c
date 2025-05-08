#include<stdio.h>

void main() {
    int a[20], i, n, j, large, index;
    printf("Enter value of n : ");
    scanf("%d", &n);

    // Input the elements into the array
    for (i = 0; i < n; i++) {
        printf("Enter element for a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    // Display elements before sorting
    printf("Before sorting the elements in the array are\n");
    for (i = 0; i < n; i++) {
        printf("Value of a[%d] = %d\n", i, a[i]);
    }

    // Selection Sort logic
    for (i = 0; i < n - 1; i++) {
        large = a[i];
        index = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < large) {  // Find the smallest element in the unsorted part
                large = a[j];
                index = j;
            }
        }
        // Swap the found smallest element with the first element of the unsorted part
        a[index] = a[i];
        a[i] = large;
    }

    // Display elements after sorting
    printf("After sorting the elements in the array are\n");
    for (i = 0; i < n; i++) {
        printf("Value of a[%d] = %d\n", i, a[i]);
    }
}
