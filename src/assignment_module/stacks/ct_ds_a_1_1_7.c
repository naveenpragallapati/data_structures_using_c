#include <stdio.h>
#include <stdlib.h>

// Define the MaxStack structure
typedef struct {
    int *data;      // Array to store stack elements
    int *maxData;  // Array to store maximum elements
    int top;       // Index of the top element
    int maxTop;    // Index of the top maximum element
    int capacity;  // Capacity of the stack
} MaxStack;

// Function to initialize the MaxStack
MaxStack* createMaxStack(int capacity) {
    MaxStack *stack = (MaxStack *)malloc(sizeof(MaxStack));
    stack->data = (int *)malloc(capacity * sizeof(int));
    stack->maxData = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->maxTop = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to push an element onto the stack
void push(MaxStack *stack, int val) {
    if (stack->top < stack->capacity - 1) {
        stack->data[++stack->top] = val;
        if (stack->maxTop == -1 || val >= stack->maxData[stack->maxTop]) {
            stack->maxData[++stack->maxTop] = val;
        }
    }
}

// Function to pop the top element from the stack
int pop(MaxStack *stack) {
    if (stack->top == -1) {
        return -1; // Stack is empty
    }
    int poppedValue = stack->data[stack->top--];
    if (poppedValue == stack->maxData[stack->maxTop]) {
        stack->maxTop--;
    }
    return poppedValue;
}

// Function to get the top element of the stack
int top(MaxStack *stack) {
    if (stack->top == -1) {
        return -1; // Stack is empty
    }
    return stack->data[stack->top];
}

// Function to get the maximum element in the stack
int getMax(MaxStack *stack) {
    if (stack->maxTop == -1) {
        return -1; // Stack is empty
    }
    return stack->maxData[stack->maxTop];
}

// Function to free the allocated memory for the stack
void freeMaxStack(MaxStack *stack) {
    free(stack->data);
    free(stack->maxData);
    free(stack);
}


int main() {
    int Q;
    scanf("%d", &Q);
    MaxStack *stack = createMaxStack(Q); // Create a MaxStack with capacity Q
    int *results = (int *)malloc(Q * sizeof(int)); // Store results of top/getMax
    int resultCount = 0;
    for (int i = 0; i < Q; i++) {
        int operationType;
        scanf("%d", &operationType);
        if (operationType == 1) { // Push operation
            int value;
            scanf("%d", &value);
            push(stack, value);
        } else if (operationType == 2) { // Pop operation
            pop(stack);
        } else if (operationType == 3) { // Top operation
            results[resultCount++] = top(stack);
        } else if (operationType == 4) { // getMax operation
            results[resultCount++] = getMax(stack);
        }
    }
    for (int i = 0; i < resultCount; i++) {
        printf("%d\n", results[i]);
    }

    free(results);          // Free results array
    freeMaxStack(stack);   // Free allocated memory for the stack
    return 0;
}
// End of code