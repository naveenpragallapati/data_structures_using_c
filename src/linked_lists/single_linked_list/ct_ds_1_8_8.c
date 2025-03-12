#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNode() {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	temp -> next = NULL;
	return temp;
}

NODE insertAtEnd(NODE first, int x) {
	NODE temp, lastNode = first;
	temp = createNode();
	temp -> data = x;
	if (first == NULL) {
		first = temp;
	} else {
		while (lastNode -> next != NULL) {
			lastNode = lastNode -> next;
		}
		lastNode -> next = temp;
	}
	return first;
}

NODE deleteAtEnd(NODE first) {
	NODE temp = first;
	NODE curr = first;
	if (first->next == NULL){
		printf("The deleted item from SLL : %d\n", first->data);
		first = NULL;
		return first;
	}
	while (temp->next != NULL){
		curr = temp;
		temp = temp->next;
	}
	curr->next = NULL;
	printf("The deleted item from SLL : %d\n", temp->data);
	return first;
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
		printf("1.Insert At End 2.Delete at End 3.Traverse the List 4.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element : ");
					scanf("%d", &x);
					first = insertAtEnd(first, x);
					break;
			case 2:	if (first == NULL) {
						printf("Single Linked List is empty so deletion is not possible\n");
					} else {
						first = deleteAtEnd(first);
					}
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