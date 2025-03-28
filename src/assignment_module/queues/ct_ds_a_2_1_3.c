#include <stdio.h>
#include <stdlib.h>

// Structure for Queue
typedef struct {
    int *data;
    int front, rear, size, capacity;
} Queue;

// Queue Operations
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = capacity - 1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue *q, int value) {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue *q) {
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return value;
}

int queueFront(Queue *q) {
    return q->data[q->front];
}

int isQueueEmpty(Queue *q) {
    return q->size == 0;
}

// Function to calculate the time taken for the class at position k to finish getting chocolates
int timeToGetChocolates(int* classes, int n, int k) {
    Queue* classQueue = createQueue(n);
    int time = 0;

    // Enqueue all classes with their respective number of students
    for (int i = 0; i < n; i++) {
        enqueue(classQueue, classes[i]);
    }

    while (!isQueueEmpty(classQueue)) {
        int students = dequeue(classQueue);
        time++;
        if (students > 1) {
            enqueue(classQueue, students - 1);
        }
        if (k == 0 && students == 1) {
            break;
        }
        k = (k - 1 + classQueue->size) % classQueue->size;
    }

    // Free allocated memory
    free(classQueue->data);
    free(classQueue);

    return time;
}

int main() {
    int n;
    scanf("%d", &n);
    int classes[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &classes[i]);
    }
    int k;
    scanf("%d", &k);
    printf("%d\n", timeToGetChocolates(classes, n, k));
    return 0;
}