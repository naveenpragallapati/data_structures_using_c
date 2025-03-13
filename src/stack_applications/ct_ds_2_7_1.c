#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char arr[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->arr[++s->top] = c;
    }
}

char pop(Stack *s) {
    return (s->top >= 0) ? s->arr[s->top--] : '\0';
}

char peek(Stack *s) {
    return (s->top >= 0) ? s->arr[s->top] : '\0';
}

int precedence(char c) {
    switch (c) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isValidChar(char c) {
    return isalnum(c) || strchr("()+-*/%^", c);
}

int isBalancedParentheses(const char *expr) {
    Stack s = {.top = -1};
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(') push(&s, '(');
        else if (expr[i] == ')') {
            if (s.top == -1) return 0;
            pop(&s);
        }
    }
    return s.top == -1;
}

void infixToPostfix(const char *infix) {
    Stack s = {.top = -1};
    char postfix[MAX] = "";
    int j = 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (!isValidChar(c)) {
            printf("Invalid symbols used\n");
            return;
        }

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        } else {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter the expression: ");
    scanf("%s", infix);

    if (!isBalancedParentheses(infix)) {
        printf("Invalid infix expression\n");
        return 0;
    }

    infixToPostfix(infix);
    return 0;
}