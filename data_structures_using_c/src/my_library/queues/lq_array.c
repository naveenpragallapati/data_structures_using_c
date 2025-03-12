#include <stdio.h>
#define MAX 5  // Define max size of the queue

int queue[MAX];  // Declare queue array
int front = -1, rear = -1;  // Initialize front and rear

// Function to insert an element into the queue
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue overflow.\n");
        return;
    }    
    queue[++rear] = x;
    printf("Inserted %d into queue.\n", x);
}

// Function to remove an element from the queue
void dequeue() {
    if (front == rear) {  // Empty condition
        printf("Queue underflow.\n");
        return;
    }
    printf("Removed %d from queue.\n", queue[++front]);
    // Move front forward
    if (front == rear) {  // Reset when queue becomes empty
        front = -1;
        rear = -1;
    }
}

// Function to display elements of the queue
void display() {
    if (front == rear) {  // Empty condition
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue: ");
    for (int i = front + 1; i <= rear; i++) {
        printf("%d ", queue[i]);
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
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}