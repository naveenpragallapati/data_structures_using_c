#include <stdio.h>
#include <stdlib.h>

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

int countInDLL(NODE first) {
	int count = 0;
	NODE temp = first;
	if (first == NULL){
		return count;
	}
	while(temp!= NULL){
		count++;
		temp = temp->next;
	};
	return count;
}

NODE insertAtBeginInDLL(NODE first, int x) {
	NODE temp = first;
	NODE newNode = createNodeInDLL();
	newNode->data = x;
	if (first == NULL){
		first = newNode;
		return first;
	}
	newNode->next = temp;
	newNode->prev = first;
	first = newNode;
	return first;
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

NODE insertAtPositionInDLL(NODE first, int position, int x) { 
	NODE temp = first;
	int count = 0;	
	count = countInDLL(first);
	if(position<0 || position>count+1){
		printf("No such position in DLL so insertion is not possible\n");
		return first;
	}
	if(position==1){
		first = insertAtBeginInDLL(first, x);
		return first;
	}
	if(position==count+1){
		first = insertAtEndInDLL(first, x);
		return first;
	}
	NODE newNode = createNodeInDLL();
	newNode->data = x;
	for(int i=1; i<position-1 && temp != NULL; i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next = newNode;
	return first;
}

void traverseListInDLL(NODE first) {
	NODE lastNode = first;
	while (lastNode != NULL) {
		printf("%d <--> ", lastNode -> data);
		lastNode = lastNode -> next;
	}
	printf("NULL\n");
}

void main() {
	NODE first = NULL;
	int x, pos, op;
	while(1) {
		printf("1.Insert At specified position 2.Traverse the List 3.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter a position : ");
					scanf("%d", &pos);
					printf("Enter an element : ");
					scanf("%d", &x);
					first = insertAtPositionInDLL(first, pos, x);
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