#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
    struct tnode *left, *right;
};
typedef struct tnode* TREENODE;

// Function to create a new node
TREENODE newNode(int data) {
    TREENODE temp = (TREENODE)malloc(sizeof(struct tnode));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to print an array
void printArray(int path[], int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", path[i]);
    printf("\n");
}

// Recursive function to print all root-to-leaf paths
void printPathsRecur(TREENODE node, int path[], int pathLen) {
    if (node == NULL)
        return;

    // Add current node to path
    path[pathLen] = node->data;
    pathLen++;

    // If it's a leaf node, print the path
    if (node->left == NULL && node->right == NULL) {
        printArray(path, pathLen);
    } else {
        // Otherwise, go down left and right subtree
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }
}

// Wrapper function to print all root-to-leaf paths
void printPaths(TREENODE root) {
    int path[1000];
    printPathsRecur(root, path, 0);
}

// Main function
int main() {
    // Sample tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TREENODE root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("All root-to-leaf paths:\n");
    printPaths(root);

    return 0;
}