#include <stdio.h>
#include <stdlib.h>
struct stack {
	int data;
	struct stack *next;
};

typedef struct stack *stk;
stk top = NULL;

// Check if stack is empty
int isEmpty() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
    return top == NULL;
}

// Push operation
void push(int x) {
    stk newNode = (stk)malloc(sizeof(struct stack));
    if (!newNode) {
        printf("Memory Allocation Failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("Successfully pushed.\n");
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack is underflow.\n");
        return -1;
    }
    int data = top->data;
    stk temp = top;
    top = top->next;
    free(temp);
    printf("Popped value = %d\n", data);
    return data;
}

// Peek operation
int peek() {
    if (top == NULL) {
        printf("Stack is underflow.\n");
        return -1;
    }
    printf("Peek value = %d\n", top->data);
    return top->data;
}

void display() {
	stk temp = top;
	if(temp == NULL) {
		printf("Stack is empty.\n"); 
	} else {
		printf("Elements of the stack are : ");
		while(temp != NULL) {
			printf("%d ", temp -> data);
			temp = temp -> next;
		}
		printf("\n");
	}
}


int main() {
	int op, x;
	while(1) {	
		printf("1.Push 2.Pop 3.Display 4.Is Empty 5.Peek 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d", &x);
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				peek();
				break;
			case 6: 
				exit(0);
		}
	}
}