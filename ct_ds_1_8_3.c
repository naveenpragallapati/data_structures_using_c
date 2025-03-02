#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNode(int value) {
	NODE newNode = (NODE)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;

}

NODE addNodes(NODE first, int x) {
	NODE newNode = createNode(x);
    if (!newNode) return first;

    if (first == NULL) { // If list is empty, new node becomes first
        return newNode;
    }

    // Traverse to the last node
    NODE temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode; // Link the new node
    return first;

}

void traverseList(NODE first) {
	if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    NODE temp = first;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}

void main() {
	NODE first = NULL;
	int x;
	printf("Enter elements up to -1 : ");
	scanf("%d", &x);
	while (x != -1) {
		first = addNodes(first, x);
		scanf("%d", &x);
	}
	if (first == NULL) {
		printf("Single Linked List is empty\n");
	} else {
		printf("The elements in SLL are : ");
		traverseList(first);
	}
}