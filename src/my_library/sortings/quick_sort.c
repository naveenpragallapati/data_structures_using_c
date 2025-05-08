#include <stdio.h>
int recursion_count = 0; // Global variable to count the number of recursive calls
// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition function using first element as pivot
int partition(int A[], int lb, int ub) {
    int pivot = A[lb];
    int i = lb;
    int j = ub;

    while (i < j) {        
        while (A[i] <= pivot && i < j)         // Move i to the right while A[i] <= pivot
            i++;        
        while (A[j] > pivot)                   // Move j to the left while A[j] > pivot
            j--;        
        if (i < j)                             // Swap A[i] and A[j] if i < j
            swap(&A[i], &A[j]);
    }  
    swap(&A[lb], &A[j]);                       // Swap pivot with A[j]
    return j;                                   // Return the partition index
}

// Recursive Quick Sort function
void quickSort(int A[], int low, int high) {
    recursion_count++; // Increment the recursion count
    printf("\n %d quickSort(%d, %d)", recursion_count, low, high);
    if (low < high) {
        int p = partition(A, low, high);
        quickSort(A, low, p - 1);         // Sort left subarray
        quickSort(A, p + 1, high);     // Sort right subarray
    }   
}

// Utility function to print the array
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}


// Main function
int main() {
    int A[] = {50, 70, 60, 90, 40, 80, 10, 20, 30};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Original array:\n");
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printf("\n\nSorted array:\n");
    printArray(A, n);
    printf("\nTotal number of recursive calls: %d\n", recursion_count);
    printf("\n");
    return 0;
}
// gcc -o quick_sort quick_sort.c
// ./quick_sort