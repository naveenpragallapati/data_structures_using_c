#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNode() {
	NODE newNode = (NODE)malloc(sizeof(struct node));
	if (newNode == NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	return newNode;
}

NODE insertAtBegin(NODE first, int x) {
	NODE newNode = createNode();
	newNode->data = x;
	newNode->next = first;
	return newNode;
}

int count(NODE first) {
	int count = 0;
	NODE temp = first;
	while (temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void traverseList(NODE first) {
	NODE temp = first;
	while (temp != NULL) {
		printf("%d --> ",temp -> data);
		temp = temp -> next;
	}
	printf("NULL\n");
}
void main() {
	NODE first = NULL;
	int x, op;
	while(1) {
		printf("1.Insert At Begin 2.Count Number of Nodes 3.Traverse the List 4.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element : ");
					scanf("%d", &x);
					first = insertAtBegin(first, x);
					break;
			case 2:	printf("The number of nodes in a SLL are : %d\n", count(first));
					break;
			case 3:	if (first == NULL) {
						printf("Single Linked List is empty\n");
					} else {
						printf("The elements in SLL are : ");
						traverseList(first);
					}
					break;
			case 4:	exit(0);
		}
	}
}