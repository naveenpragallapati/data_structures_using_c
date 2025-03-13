#include <stdlib.h>
#include <stdio.h>

struct queue {
	int data;
	struct queue *next;
};

typedef struct queue *Q;
Q front = NULL, rear = NULL;

void enqueue(int element) {
	Q temp = NULL;
	temp = (Q)malloc(sizeof(struct queue));
	if(temp == NULL) {
		printf("Queue is overflow.\n");
	} else {
		temp -> data = element;
		temp -> next = NULL;
		
		if(front == NULL) {
			front = temp;
		} else {
			rear -> next = temp;
		}
		rear = temp;
		printf("Successfully inserted.\n");
	}
}

void display() {
	if(front == NULL) {
		printf("Queue is empty.\n"); 
	} else {
		Q temp = front;
		printf("Elements in the queue : ");
		while(temp  != NULL) {
			printf("%d ", temp -> data );
			temp = temp -> next;
		}
		printf("\n");
	}
}

int main() {
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Display 3.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2: 
				display();
				break;
			case 3: 
				exit(0);
		}
	}
}