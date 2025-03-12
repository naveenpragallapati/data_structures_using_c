#include<stdio.h>
#include <stdlib.h>
#include<conio.h>

struct sparsematrix_node {
    int data;
    int row_value;
    int col_value;
    struct sparsematrix_node *next;
};

typedef struct sparsematrix_node* SPMNODE;
SPMNODE start = NULL;

SPMNODE createNode(int val, int row, int col) {
    SPMNODE temp = (SPMNODE)malloc(sizeof(struct sparsematrix_node));
    temp->data = val;
    temp->row_value = row;
    temp->col_value = col;
    temp->next = NULL;
    return temp;
} 

void addNode(int val, int row, int col) {
    SPMNODE newNode = createNode(val, row, col);
    if (start == NULL) {
        start = newNode;
    } else {
        SPMNODE temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displaySparseMatrix() {
    SPMNODE temp = start;
    printf("Row\tColumn\tValue\n");
    while (temp != NULL) {
        printf("  %d\t     %d\t    %d\n", temp->row_value, temp->col_value, temp->data);
        temp = temp->next;
    }
}

void main() {
    int rows, cols, i, j;
    int sparse_matrix[10][10];
    
    printf("Enter the row & column sizes of the sparse matrix : ");
    scanf("%d %d", &rows, &cols);
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter the value of sparse_matrix[%d][%d] : ", i, j);
            scanf("%d", &sparse_matrix[i][j]);
        }
    }
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (sparse_matrix[i][j] != 0)
                addNode(sparse_matrix[i][j], i, j);
        }
    }
    
    displaySparseMatrix();
}
