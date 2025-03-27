#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure to store characters
struct Stack {
    char arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char c) {
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = c;
    }
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top--];
    }
    return '\0'; // Return a special value if stack is empty
}

// Function to check if the given string has balanced brackets
int isBalanced(char* s) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(&stack, s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (stack.top == -1) {
                return 0; // Unmatched closing bracket
            }
            char top = pop(&stack);
            if ((s[i] == ')' && top != '(') ||
                (s[i] == '}' && top != '{') ||
                (s[i] == ']' && top != '[')) {
                return 0; // Mismatched brackets
            }
        }
    }
    return stack.top == -1; // Check if all opening brackets are matched
}

int main() {
    char s[MAX];
    scanf("%s", s);
    if (isBalanced(s)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}