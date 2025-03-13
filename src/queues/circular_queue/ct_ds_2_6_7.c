#include <stdlib.h>
#include <stdio.h>

struct queue {
	int data;
	struct queue *next;
};
typedef struct queue *CircularQueue;
CircularQueue front = NULL, rear = NULL;

//complete the below dequeue() and enqueue() functions
void dequeue() {
	if (front == NULL) {
        printf("Circular queue is underflow.\n");
    } else {
        CircularQueue temp = front;
        int deletedValue = front->data;
        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            rear->next = front;
        }
        free(temp);
        printf("Deleted value = %d\n", deletedValue);
    }
}

void size() {
	int count =0;
	if(front == NULL) {
		printf("Circular queue size : 0\n"); 
		return;
	} 
	CircularQueue temp = front;
	do {
		temp = temp -> next;
		count = count + 1;
	} while(temp != front);
	printf("Circular queue size : %d\n",count);
}

void isEmpty() {
	if(front == NULL ) {
		printf("Circular queue is empty.\n");
	} else {
		printf("Circular queue is not empty.\n");
	}
}

void enqueue(int element) {
	 CircularQueue temp = (CircularQueue)malloc(sizeof(struct queue));
    if (temp == NULL) {
        printf("Circular queue is overflow.\n");
        return;
    }
    temp->data = element;
    temp->next = NULL;
    if (front == NULL) {
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    rear->next = front;
    printf("Successfully inserted.\n");
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