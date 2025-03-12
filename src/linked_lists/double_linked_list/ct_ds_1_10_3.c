#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node * NODE;

NODE createNodeInDLL() {
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

NODE insertAtEndInDLL(NODE first, int x) {
	NODE temp = first;
	NODE newNode = createNodeInDLL();
	newNode->data = x;
	if (first == NULL){
		first = newNode;
		return first;
	}
	while(temp->next != NULL){
		temp = temp -> next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	return first;
}

void traverseListInDLL(NODE first) {
	NODE temp = first;
	if (first == NULL){
		printf("The DLL is empty\n");
	}
	while(temp != NULL){
		printf("%d <--> ", temp->data);
		temp = temp->next;
	}
	printf("NULL");
	printf("\n");
	return;
}

void main() {
	NODE first = NULL;
	int x, op;
	while(1) {
		printf("1.Insert At End 2.Traverse the List 3.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element : ");
					scanf("%d", &x);
					first = insertAtEndInDLL(first, x);
					break;
			case 2:	if (first == NULL) {
						printf("Double Linked List is empty\n");
					} else {
						printf("The elements in DLL are : ");
						traverseListInDLL(first);
					}
					break;
			case 3:	exit(0);
		}
	}
}