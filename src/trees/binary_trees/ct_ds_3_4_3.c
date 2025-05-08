#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX_VALUE 65536
struct ThreadedBinaryNode {
	int data;
    struct ThreadedBinaryNode * left, *right;
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
    TBNODE ptr = root, parent = NULL;
    int found = false;

    while (ptr != NULL) {
        if (ele == ptr->data) {
            found = true;
            break;
        }
        parent = ptr;
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

    if (!found) {
        printf("Cannot find %d in the threaded binary tree.\n", ele);
        return;
    }

    if (ptr->leftThread == true && ptr->rightThread == true) {  // Case 1: Leaf node
        if (parent == NULL) {
            root = NULL;
        } else if (parent->left == ptr) {
            parent->left = ptr->left;
            parent->leftThread = true;
        } else {
            parent->right = ptr->right;
            parent->rightThread = true;
        }
        free(ptr);
    } else if (ptr->leftThread == false && ptr->rightThread == true) {  // Case 2: One left child
        if (parent == NULL) {
            root = ptr->left;
        } else if (parent->left == ptr) {
            parent->left = ptr->left;
        } else {
            parent->right = ptr->left;
        }
        free(ptr);
    } else if (ptr->leftThread == true && ptr->rightThread == false) {  // Case 3: One right child
        if (parent == NULL) {
            root = ptr->right;
        } else if (parent->left == ptr) {
            parent->left = ptr->right;
        } else {
            parent->right = ptr->right;
        }
        free(ptr);
    } else {  // Case 4: Node with two children
        TBNODE successor = ptr->right;
        TBNODE successorParent = ptr;
        while (successor->leftThread == false) {
            successorParent = successor;
            successor = successor->left;
        }
        ptr->data = successor->data;
        if (successorParent->left == successor) {
            successorParent->left = successor->left;
            successorParent->leftThread = true;
        } else {
            successorParent->right = successor->right;
            successorParent->rightThread = true;
        }
        free(successor);
    }
}

int search(int ele) {
    TBNODE ptr = root;
    while (ptr != NULL) {
        if (ele == ptr->data)
            return true;
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
    return false;
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