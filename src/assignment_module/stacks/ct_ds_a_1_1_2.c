#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ExtraBrackets(const char *exp) {
    char stack[100]; // Stack to hold characters
    int top = -1;    // Stack pointer

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == ')') {
            if (top == -1) {
                return true; // Unmatched closing bracket
            }
            bool hasOperator = false;
            while (top != -1 && stack[top] != '(') {
                char topChar = stack[top--];
                if (topChar == '+' || topChar == '-' || topChar == '*' || topChar == '/') {
                    hasOperator = true;
                }
            }
            if (top == -1) {
                return true; // Unmatched closing bracket
            }
            top--; // Pop the matching '('
            if (!hasOperator) {
                return true; // Extra brackets found
            }
        } else {
            stack[++top] = exp[i]; // Push character onto stack
        }
    }
    return false;
}

int main() {
    char exp[100]; // Buffer to hold the input expression
    scanf("%[^\n]", exp); // Read until newline
    if (ExtraBrackets(exp)) {
        printf("true");  // Output: true if there are extra brackets
    } else {
        printf("false"); // Output: false if there are no extra brackets
    }
    return 0;
}