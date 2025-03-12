#include <stdio.h>
#include <stdlib.h>

void read1(int *matrix, int rows, int cols) {
    printf("Enter %d elements : ", rows*cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", (matrix + i * cols + j));
        }
    }
}

void display(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

void multiplicationOfTwoMatrices(int *a, int *b, int m, int n, int q) {
    int *result = (int *) calloc(m * q, sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                *(result + i * q + j) += (*(a + i * n + k)) * (*(b + k * q + j));
            }
        }
    }
    printf("The Multiplication Matrix is\n");
    display(result, m, q);
    free(result);
}

void main() {
	int *a, *b, m, n, p, q;
	printf("Enter the size of the first matrix : ");
	scanf("%d%d", &m, &n);
	a = (int *) calloc(m * n, sizeof(int));
	read1(a, m, n);
	printf("Enter the size of the second matrix : ");
	scanf("%d%d", &p, &q);
	b = (int *) calloc(p * q, sizeof(int));
	read1(b, p, q);
	printf("The first matrix is\n");
	display(a, m, n);
	printf("The second matrix is\n");
	display(b, p, q);
	if (n == p) {
		multiplicationOfTwoMatrices(a, b, m, n, q);
	} else {
		printf("Multiplication is not possible\n");
	}
}