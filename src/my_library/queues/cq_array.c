#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define max size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue overflow.\n");
        return;
    }
    if (front == -1) {  // Insert first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    printf("Inserted %d into queue.\n", value);
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1) {
        printf("Queue underflow.\n");
        return;
    }
    printf("Removed %d from queue.\n", queue[front]);
    if (front == rear) {  // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Function to display elements of the queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}