#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define STACK_MAX_SIZE 20

char stack[STACK_MAX_SIZE];
int top = -1;

// Return 1 if stack is empty else return 0.
int isEmpty() {
    return top == -1;
}

// Push the character into stack
void push(char x) {
    if (top < STACK_MAX_SIZE - 1) {
        stack[++top] = x;
    }
}

// Pop a character from stack
char pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return -1; // Return an invalid character if stack is empty
}

// Return precedence of operators
int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/' || x == '%')
        return 2;
    return -1; // Invalid operator
}

// Function to convert infix expression to postfix
void convertInfix(char *e) {
    char postfix[50];
    int i = 0, j = 0;
    int parentheses_count = 0;
    while (*e != '\0') {
        if (isalnum(*e)) {
            postfix[j++] = *e;
        } else if (*e == '(') {
            push(*e);
            parentheses_count++;
        } else if (*e == ')') {
            parentheses_count--;
            while (!isEmpty() && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && stack[top] == '(') {
                pop(); // Remove '(' from stack
            } else {
                printf("Invalid infix expression : unbalanced parenthesis.\n");
                return;
            }
        } else if (*e == '+' || *e == '-' || *e == '*' || *e == '/' || *e == '%') {
            while (!isEmpty() && priority(stack[top]) >= priority(*e)) {
                postfix[j++] = pop();
            }
            push(*e);
        } else if (isspace(*e)) {
            // Ignore spaces
        } else {
            printf("Invalid symbols in infix expression. Only alphanumeric and { '+', '-','*', '%%', '/' } are allowed.\n");
            return;
        }
        e++;
    }

    while (!isEmpty()) {
        if (stack[top] == '(') {
            printf("Invalid infix expression : unbalanced parenthesis.\n");
            return;
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix expression : %s\n", postfix);
}

int main() {
	char exp[20];
	char *e, x;
	printf("Enter the expression : ");
	scanf("%s",exp);
	e = exp;
	convertInfix(e);
}