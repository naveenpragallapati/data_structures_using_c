#include <stdio.h>
#include <stdlib.h>

// Function to compare two elements for sorting in descending order
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Function to sort the stack in descending order
void sortStack(int n, int stack[]) {
    // Use the qsort function to sort the stack in descending order
    qsort(stack, n, sizeof(int), compare);
}

int main() {
    int n;
    scanf("%d", &n);
    int stack[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &stack[i]);
    }
    sortStack(n, stack);
    for(int i = 0; i < n; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return 0;
}