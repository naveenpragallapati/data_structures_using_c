#include <stdlib.h>
#include <stdio.h>

#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

// Function to remove an element from the queue
void dequeue() {
    if (front == rear) {
        printf("Queue is underflow.\n");
        return;
    }
	front++;
    printf("Deleted element = %d\n", queue[front]);    
    if (front == rear) front = rear = -1; // Reset queue if empty
}

// Function to check if the queue is empty
void isEmpty() {
    if (front == rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

// Function to get the size of the queue
void size() {
    if (front == rear) {
        printf("Queue size : 0\n");
    } else {
        printf("Queue size : %d\n", (rear - front));
    }
}

void enqueue(int x) {
	if (rear == MAX - 1) {
		printf("Queue is overflow.\n");
	} else {
		rear++;
		queue[rear] = x;
		printf("Successfully inserted.\n");
	}
}

void display() {
	if (front == rear) {
		printf("Queue is empty.\n");
	} else {
		printf("Elements in the queue : ");
		for (int i = front+1; i <= rear; i++) {
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
}
int main() {
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Is Empty 5.Size 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2: 
				dequeue();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				size();
				break;
			case 6: exit(0);
		}
	}
}