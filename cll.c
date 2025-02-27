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
    newNode->next = newNode; // Point to itself to make it circular
    return newNode;
}

void displayCircularLinkedList(NODE head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    NODE tempNode = head;
    do {
        printf("%d --> ", tempNode->data);
        tempNode = tempNode->next;
    } while (tempNode != head);
    printf("HEAD\n");
}

int displayCount(NODE head) {
    if (head == NULL) return 0;
    NODE tempNode = head;
    int count = 0;
    do {
        count++;
        tempNode = tempNode->next;
    } while (tempNode != head);
    return count;
}

int searchElement(NODE head, int value) {
    if (head == NULL) return -1;
    NODE tempNode = head;
    int position = 1;
    do {
        if (tempNode->data == value) {
            printf("\n The element %d is found at position %d\n", value, position);
            return position;
        }
        position++;
        tempNode = tempNode->next;
    } while (tempNode != head);
    printf("\n The element %d is not found in the linked list\n", value);
    return -1;
}

NODE insertNodeAtTheEnd(NODE head, int value) {
    NODE newNode = createNode(value);
    if (newNode == NULL) {
        printf("Not able to add the new node\n");
        return head;
    }
    if (head == NULL) {
        return newNode;
    }
    NODE tempNode = head;
    while (tempNode->next != head) {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
    newNode->next = head;
    return head;
}

NODE deleteNodeAtTheEnd(NODE head) {
    if (head == NULL) {
        printf("\n The linked list is empty\n");
        return head;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    NODE tempNode = head;
    NODE prevNode = NULL;
    while (tempNode->next != head) {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    prevNode->next = head;
    free(tempNode);
    return head;
}

NODE insertNodeAtTheBeginning(NODE head, int value) {
    NODE newNode = createNode(value);
    if (newNode == NULL) {
        printf("Not able to add the new node\n");
        return head;
    }
    if (head == NULL) {
        return newNode;
    }
    NODE tempNode = head;
    while (tempNode->next != head) {
        tempNode = tempNode->next;
    }
    newNode->next = head;
    tempNode->next = newNode;
    return newNode;
}

NODE deleteNodeAtTheBeginning(NODE head) {
    if (head == NULL) {
        printf("\n The linked list is empty\n");
        return head;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    NODE tempNode = head;
    while (tempNode->next != head) {
        tempNode = tempNode->next;
    }
    NODE newHead = head->next;
    tempNode->next = newHead;
    free(head);
    return newHead;
}

NODE insertNodeAtSpecifiedPosition(NODE head, int value, int position) {
    int node_count = displayCount(head);
    NODE newNode = createNode(value);
    if (newNode == NULL) {
        printf("Not able to add the new node\n");
        return head;
    }
    if (position > node_count + 1 || position <= 0) {
        printf("\n The position is out of range\n");
        free(newNode);
        return head;
    }
    if (position == 1) {
        return insertNodeAtTheBeginning(head, value);
    }
    NODE tempNode = head;
    for (int i = 1; i < position - 1; i++) {
        tempNode = tempNode->next;
    }
    newNode->next = tempNode->next;
    tempNode->next = newNode;
    return head;
}

NODE deleteNodeAtSpecifiedPosition(NODE head, int position) {
    if (head == NULL) {
        printf("\n The linked list is empty\n");
        return head;
    }
    int node_count = displayCount(head);
    if (position > node_count || position <= 0) {
        printf("\n The position is out of range\n");
        return head;
    }
    if (position == 1) {
        return deleteNodeAtTheBeginning(head);
    }
    NODE tempNode = head;
    for (int i = 1; i < position - 1; i++) {
        tempNode = tempNode->next;
    }
    NODE nodeToDelete = tempNode->next;
    tempNode->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

NODE reverseCircularLinkedList(NODE head) {
    if (head == NULL || head->next == head) {
        return head;
    }
    NODE prevNode = NULL;
    NODE currentNode = head;
    NODE nextNode = NULL;
    do {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    } while (currentNode != head);
    head->next = prevNode;
    head = prevNode;
    return head;
}

int main() {
    int choice, node_value, position, count;
    NODE head = NULL;
    printf("\n\n Circular Linked List Operations\n");

    printf("\n\n 1. Display CLL\n 2. Display Count\n 3. Search for an element\n 4. Insert a node at the end\n 5. Insert a node at the beginning\n 6. Insert at a specified position\n ");
    printf("7. Delete a node at the end \n 8. Delete a node at the beginning\n 9. Delete a node at a specified position\n 10. Reverse the Circular Linked List\n 11. Exit\n");
    printf("\n Enter your choice : ");
    scanf("%d", &choice);

    while (choice != 11) {
        switch (choice) {
            case 1:
                printf("\n The updated Circular Linked List is :\n");
                displayCircularLinkedList(head);
                break;
            case 2:
                printf("\n The count of the nodes in the Circular Linked List is : ");
                count = displayCount(head);
                printf("%d\n", count);
                break;
            case 3:
                printf("\n Enter the element to be searched: ");
                scanf("%d", &node_value);
                position = searchElement(head, node_value);
                break;
            case 4:
                printf("\nEnter the node value : ");
                scanf("%d", &node_value);
                head = insertNodeAtTheEnd(head, node_value);
                displayCircularLinkedList(head);
                break;
            case 5:
                printf("\n Enter the node value: ");
                scanf("%d", &node_value);
                head = insertNodeAtTheBeginning(head, node_value);
                displayCircularLinkedList(head);
                break;
            case 6:
                printf("\n Enter the node value: ");
                scanf("%d", &node_value);
                printf("\n Enter the position: ");
                scanf("%d", &position);
                head = insertNodeAtSpecifiedPosition(head, node_value, position);
                displayCircularLinkedList(head);
                break;
            case 7:
                head = deleteNodeAtTheEnd(head);
                displayCircularLinkedList(head);
                break;
            case 8:
                head = deleteNodeAtTheBeginning(head);
                displayCircularLinkedList(head);
                break;
            case 9:
                printf("\n Enter the position of the node to be deleted: ");
                scanf("%d", &position);
                head = deleteNodeAtSpecifiedPosition(head, position);
                displayCircularLinkedList(head);
                break;
            case 10:
                head = reverseCircularLinkedList(head);
                displayCircularLinkedList(head);
                break;
            case 11:
                printf("\n Exiting the program\n");
                break;
            default:
                printf("\n Wrong selection of choice\n");
                break;
        }
        printf("\n\n 1. Display CLL\n 2. Display Count\n 3. Search for an element\n 4. Insert a node at the end\n 5. Insert a node at the beginning\n 6. Insert at a specified position\n ");
        printf("7. Delete a node at the end \n 8. Delete a node at the beginning\n 9. Delete a node at a specified position\n 10. Reverse the Circular Linked List\n 11. Exit\n");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
    }
    return 0;
}