#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
    int *arr;
    int front, rear;
    int size;
} Queue;

// Function to initialize a queue
void initQueue(Queue *q, int size) {
    q->arr = (int *)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = size;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to enqueue (push) an element to the queue
void enqueue(Queue *q, int value) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
}

// Function to dequeue (pop) an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Define the Stack structure using two queues
typedef struct Stack {
    Queue q1, q2;
} Stack;

// Function to initialize the stack using two queues
void initStack(Stack *stack, int size) {
    initQueue(&stack->q1, size);
    initQueue(&stack->q2, size);
}

// Push operation to insert an element into the stack
void push(Stack *stack, int x) {
    enqueue(&stack->q1, x);
}

// Pop operation to remove the top element from the stack
int pop(Stack *stack) {
    if (isEmpty(&stack->q1)) {
        return -1;
    }
    while (stack->q1.front != stack->q1.rear) {
        enqueue(&stack->q2, dequeue(&stack->q1));
    }
    int top = dequeue(&stack->q1);
    Queue temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    return top;
}

// Main function to process queries
int main() {
    int q;
    scanf("%d", &q);
    Stack stack;
    initStack(&stack, q);
    int queries[q][2];  // Store queries to process later
    for (int i = 0; i < q; i++) {
        scanf("%d", &queries[i][0]);
        if (queries[i][0] == 1) {
            scanf("%d", &queries[i][1]);
        }
    }
    int first_pop = 1; // Flag to handle space formatting for output
    for (int i = 0; i < q; i++) {
        if (queries[i][0] == 1) {
            push(&stack, queries[i][1]);
        } else if (queries[i][0] == 2) {
            int result = pop(&stack);
            if (result != -1) {
                if (first_pop) {
                    printf("%d", result);
                    first_pop = 0;
                } else {
                    printf(" %d", result);
                }
            } else {
                if (first_pop) {
                    printf("-1");
                    first_pop = 0;
                } else {
                    printf(" -1");
                }
            }
        }
    }
    printf("\n");
    return 0;
}