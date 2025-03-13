#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 20

int stack[STACK_MAX_SIZE];
int top = -1;

// Return 1 if stack is empty else return 0.
int isEmpty() {
    return top == -1;
}

// Push an integer onto the stack
void push(int x) {
    if (top < STACK_MAX_SIZE - 1) {
        stack[++top] = x;
    }
}

// Pop an integer from the stack
int pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return -1; // Error case
}

// Function to evaluate postfix expression
void evaluatePostfix(char *e) {
    int op1, op2, result;
    while (*e != '\0') {
        if (isdigit(*e)) {
            push(*e - '0'); // Convert character to integer and push
        } else if (*e == '+' || *e == '-' || *e == '*' || *e == '/') {
            if (top < 1) {
                printf("Invalid postfix expression.\n");
                return;
            }
            op2 = pop();
            op1 = pop();
            
            switch (*e) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': 
                    if (op2 == 0) {
                        printf("Error: Division by zero.\n");
                        return;
                    }
                    result = op1 / op2; 
                    break;
            }
            push(result);
        } else {
            printf("Invalid postfix expression.\n");
            return;
        }
        e++;
    }
    
    if (top == 0) {
        printf("Result : %d\n", pop());
    } else {
        printf("Invalid postfix expression.\n");
    }
}

//Read a postfix expression and evaluate it.
int main() {
	char exp[20];
	char *e, x;
	printf("Enter the postfix expression : ");
	scanf("%s",exp);
	e = exp;
	evaluatePostfix(e);

}