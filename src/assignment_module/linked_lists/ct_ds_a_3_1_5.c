#include <stdio.h>
#include <stdlib.h>

// Structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} *NODE;

// Function to create a new node
NODE createNode(int data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse a linked list
NODE reverseList(NODE head) {
    NODE prev = NULL, curr = head, next = NULL;
    
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to create a linked list from an array
NODE createLinkedList(int arr[], int size) {
    if (size == 0) return NULL;

    NODE head = createNode(arr[0]), temp = head;
    
    for (int i = 1; i < size; i++) {
        temp->next = createNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(NODE head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to add two numbers represented as linked lists
NODE addTwoLists(NODE l1, NODE l2) {
    // Reverse both lists
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    NODE dummy = createNode(0), temp = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        temp->next = createNode(sum % 10);
        temp = temp->next;
    }

    // Reverse the result before returning
    return reverseList(dummy->next);
}

// Main function
int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int arr1[N], arr2[M];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &arr2[i]);
    }

    NODE l1 = createLinkedList(arr1, N);
    NODE l2 = createLinkedList(arr2, M);
    NODE result = addTwoLists(l1, l2);

    printLinkedList(result);

    return 0;
}
