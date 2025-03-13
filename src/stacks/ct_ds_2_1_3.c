#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_MAX_SIZE 10

int arr[STACK_MAX_SIZE];
int top = -1;

void pop() {
	if (top >= 0) {
		printf("Popped value = %d\n", arr[top]);
		top = top - 1;
	} else {
		printf("Stack is underflow.\n");
	}
}

void peek() {
	if (top >= 0) {
		printf("Peek value = %d\n", arr[top]);
	} else {
		printf("Stack is underflow.\n");
	}
}

void isEmpty() {
	if (top >= 0) {
		printf("Stack is not empty.\n");
	} else {
		printf("Stack is empty.\n");
	}
}

void push(int element) {
	if (top == STACK_MAX_SIZE - 1) {
		printf("Stack is overflow.\n");
	} else {
		top = top + 1;
		arr[top] = element;
		printf("Successfully pushed.\n");
	}
}

void display() {
	if (top < 0) {
		printf("Stack is empty.\n");
	} else {
		printf("Elements of the stack are : ");
		for (int i = top; i >= 0; i--) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}

int main() {
	int op, x;
	while(1) {	
		printf("1.Push 2.Pop 3.Display 4.Is Empty 5.Peek 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
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