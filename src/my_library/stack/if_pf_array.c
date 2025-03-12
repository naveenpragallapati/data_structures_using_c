#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

// Function prototypes
int precedence(char op);
int isOperator(char ch);
char *infixToPostfix(char infix[]);
double evaluatePostfix(char postfix[]);

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

// Function to convert infix to postfix using array-based stack
char *infixToPostfix(char infix[]) {
    static char postfix[MAX];
    char stack[MAX];
    int top = -1;
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];  // Operand goes to output
        } 
        else if (infix[i] == '(') {
            stack[++top] = infix[i];  // Push '(' onto stack
        } 
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];  // Pop till '(' is found
            }
            top--;  // Remove '('
        } 
        else if (isOperator(infix[i])) {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top]) && infix[i] != '^') {
                postfix[j++] = stack[top--];  // Pop operators with higher precedence
            }
            stack[++top] = infix[i];  // Push current operator
        }
        i++;
    }
    
    while (top != -1) {
        postfix[j++] = stack[top--];  // Pop remaining operators
    }
    
    postfix[j] = '\0';  // Null terminate postfix expression
    return postfix;
}

// Function to evaluate a postfix expression using array-based stack
double evaluatePostfix(char postfix[]) {
    double stack[MAX];
    int top = -1;
    int i = 0;
    double op1, op2, result;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            stack[++top] = postfix[i] - '0';  // Convert char to int
        } 
        else if (isOperator(postfix[i])) {
            op2 = stack[top--];
            op1 = stack[top--];

            switch (postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = (int)op1 % (int)op2; break;
                case '^': result = pow(op1, op2); break;
                default: printf("Invalid Operator!\n"); exit(1);
            }
            stack[++top] = result;  // Push result back
        }
        i++;
    }
    return stack[top];  // Final result
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
