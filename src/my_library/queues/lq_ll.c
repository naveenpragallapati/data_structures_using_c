#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node* Q;

Q front = NULL;
Q rear = NULL;

// Function to create a new node
Q createNode(int data) {
    Q newNode = (Q)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an element to the queue
void enqueue(int data) {
    Q newNode = createNode(data);
    if (rear == NULL) {
        front = rear = newNode;
        printf("Inserted %d into queue.\n", data);
        return;
    }
    rear->next = newNode;
    rear = newNode;
    printf("Inserted %d into queue.\n", data);
}

// Function to remove an element from the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Q temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    printf("Removed %d from queue.\n", temp->data);
    free(temp);
}

// Function to display elements of the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Q temp = front;
    printf("Elements in the queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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