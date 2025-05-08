#include <stdio.h>

int recurstive_count = 0; // Global variable to count recursive calls

void merge(int arr[], int left, int mid, int right) {
    recurstive_count++; // Increment the recursive call count

    // Find sizes of two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    printf(" %d merge(%d to %d, %d to %d)\n", recurstive_count, left, mid, mid + 1, right);    

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;

    // Merge the temp arrays back into arr[]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, size);
    mergeSort(arr, 0, size - 1);
    printf("\nSorted array: \n");
    printArray(arr, size);
    printf("Total recursive calls: %d\n", recurstive_count);
    return 0;
}
