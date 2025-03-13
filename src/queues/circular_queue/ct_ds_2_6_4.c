#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void dequeue() {
    if (front == -1) {
        printf("Circular queue is underflow.\n");
    } else {
        printf("Deleted element = %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void isEmpty() {
    if (front == -1)
        printf("Circular queue is empty.\n");
    else
        printf("Circular queue is not empty.\n");
}

void size() {
    if (front == -1) {
        printf("Circular queue size : 0\n");
    } else if (front <= rear) {
        printf("Circular queue size : %d\n", rear - front + 1);
    } else {
        printf("Circular queue size : %d\n", (MAX - front) + (rear + 1));
    }
}

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
		printf("1.Enqueue 2.Dequeue 3.Display 4.Is empty 5.Size 6.Exit\n");
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