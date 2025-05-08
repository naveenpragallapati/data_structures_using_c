#include <stdio.h>
#include <stdlib.h>

// Define Node and PQNODE
struct Node {
    char data;
    int priority;
    struct Node* next;
};
typedef struct Node* PQNODE;

// Global head pointer
PQNODE head = NULL;

// Create a new node
PQNODE createNode(char x, int p) {
    PQNODE newNode = (PQNODE)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->priority = p;
    newNode->next = NULL;
    return newNode;
}

// Insert an element into the priority queue
void enqueue(char x, int p) {
    PQNODE newNode = createNode(x, p);

    if (head == NULL) {        
        head = newNode;
    } else {
        PQNODE temp = head;
        PQNODE prev = NULL;
        // Find the correct position for the new node
        while (temp != NULL && newNode->priority >= temp->priority) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL) {
            // Insert at the head
            newNode->next = head;
            head = newNode;
        } else {
            // Insert in the middle or at the end
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    printf("Inserted: %c (Priority: %d)\n", x, p);
}

/*Insert an element into the priority queue without using prev pointer
void enqueue(char x, int p) {
    PQNODE newNode = createNode(x, p);

    // If the queue is empty or the new node has the highest priority
    if (head == NULL || newNode->priority < head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        // Traverse the list to find the correct position
        PQNODE temp = head;
        while (temp->next != NULL && temp->next->priority <= newNode->priority) {
            temp = temp->next;
        }
        // Insert the new node
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Inserted: %c (Priority: %d)\n", x, p);
}
*/

// Delete the element with the highest priority
void dequeue() {
    if (head == NULL) {
        printf("Underflow: Priority Queue is empty.\n");
        return;
    }

    PQNODE temp = head;
    printf("Deleted: %c (Priority: %d)\n", temp->data, temp->priority);
    head = head->next;
    free(temp);
}

// Display the queue
void display() {
    if (head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }

    PQNODE temp = head;
    printf("Priority Queue (data | PRIORITY):\n");
    while (temp != NULL) {
        printf("%c | %d -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Return size of the queue
int size() {
    int count = 0;
    PQNODE current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Check if queue is empty
int isEmpty() {
    return head == NULL;
}

// Main menu
int main() {
    int choice, priority;
    char data;
    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Size\n");
        printf("5. Is Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%c", &data);
                getchar();  // consume newline
                printf("Enter priority (lower = higher priority): ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Queue Size: %d\n", size());
                break;

            case 5:
                if (isEmpty())
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
// Compile with: gcc -o pq_ll pq_ll.c
// Run with: ./pq_ll