#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
    struct tnode *left, *right;
};
typedef struct tnode* TREENODE;

struct qnode {
    TREENODE treeNode;
    struct qnode *next;
};
typedef struct qnode* QNODE;

QNODE front = NULL, rear = NULL;

void enqueue(TREENODE node) {
    QNODE temp = (QNODE)malloc(sizeof(struct qnode));
    temp->treeNode = node;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

TREENODE dequeue() {
    if (front == NULL) {
        return NULL;
    }
    QNODE temp = front;
    TREENODE node = front->treeNode;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return node;
}

int isQueueEmpty() {
    return front == NULL;
}

TREENODE createNode(int data) {
    TREENODE newNode = (TREENODE)malloc(sizeof(struct tnode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TREENODE createTree() {
    int data;
    printf("Enter root node data: ");
    scanf("%d", &data);
    TREENODE root = createNode(data);
    enqueue(root);

    while (!isQueueEmpty()) {
        TREENODE current = dequeue();
        printf("Enter left child of %d (enter -1 for no child): ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->left = createNode(data);
            enqueue(current->left);
        }
        printf("Enter right child of %d (enter -1 for no child): ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->right = createNode(data);
            enqueue(current->right);
        }
    }
    return root;
}

void levelOrderTraversal(TREENODE root) {
    if (root == NULL) {
        return;
    }
    enqueue(root);
    while (!isQueueEmpty()) {
        TREENODE current = dequeue();
        printf("%d ", current->data);
        if (current->left != NULL) {
            enqueue(current->left);
        }
        if (current->right != NULL) {
            enqueue(current->right);
        }
    }
    printf("\n");
}

void preorderTraversal(TREENODE root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(TREENODE root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(TREENODE root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    TREENODE root = NULL;
    int choice;

    while (1) {
        printf("1. Create tree using level order traversal\n");
        printf("2. Display level order traversal\n");
        printf("3. Display preorder traversal\n");
        printf("4. Display inorder traversal\n");
        printf("5. Display postorder traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createTree();
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Level order traversal: ");
                    levelOrderTraversal(root);
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Preorder traversal: ");
                    preorderTraversal(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Inorder traversal: ");
                    inorderTraversal(root);
                    printf("\n");
                }
                break;
            case 5:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Postorder traversal: ");
                    postorderTraversal(root);
                    printf("\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}