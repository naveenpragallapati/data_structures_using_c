#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

// Stack structure for operators
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Stack structure for operands (postfix evaluation)
typedef struct {
    double items[MAX];
    int top;
} OperandStack;

// Function prototypes
Stack push(Stack s, char c);
Stack pop(Stack s, char *popped);
char peek(Stack s);
int precedence(char op);
int isOperator(char ch);
char *infixToPostfix(char infix[]);
OperandStack pushOperand(OperandStack s, double value);
OperandStack popOperand(OperandStack s, double *popped);
double evaluatePostfix(char postfix[]);

// Function to push to operator stack
Stack push(Stack s, char c) {
    if (s.top == MAX - 1) {
        printf("Stack Overflow!\n");
        return s;
    }
    s.items[++(s.top)] = c;
    return s;
}

// Function to pop from operator stack
Stack pop(Stack s, char *popped) {
    if (s.top == -1) {
        *popped = '\0';
    } else {
        *popped = s.items[s.top--];
    }
    return s;
}

// Function to return top element without popping
char peek(Stack s) {
    return (s.top == -1) ? '\0' : s.items[s.top];
}

// Function to determine operator precedence
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': case '%': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

// Function to convert infix to postfix
char *infixToPostfix(char infix[]) {
    static char postfix[MAX];
    Stack s = { .top = -1 };
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];  // Operand goes to output
        } 
        else if (infix[i] == '(') {
            s = push(s, infix[i]);  // Push '(' onto stack
        } 
        else if (infix[i] == ')') {
            char popped;
            while (s.top != -1 && peek(s) != '(') {
                s = pop(s, &popped);
                postfix[j++] = popped;
            }
            s = pop(s, &popped);  // Remove '('
        } 
        else if (isOperator(infix[i])) {
            while (s.top != -1 && precedence(peek(s)) >= precedence(infix[i]) && infix[i] != '^') {
                char popped;
                s = pop(s, &popped);
                postfix[j++] = popped;
            }
            s = push(s, infix[i]);
        }
        i++;
    }
    
    while (s.top != -1) {
        char popped;
        s = pop(s, &popped);
        postfix[j++] = popped;
    }
    
    postfix[j] = '\0';  // Null terminate postfix expression
    return postfix;
}

// Function to push to operand stack
OperandStack pushOperand(OperandStack s, double value) {
    if (s.top == MAX - 1) {
        printf("Stack Overflow!\n");
        return s;
    }
    s.items[++(s.top)] = value;
    return s;
}

// Function to pop from operand stack
OperandStack popOperand(OperandStack s, double *popped) {
    if (s.top == -1) {
        printf("Invalid Expression\n");
        exit(1);
    }
    *popped = s.items[s.top--];
    return s;
}

// Function to evaluate a postfix expression
double evaluatePostfix(char postfix[]) {
    OperandStack s = { .top = -1 };
    int i = 0;
    double op1, op2, result;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            s = pushOperand(s, postfix[i] - '0');  // Convert char to int
        } 
        else if (isOperator(postfix[i])) {
            s = popOperand(s, &op2);
            s = popOperand(s, &op1);

            switch (postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = (int)op1 % (int)op2; break;
                case '^': result = pow(op1, op2); break;
                default: printf("Invalid Operator!\n"); exit(1);
            }
            s = pushOperand(s, result);
        }
        i++;
    }
    s = popOperand(s, &result);  // Final result
    return result;
}

// Menu-driven program
int main() {
    int choice;
    char infix[MAX], postfix[MAX];
    double result;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Convert Infix to Postfix\n");
        printf("2. Evaluate Postfix Expression\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%[^\n]%*c", infix);
                strcpy(postfix, infixToPostfix(infix));
                printf("Postfix expression: %s\n", postfix);
                break;
            
            case 2:
                printf("Enter postfix expression: ");
                scanf("%[^\n]%*c", postfix);
                result = evaluatePostfix(postfix);
                printf("Evaluated Result: %.2f\n", result);
                break;
            
            case 3:
                printf("Exiting...\n");
                return 0;
            
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}