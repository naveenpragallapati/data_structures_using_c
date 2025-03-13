#include <stdlib.h>
#include <stdio.h>
#define MAX 100  // Define maximum size of the queue

int queue[MAX]; // Declare queue array
int front = -1, rear = -1; // Initialize front and rear

// Function to insert an element into the queue
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue is overflow.\n");
        return;
    }   
    queue[++rear] = x;
    printf("Successfully inserted.\n");
}
// Function to display elements of the queue
void display() {
    if (front == rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue : ");
    for (int i = front+1; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
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
			case 2: display();
				break;
			case 3: exit(0);
		}
	}
}