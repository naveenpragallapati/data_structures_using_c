#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1; // Initialize top as -1

int isEmpty() {
    if (top < 0) {
        printf("Stack is Empty!\n");
    } else {
        printf("Stack is Not Empty!\n");
    }
    return top < 0;
}

void push(int x) {
    if (top < MAX - 1) {
        stack[++top] = x;
        printf("Pushed: %d\n", x);
    } else {
        printf("Stack Overflow!\n");
    }
}

void pop() {
    if (top >= 0) {
        printf("Popped: %d\n", stack[top--]);
    } else {
        printf("Stack Underflow!\n");
    }
}

void peek() {
    if (top >= 0) {
        printf("Peek: %d\n", stack[top]);
    } else {
        printf("Stack Underflow!\n");
    }
}

void display() {
    if (top >= 0) {
        printf("Stack: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    } else {
        printf("Stack is Empty!\n");
    }
}

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
                isEmpty();
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
