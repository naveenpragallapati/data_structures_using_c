#include <stdio.h>
#include <stdlib.h>

struct Stack {
    char *items;
    int top;
    int capacity;
};

void initStack(struct Stack *stack, int capacity) {
    stack->items = (char *)malloc(sizeof(char) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
}

void push(struct Stack *stack, char item) {
    if (stack->top == stack->capacity - 1) {
        printf("Error: Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Error: Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}


int isBalancedParentheses(const char *expression) {
struct Stack stack;
    initStack(&stack, 100);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                free(stack.items);
                return 0; // Not balanced
            }

            char topChar = pop(&stack);
            
            // Directly checking matching pairs without a separate function
            if ((topChar == '(' && ch != ')') || 
                (topChar == '{' && ch != '}') || 
                (topChar == '[' && ch != ']')) {
                free(stack.items);
                return 0; // Not balanced
            }
        }
    }

    int balanced = isEmpty(&stack);
    free(stack.items);
    return balanced;
}

int main() {
    char input_expression[100];
    scanf("%s", input_expression);
    if (isBalancedParentheses(input_expression)) {
        printf("%s - balanced\n", input_expression);
    } else {
        printf("%s - Not balanced\n", input_expression);
    }
    return 0;
}
