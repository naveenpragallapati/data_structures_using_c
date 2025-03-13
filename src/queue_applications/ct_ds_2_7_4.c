#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *items;
    int front, rear, capacity;
};

void initQueue(struct Queue *q, int capacity) {
    q->items = (int *)malloc(sizeof(int) * capacity);
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
}

void enqueue(struct Queue *q, int item) {
    if (q->rear == q->capacity - 1) {
        return; // Queue is full
    }
    
    // Print existing queue first (if any)
    for (int i = 0; i <= q->rear; i++) {
        printf("%d ", q->items[i]); 
    }

    // Insert the new element
    q->items[++q->rear] = item;

    // Print "Enqueuing X" after the current queue elements
    printf("Enqueuing %d\n", item);
}

int main() {
    int size;
    scanf("%d", &size);

    struct Queue q;
    initQueue(&q, size);

    for (int i = 0; i < size; i++) {
        int num;
        scanf("%d", &num);
        enqueue(&q, num);
    }

    free(q.items); // Free allocated memory
    return 0;
}
