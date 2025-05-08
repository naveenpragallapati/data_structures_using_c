#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX_VALUE 65536

// Definition of Threaded Binary Node
struct ThreadedBinaryNode {
    int data;
    struct ThreadedBinaryNode *left, *right;
    int leftThread, rightThread; // 1 if thread, 0 otherwise
};

typedef struct ThreadedBinaryNode *TBNODE;
TBNODE root = NULL;

// Function to insert a node in the Threaded Binary Search Tree
void insert(int ele) {
    TBNODE ptr = root;
    TBNODE par = root; // Parent of new node

    // Find the correct position to insert
    while (ptr != NULL) {
        if (ele == ptr->data) {
            printf("Duplicates are not allowed.\n");
            return;
        }
        par = ptr;
        if (ele < ptr->data) {
            if (ptr->leftThread == false)
                ptr = ptr->left;
            else
                break;
        } else {
            if (ptr->rightThread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    // Create new node
    TBNODE temp = (TBNODE)malloc(sizeof(struct ThreadedBinaryNode));
    temp->data = ele;
    temp->leftThread = true;
    temp->rightThread = true;

    // Insert the node
    if (par == root || ele < par->data) {
        temp->left = par->left;
        temp->right = par;
        par->leftThread = false;
        par->left = temp;
    } else {
        temp->right = par->right;
        temp->left = par;
        par->rightThread = false;
        par->right = temp;
    }
}

// Function to find the leftmost node (starting point for in-order traversal)
TBNODE leftmost(TBNODE node) {
    while (node != NULL && node->leftThread == false)
        node = node->left;
    return node;
}

// Function to traverse the Threaded Binary Search Tree (In-Order Traversal)
void traverse() {
    TBNODE ptr = leftmost(root->left);
    while (ptr != root) {
        printf("%d ", ptr->data);
        if (ptr->rightThread)
            ptr = ptr->right;
        else
            ptr = leftmost(ptr->right);
    }
    printf("\n");
}

int main() {
	int ele, op, pos;
	root = (TBNODE)malloc(sizeof(struct ThreadedBinaryNode));
	root->right = root->left = root;
	root->leftThread = true;
	root->data = MAX_VALUE;
	while(1)
	{
		printf("1.Insert 2.Traversal 3.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element to be inserted : ");
					scanf("%d", &ele);
					insert(ele);
					break;
			case 2:
					if(root->right == root && root->left == root) {
						printf("Threaded binary tree is empty.\n");
					}
					else {
						printf("Elements of the threaded binary tree : ");
						traverse();
					}
					break;
			case 3:	exit(0);
		}
	}
}