/*Write a program that uses functions to perform the following operations on a singly linked list
1.Insertion 2. Deletion 3.Traversal

Input format:
The first line of input contains the number of operations to be performed on the single linked list
The next lines contain the integers separated by space in which the first integer indicates the 
operation to be performed and the second integer contains the element to be inserted or deleted.
    1 ---> indicates the insertion
    2---> indicates the deletion
Output format:
Display the elements of the single linked list after performing the traversal operation. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node *NODE;

NODE createNode(int value) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\n No memory is allocated for the new node\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

NODE insertNodeAtTheEnd(NODE head, int value) {
    NODE tempNode = head;
    NODE newNode = createNode(value);
    if (newNode == NULL) {
        printf("Not able to add the new node\n");
    }
    if (head == NULL) {
        head = newNode;
        return head;
    }
    if (newNode != NULL) {
        while (tempNode->next != NULL) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }
    return head;
}

NODE deleteNode(NODE head, int value) {
    NODE tempNode = head;
    NODE prev = NULL;

    if (tempNode != NULL && tempNode->data == value) {
        head = tempNode->next;
        free(tempNode);
        return head;
    }

    while (tempNode != NULL && tempNode->data != value) {
        prev = tempNode;
        tempNode = tempNode->next;
    }

    if (tempNode == NULL) return head;

    prev->next = tempNode->next;
    free(tempNode);
    return head;
}

void displaySingleLinkedList(NODE head) {
    NODE tempNode = head;
    while (tempNode != NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    NODE head = NULL;
    int n, operation, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &operation, &value);
        if (operation == 1) {
            head = insertNodeAtTheEnd(head, value);
        } else if (operation == 2) {
            head = deleteNode(head, value);
        }
    }

    displaySingleLinkedList(head);

    return 0;
}

