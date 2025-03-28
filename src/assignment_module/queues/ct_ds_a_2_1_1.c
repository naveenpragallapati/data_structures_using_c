#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Queue
typedef struct {
    int *data;      // Array to store queue elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int capacity;   // Capacity of the queue
} Queue;

// Function to create a new queue
Queue* createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (int *)malloc(capacity * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int value) {
    if (queue->rear == queue->capacity - 1) {
        return; // Queue is full
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->data[++queue->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return -1; // Queue is empty
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // Reset queue
    } else {
        queue->front++;
    }
    return value;
}

// Define a structure for Stack using two queues
typedef struct {
    Queue *q1;
    Queue *q2;
} Stack;

// Function to create a new stack using two queues
Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->q1 = createQueue(capacity);
    stack->q2 = createQueue(capacity);
    return stack;
}

// Function to push an element onto the stack
void push(Stack *stack, int x) {
    enqueue(stack->q1, x);
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack->q1)) {
        return -1; // Stack is empty
    }
    while (stack->q1->front != stack->q1->rear) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    int top = dequeue(stack->q1);
    Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    return top;
}

// Function to free allocated memory for the stack and its queues
void freeStack(Stack *stack) {
    free(stack->q1->data);
    free(stack->q2->data);
    free(stack->q1);
    free(stack->q2);
    free(stack);
}

int main() {
    int q;
    scanf("%d", &q);
    Stack *stack = createStack(q); // Create a Stack with capacity q
    int *results = (int *)malloc(q * sizeof(int)); // Array to store results of pop operations
    int resultCount = 0;
    for (int i = 0; i < q; i++) {
        int operationType;
        scanf("%d", &operationType);
        if (operationType == 1) { // Push operation
            int value;
            scanf("%d", &value);
            push(stack, value);
        } else if (operationType == 2) { // Pop operation
            results[resultCount++] = pop(stack); // Store result for later output
        }
    }
    for (int i = 0; i < resultCount; i++) {
        printf("%d ", results[i]);
    }
    printf("\n"); // Print newline at the end
    free(results);          // Free results array
    freeStack(stack);      // Free allocated memory for the stack
    return 0;
}