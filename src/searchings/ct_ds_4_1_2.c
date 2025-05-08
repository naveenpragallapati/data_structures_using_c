#include <stdio.h>
#include <stdio.h>

// Function to read n elements into the array
void read1(int a[], int n) {
    printf("Enter %d elements : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

// Recursive function for linear search
int linearSearch(int a[], int index, int n, int key) {
    if (index > n) {
        return -1;  // Base case: not found
    }
    if (a[index] == key) {
        return index;  // Found at current index
    }
    return linearSearch(a, index + 1, n, key);  // Recursive call
}

void main() {
	int a[20], n, pos, key;
	printf("Enter n value : ");
	scanf("%d", &n);
	read1(a, n);
	printf("Enter a key element : ");
	scanf("%d", &key);
	pos = linearSearch(a, 0, n - 1, key);
	if (pos == -1) {
		printf("The key element %d is not found\n", key);
	} else {
		printf("The key element %d is found at position : %d\n", key, pos);
	}
}