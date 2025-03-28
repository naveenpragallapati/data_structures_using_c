#include <stdio.h>
#include <stdlib.h>

// Structure for Queue (Students)
typedef struct {
    int *data;
    int front, rear, size;
} Queue;

// Structure for Stack (Sandwiches)
typedef struct {
    int *data;
    int top;
} Stack;

// Queue Operations
Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = size - 1;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int value, int n) {
    q->rear = (q->rear + 1) % n;
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue *q) {
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    q->size--;
    return value;
}

int queueFront(Queue *q) {
    return q->data[q->front];
}

int isQueueEmpty(Queue *q) {
    return q->size == 0;
}

// Stack Operations
Stack* createStack(int size) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(size * sizeof(int));
    s->top = -1;
    return s;
}

void push(Stack *s, int value) {
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int stackTop(Stack *s) {
    return s->data[s->top];
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

// Function to count students who cannot eat
int countStudents(int* students, int* sandwiches, int n) {
    Queue* studentQueue = createQueue(n);
    Stack* sandwichStack = createStack(n);

    // Enqueue all students
    for (int i = 0; i < n; i++) {
        enqueue(studentQueue, students[i], n);
    }

    // Push all sandwiches onto the stack
    for (int i = n - 1; i >= 0; i--) {
        push(sandwichStack, sandwiches[i]);
    }

    int attempts = 0; // Number of attempts to match the top sandwich

    while (!isQueueEmpty(studentQueue) && attempts < studentQueue->size) {
        if (queueFront(studentQueue) == stackTop(sandwichStack)) {
            dequeue(studentQueue);
            pop(sandwichStack);
            attempts = 0; // Reset attempts after a successful match
        } else {
            enqueue(studentQueue, dequeue(studentQueue), n);
            attempts++;
        }
    }

    int count = studentQueue->size;

    // Free allocated memory
    free(studentQueue->data);
    free(studentQueue);
    free(sandwichStack->data);
    free(sandwichStack);

    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int students[n], sandwiches[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &students[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &sandwiches[i]);
    }
    printf("%d\n", countStudents(students, sandwiches, n));
    return 0;
}