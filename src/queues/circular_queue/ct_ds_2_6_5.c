#include <stdlib.h>
#include <stdio.h>

struct queue {
	int data;
	struct queue *next;
};

typedef struct queue *CircularQueue;
CircularQueue front = NULL, rear = NULL;

void enqueue(int element) {
	CircularQueue temp = NULL;
	temp = (CircularQueue)malloc(sizeof(struct queue));
	if(temp == NULL) {
		printf("Circular queue is overflow.\n");
	} else {
		temp -> data = element;
		temp -> next = NULL;
		if(front == NULL) {
			front = temp;
		} else {
			rear -> next = temp;
		}
		rear = temp;
		rear -> next = front;
		printf("Successfully inserted.\n");
	}
}

void display() {
	if(front == NULL) {
		printf("Circular queue is empty.\n"); 
	} else {
		CircularQueue temp = front;
		printf("Elements in the circular queue : ");
		do {
			printf("%d ", temp -> data);
			temp = temp -> next;
		} while(temp != front);
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