#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
	if (((rear == MAX - 1) && (front == 0)) || (rear + 1 == front)) {
		printf("Circular queue is overflow.\n");
	} else {
		if (rear == MAX - 1) {
			rear = -1;
		} else if (front == -1) {
			front = 0;
		}
		rear++;
		queue[rear] = x;
		printf("Successfully inserted.\n");
	}
}
void display() {
	int i;
	if (front == -1 && rear == -1) {
		printf("Circular queue is empty.\n");
	} else {
		printf("Elements in the circular queue : ");
		if (front <= rear) {
			for (i = front; i <= rear; i++) {
				printf("%d ", queue[i]);
			}
		} else {
			for (i = front; i <= MAX - 1; i++) {
				printf("%d ", queue[i]);
			}
			for (i = 0; i <= rear; i++) {
				printf("%d ", queue[i]);
			}
		}
		printf("\n");
	}
}
int main() {
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Display 3.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1: printf("Enter element : ");
				scanf("%d", &x);
				enqueue(x);
				break;
			case 2: display();
				break;
			case 3: exit(0);
		}
	}
}