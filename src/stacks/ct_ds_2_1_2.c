#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 10

int arr[STACK_MAX_SIZE];
int top = -1;

void push(int element) {
    if (top < STACK_MAX_SIZE - 1) {
        arr[++top] = element;
        printf("Successfully pushed.\n");
    } else {
        printf("stack overflow.\n");
    }
}

void display() {
    if (top >= 0) {
        printf("Elements of the stack are :");
        for (int i = top; i >= 0; i--) {
            printf(" %d", arr[i]);
        }
		printf(" \n");
    } else {
        printf("Stack is empty.\n");
    }
}

int main() {
	int op, x;
	while(1) {	
		printf("1.Push 2.Display 3.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d", &x);
				push(x);
				break;
			case 2: 
				display();
				break;
			case 3: 
				exit(0);
		}
	}
}