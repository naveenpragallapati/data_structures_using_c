#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Node structure to represent a date in the doubly linked list
struct Node {
    char dateInfo[50];
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new date node at the end of the doubly linked list
struct Node* insertDate(struct Node* head, char dateInfo[]) {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->dateInfo, dateInfo);
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    
    return head;
    
}

// Function to delete the middle element(s) from the doubly linked list
struct Node* deleteMiddleElements(struct Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    struct Node* slow = head;
    struct Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    struct Node* middle = slow;
    if (middle->prev != NULL) {
        middle->prev->next = middle->next;
    }
    if (middle->next != NULL) {
        middle->next->prev = middle->prev;
    }
    
    if (middle == head) {
        head = middle->next;
    }
    
    free(middle);
    return head;
    
}

// Function to print the doubly linked list representing the important dates
void printImportantDates(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->dateInfo);
        temp = temp->next;
    }
    printf("NULL\n");    
}

int main() {
    int totalDates;
    scanf("%d", &totalDates);
    struct Node* importantDates = NULL;

    for (int i = 0; i < totalDates; ++i) {
        char dateInfo[50];
        scanf("%s", dateInfo);
        importantDates = insertDate(importantDates, dateInfo);
    }

    printImportantDates(importantDates);
    importantDates = deleteMiddleElements(importantDates);
    printf("After Deletion:\n");
    printImportantDates(importantDates);

    return 0;
}
