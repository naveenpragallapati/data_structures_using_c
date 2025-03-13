#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *items;
    int front, rear, size;
};

// Initialize Queue
void initQueue(struct Queue *q, int size) {
    q->items = (int *)malloc(sizeof(int) * size);
    q->front = 0;
    q->rear = -1;
    q->size = size;
}

// Enqueue operation
void enqueue(struct Queue *q, int item) {
    if (q->rear == q->size - 1) return; // Queue is full
    q->items[++q->rear] = item;
}

// Dequeue operation
int dequeue(struct Queue *q) {
    if (q->front > q->rear) return -1; // Queue is empty
    return q->items[q->front++];
}

// Function to reverse the queue
void rev(struct Queue *q) {
    if (q->front > q->rear) return; // No elements to reverse

    int stack[q->size];
    int top = -1;

    // Step 1: Dequeue all elements into a stack
    while (q->front <= q->rear) {
        stack[++top] = dequeue(q);
    }

    // Reset front and rear pointers
    q->front = 0;
    q->rear = -1;

    // Step 2: Pop from stack and enqueue back
    while (top >= 0) {
        enqueue(q, stack[top--]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Queue q;
    initQueue(&q, n);

    // Read queue elements
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        enqueue(&q, num);
    }

    // Reverse the queue
    rev(&q);

    // Print reversed queue
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d", q.items[i]);
        if (i < q.rear) printf(" "); // Print '·' as separator
    }
    printf(" \n");

    free(q.items);
    return 0;
}
