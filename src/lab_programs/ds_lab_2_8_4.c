#include <stdlib.h>
#include <stdio.h>
#define MAX 10 // Define MAX as 10

int queue[MAX]; // Declare queue array of size MAX
int front = -1, rear = -1; // Define front and rear to -1

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue is overflow.\n");
        return;
    }    
    queue[++rear] = x;
    printf("Successfully inserted.\n");
}

void dequeue() {
    if (front == rear) {
        printf("Queue is underflow.\n");
        return;
    }
    printf("Deleted element = %d\n", queue[++front]);
    if (front == rear) {
        front = rear = -1; // Reset queue when empty
    }
}

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

void size() {
    if (front == rear) {
        printf("Queue size : 0\n");
        return;
    }
    printf("Queue size : %d\n", rear - front);
}

void isEmpty() {
    if (front == rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
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