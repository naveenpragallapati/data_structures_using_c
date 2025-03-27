#include <stdio.h>
#include <string.h>
#define MAX 100

// Stack structure
struct Stack {
    int top;
    char arr[MAX];
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char c) {
    if (!isFull(stack)) {
        stack->arr[++stack->top] = c;
    }
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return '\0'; // Return null character if stack is empty
}

// Function to reverse the string using stack
void reverseString(char* str) {
    struct Stack stack;
    initStack(&stack);

    // Push all characters of the string onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }

    // Pop characters from the stack and overwrite the string
    for (int i = 0; !isEmpty(&stack); i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[MAX];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    reverseString(str);
    printf("%s\n", str);
    return 0;
}