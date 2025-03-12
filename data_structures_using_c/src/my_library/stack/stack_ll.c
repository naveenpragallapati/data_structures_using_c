#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *stk;

// Stack top
stk top = NULL;

// Check if stack is empty
int isEmpty() {
    return top == NULL;
}

// Push operation
void push(int x) {
    stk newNode = (stk)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory Allocation Failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("Pushed: %d\n", x);
}

// Pop operation
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = top->data;
    stk temp = top;
    top = top->next;
    free(temp);
    printf("Popped: %d\n", data);
    return data;
}

// Peek operation
int peek() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return -1;
    }
    printf("Peek: %d\n", top->data);
    return top->data;
}

// Display stack
void display() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return;
    }
    stk temp = top;
    printf("Stack: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check if Empty\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty())
                    printf("Stack is Empty\n");
                else
                    printf("Stack is Not Empty\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again!\n");
        }
    } while (choice != 6);

    return 0;
}