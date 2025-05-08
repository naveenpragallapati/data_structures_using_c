#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *left, *right;
};

// Queue to build the tree level-wise
struct Queue {
    struct node** arr;
    int front, rear, size;
};

struct node* newNode(int val) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct node**)malloc(size * sizeof(struct node*));
    q->front = q->rear = -1;
    q->size = size;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct node* n) {
    if (q->rear == q->size - 1) return;
    q->arr[++q->rear] = n;
    if (q->front == -1) q->front = 0;
}

struct node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct node* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Mirror check
int isMirror(struct node* t1, struct node* t2) {
    if (!t1 && !t2) return 1;
    if (!t1 || !t2) return 0;
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct node* root) {
    if (!root) return 1;
    return isMirror(root->left, root->right);
}

// Build tree from level-order with "null" strings
struct node* buildTree(char tokens[][10], int count) {
    if (count == 0 || strcmp(tokens[0], "null") == 0) return NULL;

    struct node* root = newNode(atoi(tokens[0]));
    struct Queue* q = createQueue(count);
    enqueue(q, root);

    int i = 1;
    while (i < count) {
        struct node* curr = dequeue(q);

        // Left child
        if (i < count && strcmp(tokens[i], "null") != 0) {
            curr->left = newNode(atoi(tokens[i]));
            enqueue(q, curr->left);
        }
        i++;

        // Right child
        if (i < count && strcmp(tokens[i], "null") != 0) {
            curr->right = newNode(atoi(tokens[i]));
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);

    char tokens[100][10];
    int count = 0;

    char* token = strtok(input, " \n");
    while (token && strcmp(token, "-1") != 0) {
        strcpy(tokens[count++], token);
        token = strtok(NULL, " \n");
    }

    struct node* root = buildTree(tokens, count);
    printf("%d\n", isSymmetric(root));

    return 0;
}
// This code builds a binary tree from a level-order input and checks if it is symmetric.