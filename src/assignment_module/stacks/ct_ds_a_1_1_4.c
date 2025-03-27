#include <stdio.h>

void findImmediateSmaller(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] < arr[i]) {
            arr[i] = arr[i + 1];
        } else {
            arr[i] = -1;
        }
    }
    arr[n - 1] = -1; // Last element is always -1

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    findImmediateSmaller(arr, n);
    return 0;
}