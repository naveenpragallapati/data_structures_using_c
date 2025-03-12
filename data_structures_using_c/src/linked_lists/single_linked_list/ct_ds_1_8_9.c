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
	NODE newNode = createNode();
	newNode->data = x;
	if (first == NULL){
		first = newNode;
		return first;
	}
	NODE temp = first;
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	return first;
}

NODE deleteAtPosition(NODE first, int pos) {
	NODE curr = first;
	NODE temp = curr->next;
	int count = 0;
	NODE temp1 = first;
	while (temp1 != NULL){
		temp1 = temp1->next;
		count++;
	}
	if (pos > count){
		printf("No such position in SLL so deletion is not possible\n");
		return first;
	}
	if (pos == 1){
		printf("The deleted element from SLL : %d\n", first->data);
		first = first->next;
		return first;
	}
	int curr_pos = 0;
	for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
		temp = curr->next;
    }
	if (temp->next == NULL){
		printf("The deleted element from SLL : %d\n", (curr->next)->data);
		curr->next = NULL;
	}
	else{
		printf("The deleted element from SLL : %d\n", (curr->next)->data);
		curr->next = temp->next;
	}
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
	int x, op, pos;
	while(1) {
		printf("1.Insert At End 2.Delete at Position 3.Traverse the List 4.Exit\n");
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
						printf("Enter position : ");
						scanf("%d", &pos);
						first = deleteAtPosition(first, pos);
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