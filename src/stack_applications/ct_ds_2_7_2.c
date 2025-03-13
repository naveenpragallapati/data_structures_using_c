#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    int arr[MAX];
} Stack;

void push(Stack *s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->arr[++(s->top)] = val;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Invalid postfix expression\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

int evaluatePostfix(char *expr) {
    Stack s;
    s.top = -1;
    int i, op1, op2, result;

    for (i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {  // If operand, push onto stack
            push(&s, expr[i] - '0');
        } 
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') { 
            if (s.top < 1) {  // Less than 2 operands means invalid expression
                printf("Invalid postfix expression\n");
                return -1;
            }
            op2 = pop(&s);
            op1 = pop(&s);
            
            switch (expr[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': 
                    if (op2 == 0) {
                        printf("Division by zero error\n");
                        return -1;
                    }
                    result = op1 / op2;
                    break;
            }
            push(&s, result);
        } 
        else { // Invalid character in expression
            printf("Invalid postfix expression\n");
            return -1;
        }
    }

    // Final result should be the only value in stack
    if (s.top != 0) {
        printf("Invalid postfix expression\n");
        return -1;
    }

    return pop(&s);
}

int main() {
    char expr[MAX];

    printf("Postfix expression: ");
    scanf("%s", expr);

    int result = evaluatePostfix(expr);
    if (result != -1) {
        printf("Evaluated expression: %d\n", result);
    }

    return 0;
}
