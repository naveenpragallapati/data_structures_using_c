#include<stdio.h>

void main() {
    int a[20], i, n, j, key;
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

    // Insertion Sort logic
    for (i = 1; i < n; i++) {
        key = a[i];  // The element to be inserted into the sorted part
        j = i - 1;
        
        // Move elements of a[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    // Display elements after sorting
    printf("After sorting the elements in the array are\n");
    for (i = 0; i < n; i++) {
        printf("Value of a[%d] = %d\n", i, a[i]);
    }
}
