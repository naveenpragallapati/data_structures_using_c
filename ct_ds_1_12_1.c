#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node *NODE;

// Function to insert at the beginning
NODE insert_at_beginning(NODE head, int data) {
    NODE new_node = (NODE)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to display the linked list
void display(NODE head) {
    NODE temp = head;
    printf("Given linked list: ");
    while (temp) {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
}

// Function to count occurrences of a key
int count_occurrences(NODE head, int key) {
    int count = 0;
    NODE temp = head;
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
    NODE head = NULL;
    
    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        head = insert_at_beginning(head, value);
    }
    
    display(head);
    
    scanf("%d", &key);
    printf("%d\n", count_occurrences(head, key));
    
    return 0;
}