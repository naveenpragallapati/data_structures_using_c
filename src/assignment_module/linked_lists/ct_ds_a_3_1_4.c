#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to exchange the first and last node
struct Node* exchangeNodes(struct Node* head) {
if (head == NULL || head->next == NULL) {
        return head; // No exchange needed if list is empty or has only one node
    }

    struct Node* prev = NULL;
    struct Node* current = head;

    // Traverse to the last node
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    // Exchange the first and last nodes
    current->next = head->next;
    prev->next = head;
    head->next = NULL;
    head = current;

    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" "); 
        }
        temp = temp->next;
    }
    printf("\n");
}

// Driver function
int main() {
    int N, value;
    struct Node* head = NULL;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    head = exchangeNodes(head);
    printList(head);

    return 0;
}
