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

NODE insertAtEndInDLL(NODE first, int x) {
	NODE temp, lastNode = first;
	temp = createNodeInDLL();
	temp -> data = x;
	if (first == NULL) {
		first = temp;
	} else {
		while (lastNode -> next != NULL) {
			lastNode = lastNode -> next;
		}
		lastNode -> next = temp;
		temp -> prev = lastNode;
	}
	return first;
}

NODE deleteAtEndInDLL(NODE first) {
	NODE temp = first;
	NODE prev_node = NULL;
	while(temp->next !=NULL){
		prev_node = temp;
		temp = temp->next;
	}
	if (temp->prev == NULL){
		printf("The deleted element from DLL : %d\n",temp->data);
		first = NULL;
		return first;
	}
	else{
		prev_node->next = NULL;
		printf("The deleted element from DLL : %d\n", temp->data);
		free(temp);
		return first;
	}
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
		printf("1.Insert At End 2.Delete at End 3.Traverse the List 4.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element : ");
					scanf("%d", &x);
					first = insertAtEndInDLL(first, x);
					break;
			case 2:	if (first == NULL) {
						printf("Double Linked List is empty so deletion is not possible\n");
					} else {
						first = deleteAtEndInDLL(first);
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