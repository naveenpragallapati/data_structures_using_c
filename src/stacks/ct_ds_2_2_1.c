#include <stdio.h>
#include <stdlib.h>

struct stack {
	int data;
	struct stack *next;
};
typedef struct stack *stk;
stk top = NULL;

stk push(int x) {
	stk newNode = (stk)malloc(sizeof(struct stack));
	if (newNode==NULL){
		printf("Stack is overflow.\n");
		return top;
	}
	else{
		newNode->data = x;
		newNode->next = top;
		top = newNode;
		printf("Successfully pushed.\n");
		return top;
	}
	return top;
}


void display() {
	if(top==NULL){
		printf("Stack is empty.\n");
		return;
	}
	printf("Elements of the stack are :");
	stk temp = top;
	while(temp!=NULL){
		printf(" %d",temp->data);
		temp=temp->next;
	}
	printf(" \n");
	return;
}


int main() {
	int op, x;
	while(1) {	
	printf("1.Push 2.Display 3.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d",&x);
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
