#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a circular linked list based on the given keys
struct Node* createCircularLinkedList(int keys[], int n) {    
    if (n == 0) return NULL;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = keys[0];
    head->next = head; // Circular reference
    struct Node* last = head;

    for (int i = 1; i < n; i++) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = keys[i];
        temp->next = head; // Point back to the head

        last->next = temp; // Link previous node to new node
        last = temp; // Update last node
    }
    return head;    
}

// Function to search for a key in the circular linked list
int searchKey(struct Node* head, int key) {
    if (head == NULL) return -1;

    struct Node* current = head;
    int index = 0;

    do {
        if (current->data == key) {
            return index; // Key found
        }
        current = current->next;
        index++;
    } while (current != head); // Stop when we complete a full cycle

    return -1; // Key not found
}

int main() {
    int n;
    scanf("%d", &n);

    int keys[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    int keyToFind;
    scanf("%d", &keyToFind);

    struct Node* circularList = createCircularLinkedList(keys, n);
    int result = searchKey(circularList, keyToFind);

    if (result != -1) {
        printf("Index: %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
