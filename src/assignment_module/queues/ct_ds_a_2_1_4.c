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

int isQueueEmpty(Queue *q) {
    return q->size == 0;
}

// Function to rearrange students by interleaving the first half with the second half
void rearrangeStudents(int* students, int n) {
    int half = n / 2;
    Queue* firstHalf = createQueue(half);
    Queue* secondHalf = createQueue(half);

    // Enqueue the first half of the students
    for (int i = 0; i < half; i++) {
        enqueue(firstHalf, students[i]);
    }

    // Enqueue the second half of the students
    for (int i = half; i < n; i++) {
        enqueue(secondHalf, students[i]);
    }

    // Dequeue from both queues alternately to form the rearranged order
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            students[i] = dequeue(firstHalf);
        } else {
            students[i] = dequeue(secondHalf);
        }
    }

    // Free allocated memory
    free(firstHalf->data);
    free(firstHalf);
    free(secondHalf->data);
    free(secondHalf);
}

int main() {
    int n;
    scanf("%d", &n);
    int students[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &students[i]);
    }

    rearrangeStudents(students, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", students[i]);
    }
    printf("\n");

    return 0;
}