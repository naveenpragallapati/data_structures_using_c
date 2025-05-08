#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX_VALUE 65536
struct ThreadedBinaryNode {
	int data;
    struct ThreadedBinaryNode * left, *right;
    // 1- indicates a thread, 0- indicates not a thread.
    int leftThread, rightThread; 
};
typedef struct ThreadedBinaryNode * TBNODE;
TBNODE root = NULL;
void insert(int ele) {
	TBNODE p = root;
	for (;;) {
		if (p->data < ele) {
			if (p->rightThread) 
				break;
			p = p->right;
		} else if (p->data > ele) {
			if (p->leftThread) 
				break;
			p = p->left;
		} else { 
			printf("Duplicates are not allowed.\n");
			return; 
		}
	}
	TBNODE tmp = (TBNODE)malloc(sizeof(struct ThreadedBinaryNode));
	tmp->data = ele;
	tmp->rightThread = tmp->leftThread = true;
	if (p->data < ele) { 
		tmp->right = p->right;
		tmp->left = p;
		p->right = tmp;
		p->rightThread = false;
	} else {
		tmp->right = p;
		tmp->left = p->left;
		p->left = tmp;
		p->leftThread = false;
	}
}
void delete(int ele) {
    TBNODE dest = root->left, p = root;  // dest: node to delete, p: parent

    // 🔎 Searching for the node to delete
    while (dest != root) {
        if (dest->data < ele) {
            if (dest->rightThread) {
                printf("Cannot find %d in the threaded binary tree.\n", ele);
                return;
            }
            p = dest;
            dest = dest->right;
        } else if (dest->data > ele) {
            if (dest->leftThread) {
                printf("Cannot find %d in the threaded binary tree.\n", ele);
                return;
            }
            p = dest;
            dest = dest->left;
        } else {
            break;  // Found the node to delete
        }
    }

    if (dest == root) {  // Node not found
        printf("Cannot find %d in the threaded binary tree.\n", ele);
        return;
    }

    // 🌳 Case 1: Node has **two children**
    TBNODE target = dest;
    if (!dest->rightThread && !dest->leftThread) {
        p = dest;
        target = dest->left;

        // Find the **rightmost node** of the left subtree
        while (!target->rightThread) {
            p = target;
            target = target->right;
        }

        // Copy target's value into dest
        dest->data = target->data;
    }

    // 🌿 Case 2 & 3: Node has one or zero children
    TBNODE child;
    if (target->rightThread && target->leftThread) {
        // Case: **Leaf node**
        child = NULL;
    } else if (!target->leftThread) {
        // Case: **Only left child exists**
        child = target->left;
    } else {
        // Case: **Only right child exists**
        child = target->right;
    }

    // 🛠 Updating parent links
    if (p->data > target->data) {  // Node is in **left subtree**
        if (target->rightThread && target->leftThread) {
            p->left = target->left;
            p->leftThread = 1;
        } else if (target->rightThread) {
            // **Left child exists, updating right-thread**
            TBNODE largest = target->left;
            while (!largest->rightThread) {
                largest = largest->right;
            }
            largest->right = p;
            p->left = target->left;
        } else {
            // **Right child exists**
            TBNODE smallest = target->right;
            while (!smallest->leftThread) {
                smallest = smallest->left;
            }
            smallest->left = target->left;
            p->left = target->right;
        }
    } else {  // Node is in **right subtree**
        if (target->rightThread && target->leftThread) {
            p->right = target->right;
            p->rightThread = 1;
        } else if (target->rightThread) {
            TBNODE largest = target->left;
            while (!largest->rightThread) {
                largest = largest->right;
            }
            largest->right = target->right;
            p->right = target->left;
        } else {
            TBNODE smallest = target->right;
            while (!smallest->leftThread) {
                smallest = smallest->left;
            }
            smallest->left = p;
            p->right = target->right;
        }
    }

    free(target);  // Delete the node
}

int search(int ele) {
    TBNODE tmp = root->left;  // Start from the actual tree root

    while (tmp != root) {  // Continue until we reach the dummy root
        if (tmp->data < ele) {
            // Search in the right subtree
            if (tmp->rightThread) return 0;  // Element not found
            tmp = tmp->right;
        } else if (tmp->data > ele) {
            // Search in the left subtree
            if (tmp->leftThread) return 0;  // Element not found
            tmp = tmp->left;
        } else {
            // Found the element
            return 1;
        }
    }
    return 0;
}

void traverse() {
	TBNODE tmp = root,p;
	for (;;) {
		p = tmp;
		tmp = tmp->right;
		if (!p->rightThread) {
			while (!tmp->leftThread) {
				tmp = tmp->left;
			}
		}
		if (tmp == root) 
			break;
		printf("%d ",tmp->data);
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
		printf("1.Insert 2.Delete 3.Search 4.Traversal 5.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element to be inserted : ");
					scanf("%d", &ele);
					insert(ele);
					break;
			case 2: printf("Enter the element to be deleted : ");
					scanf("%d", &ele);
					delete(ele);
					break;
			case 3: printf("Enter the element to be searched : ");
					scanf("%d", &ele);
					pos = search(ele);
					if(pos)
						printf("Element found in threaded binary tree.\n");
					else
						printf("Element not found in threaded binary tree.\n");
					pos=0;
					break;
			case 4:
					if(root->right == root && root->left == root) {
						printf("Threaded binary tree is empty.\n");
					}
					else {
						printf("Elements of the threaded binary tree : ");
						traverse();
					}
					break;
			case 5:	exit(0);
		}
	}
}