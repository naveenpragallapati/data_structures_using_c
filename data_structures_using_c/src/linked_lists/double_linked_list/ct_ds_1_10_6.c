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

NODE deleteAtBeginInDLL(NODE first) {
	NODE temp = first;
	if (first == NULL){
		printf("List is empty so deletion not possible\n");
		return first;
	}
	if(first->next == NULL){
		printf("The deleted element from DLL : %d\n", first->data);
		first = NULL;
		return first;
	}
	first = temp->next;
	first->prev = NULL;
	printf("The deleted element from DLL : %d\n", temp->data);
	free(temp);
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
	int x, op;
	while(1) {
		printf("1.Insert At Begin 2.Delete at Begin 3.Traverse the List 4.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element : ");
					scanf("%d", &x);
					first = insertAtBeginInDLL(first, x);
					break;
			case 2:	if (first == NULL) {
						printf("Double Linked List is empty so deletion is not possible\n");
					} else {
						first = deleteAtBeginInDLL(first);
					}
					break;
			case 3:	if (first == NULL) {
						printf("Double Linked List is empty\n");
					} else {
						printf("The elements in DLL are : ");
						traverseListInDLL(first);
					}
					break;
			case 4:	exit(0);
		}
	}
}