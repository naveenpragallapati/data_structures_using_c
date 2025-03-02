#include <stdio.h>
#include <stdlib.h>

void read1(int *p, int n) {
    printf("Enter %d elements : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
}

void display(int *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

void bubbleSort(int *p, int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (p[j] > p[j+1]) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int binarySearch(int *p, int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (p[mid] == key) {
            return mid;
        } else if (p[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void main() {
	int *p, n, key, flag;
	printf("Enter value of n : ");
	scanf("%d", &n);
	p = (int *) malloc(n * sizeof(int));
	read1(p, n);
	bubbleSort(p, n);
	printf("After sorting the elements are : ");
	display(p, n);
	printf("Enter key element : ");
	scanf("%d", &key);
	flag = binarySearch(p, n, key);
	if (flag == -1) {
		printf("The given key element %d is not found\n", key);
	} else {
		printf("The given key element %d is found at position : %d\n", key, flag);
	}
}