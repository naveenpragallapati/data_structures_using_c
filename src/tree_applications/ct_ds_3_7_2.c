#include <stdio.h>
#include <stdlib.h>

// Complete the below function to determine whether the given preorder traversal of a
// binary tree represents a skewed BST
int isSkewedBST(int pre[], int n, int *min_val, int *max_val    ){
    *min_val = pre[0];
    *max_val = pre[0];

    int root = pre[0];  // Initialize root to first element
    int lower_bound = -100000, upper_bound = 100000;  // large bounds

    for (int i = 1; i < n; i++) {
        // Update min and max
        if (pre[i] < *min_val) *min_val = pre[i];
        if (pre[i] > *max_val) *max_val = pre[i];

        // Check if the current value is valid in BST range
        if (pre[i] < root) {
            // Left child: must be > lower_bound
            if (pre[i] < lower_bound) return 0;
            upper_bound = root;
        } else {
            // Right child: must be < upper_bound
            if (pre[i] > upper_bound) return 0;
            lower_bound = root;
        }

        // Move to next node as root
        root = pre[i];
    }

    return 1;  // Skewed BST

}

int main() {
    int n;
    scanf("%d", &n);
    int *pre = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    int min_val, max_val;
    int isSkewed = isSkewedBST(pre, n, &min_val, &max_val);
    if (isSkewed) {
        printf("The BST is skewed: True\n");
        printf("%d %d\n", min_val, max_val);
    }
    else {
        printf("The BST is skewed: False\n");
    }
    free(pre);
    return 0;
}
