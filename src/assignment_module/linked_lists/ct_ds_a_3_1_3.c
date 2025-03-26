#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

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

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to remove duplicates from an unsorted linked list
void removeDuplicates(struct Node* head) {
    if (head == NULL) {
        return;
    }

    bool hashTable[MAX] = {false};
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (hashTable[current->data]) {
            prev->next = current->next;
            free(current);
        } else {
            hashTable[current->data] = true;
            prev = current;
        }
        current = prev->next;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver function
int main() {
    struct Node* head = NULL;
    int N, data;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &data);
        insertNode(&head, data);
    }
    removeDuplicates(head);
    printList(head);

    return 0;
}