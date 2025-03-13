#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define STACK_MAX_SIZE 20
char stack [STACK_MAX_SIZE];
int top = -1;

//Return 1 if stack is empty else return 0.
int isEmpty() {
	return top == -1;
}

//Push the character into stack
void push(char x) {
	 if (top < STACK_MAX_SIZE - 1) {
        stack[++top] = x;
    }
}

//pop a character from stack
char pop() {
	if (!isEmpty()) {
        return stack[top--];
    }
    return '#'; // Return a dummy character if stack is empty	
}

// Return 0 if char is '('
// Return 1 if char is '+' or '-'
// Return 2 if char is '*' or '/' or '%'
int priority(char x) {
	 if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/' || x == '%') return 2;
    return -1; // Invalid operator	
}

//Output Format
//if expression is correct then output will be Postfix Expression : <postfix notation>
//If expression contains invalid operators then output will be "Invalid symbols in infix expression. Only alphanumberic and { '+', '-','*', '%%', '/' } are allowed."
//If the expression contains unbalanced paranthesis the output will be "Invalid infix expression : unbalanced parenthesis."
void convertInfix(char * e) {
    char postfix[STACK_MAX_SIZE];
    int i = 0, j = 0, balanced = 0;

    while (*e) {
        if (isalnum(*e)) {
            postfix[j++] = *e;
        } else if (*e == '(') {
            push(*e);
            balanced++;
        } else if (*e == ')') {
            balanced--;
            while (!isEmpty() && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (isEmpty()) {
                printf("Invalid infix expression : unbalanced parenthesis.\n");
                return;
            }
            pop();
        } else if (strchr("+-*/%", *e)) {
            while (!isEmpty() && priority(stack[top]) >= priority(*e)) {
                postfix[j++] = pop();
            }
            push(*e);
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

    if (balanced != 0) {
        printf("Invalid infix expression : unbalanced parenthesis.\n");
        return;
    }

    postfix[j] = '\0';
    printf("Postfix expression : %s\n", postfix);    
}


int main() {
	char expr[20];
	char *e, x;
	printf("Enter the expression : ");
	scanf("%s",expr);
	e = expr;
	convertInfix(e);
	return 0;
}