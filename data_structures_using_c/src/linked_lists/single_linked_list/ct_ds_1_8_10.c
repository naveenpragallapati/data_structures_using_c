#include<stdio.h>
#include<stdlib.h>

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

NODE insertAtBegin(NODE first, int x) {
	NODE newNode = createNode();
	newNode->data = x;
	newNode->next = first;
	return newNode;
}

int searchPosOfEle(NODE first, int key) {
	int pos = 1;
	int count = 0;
	NODE temp = first;
	if (first == NULL){
		return 0;
	}
	while (temp != NULL){
		if (temp->data == key){
			return pos;			
		}
		temp = temp->next;
		pos++;
	}
	return 0;
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
	int x, pos, op;
	while(1) {
		printf("1.Insert At Begin 2.Search an element Position 3.Traverse the List 4.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element : ");
					scanf("%d", &x);
					first = insertAtBegin(first, x);
					break;
			case 2:	printf("Enter search element : ");
					scanf("%d", &x);
					pos = searchPosOfEle(first, x);
					if (pos == 0) {
						printf("The given element %d is not found in the given SLL\n", x);
					} else {
						printf("The given element %d is found at position : %d\n", x, pos);
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