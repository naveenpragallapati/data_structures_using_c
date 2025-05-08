#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int ticket_id;
    int severity;
    struct Node* next;
};

struct Node* front = NULL;

// Enqueue based on priority (lower severity = higher priority)
void enqueue(int ticket_id, int severity) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->ticket_id = ticket_id;
    temp->severity = severity;
    temp->next = NULL;

    // If queue is empty or new node has higher priority than front
    if (front == NULL || severity < front->severity) {
        temp->next = front;
        front = temp;
    } else {
        // Find the correct position
        struct Node* curr = front;
        while (curr->next != NULL && curr->next->severity <= severity) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

// Display the queue
void display() {
    struct Node* curr = front;
    while (curr != NULL) {
        printf("%d (%d) ", curr->ticket_id, curr->severity);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int op, x, p;
    while (1) {
        scanf("%d", &op);
        switch (op) {
            case 1:
                scanf("%d %d", &x, &p);
                enqueue(x, p);
                break;
            case 2:
                display();
                break;
        }
        if(op == 2) {
            break;
        }
    }
    return 0; 
}
// This program implements a priority queue using a linked list. It allows the user to enqueue tickets with a severity level and display the queue. The tickets are sorted based on their severity, with lower severity values indicating higher priority.