#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort - ascending
int cmpAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Compare function for qsort - descending
int cmpDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int t;
    scanf("%d", &t); // number of test cases

    while (t--) {
        int n;
        scanf("%d", &n); // size of arrays

        int A[n], B[n];

        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &B[i]);

        // Sort A in ascending, B in descending
        qsort(A, n, sizeof(int), cmpAsc);
        qsort(B, n, sizeof(int), cmpDesc);

        // Calculate sum of products
        int result = 0;
        for (int i = 0; i < n; i++)
            result += A[i] * B[i];

        printf("%d\n", result);
    }

    return 0;
}
