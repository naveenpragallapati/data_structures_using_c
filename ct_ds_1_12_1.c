// Write complete code here
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert at the beginning
void insert_at_beginning(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    printf("Given linked list: ");
    while (temp) {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
}

// Function to count occurrences of a key
int count_occurrences(Node* head, int key) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main() {
    int N, key;
    scanf("%d", &N);
    Node* head = NULL;
    
    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        insert_at_beginning(&head, value);
    }
    
    display(head);
    
    scanf("%d", &key);
    printf("%d\n", count_occurrences(head, key));
    
    return 0;
}