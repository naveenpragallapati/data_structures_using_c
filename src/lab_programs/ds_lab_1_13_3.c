/*Write a C program that uses functions to perform the following operations on double linked list
i) Creation  ii) Insertion  iii) Deletion  iv) Traversal*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
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
    newNode->prev = NULL;
    return newNode;
}

void displayDoublyLinkedList(NODE head) {
    NODE tempNode = head;
    while (tempNode != NULL) {
        printf("%d\t", tempNode->data);
        tempNode = tempNode->next;
    }
	printf("\n");
}

NODE insertNodeAtTheEnd(NODE head, int value) {
    NODE tempNode = head;
    NODE newNode = createNode(value);
    if (newNode == NULL) {
        printf(" Not able to add the new node\n");
    }
    if (head == NULL) {
        head = newNode;
        return head;
    }
    while (tempNode->next != NULL) {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
    newNode->prev = tempNode;
    return head;
}

NODE deleteNode(NODE head, int key) {
    NODE tempNode = head;
	NODE prevNode = NULL;
    if (head == NULL) {
        printf("\n The linked list is empty\n");
        return head;
    }
	while(tempNode != NULL && tempNode->data != key){
		prevNode = tempNode;
		tempNode = tempNode->next;
	}
	if(tempNode != NULL && tempNode->data == key){
		if (head->next == NULL) {
        free(head);
        head = NULL;
        return head;
	    }
	    if(tempNode->next == NULL){
			prevNode->next = NULL;
			free(tempNode);
			return head;
		}
		prevNode->next = tempNode->next;
		tempNode->next->prev = prevNode;
	    free(tempNode);
	    return head;
	}
    printf("%d not found\n", key);
	return head;
}

int main() {
    int choice, node_value, position, count;
    NODE head = NULL;
	while (1) {
    printf("Operations on doubly linked list\n");
    printf("1.Insert\n2.Remove\n3.Display\n0.Exit\n");
    printf("Enter Choice 0-4?: ");
    scanf("%d", &choice);
	switch (choice) {
		case 1:
			printf("Enter number: ");
			scanf("%d", &node_value);
			head = insertNodeAtTheEnd(head, node_value);
			break;
		case 2:
			printf("Enter number to delete: ");
			scanf("%d", &node_value);
			head =deleteNode(head, node_value);
			break;
		case 3:			
			displayDoublyLinkedList(head);
			break;
		case 0:
			exit(0);
			break;
        default:
            printf("Invalid choice\n");
            break;
	    	}
	return 0;
}
}