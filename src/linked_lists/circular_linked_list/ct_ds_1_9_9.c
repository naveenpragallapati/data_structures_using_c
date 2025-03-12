#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNodeInCLL() {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	temp -> next = NULL;
	return temp;
}

NODE insertAtEndInCLL(NODE first, int x) {
	NODE temp = first;
	NODE newNode = createNodeInCLL();
	newNode->data = x;
	if (first == NULL){
		newNode->next = newNode;
		return newNode;
	}
	do{
		temp = temp->next;
	}while(temp->next != first);
	temp->next = newNode;
	newNode->next = first;
	return first;
}

int countNodes(NODE head){
	NODE temp = head;
	int node_count = 1;
	if (head == NULL){
		return 0;
	}
	do{
		node_count++;
		temp = temp->next;
	}while(temp->next != head);
	return node_count;
}

NODE deleteAtPositionInCLL(NODE first, int position) {
	NODE prev = first, lastNode = first;
	int count = 0;
	if (first == NULL || position <= 0) {
	printf("List is Empty. So deletion is not possible\n");
	} 
	else {  
			count = countNodes(first);
			if (position>count){
	            printf("No such position in CLL so deletion is not possible\n");
				return first;
			}				
			if (position == 1) {
			if (prev -> next == first) {
				first = NULL;
			} else {
				while (lastNode -> next != first) {
					lastNode = lastNode -> next;
				}
				first = prev -> next;
				lastNode -> next = first;
			} 
		} else {
			for (int i = 1; i < position; i++) {
				if (prev -> next == first) {
					return first;
				}
				lastNode = prev;
				prev = prev -> next;
			}
			lastNode -> next = prev -> next; 
		} 
		printf("The deleted element from CLL : %d\n", prev -> data);
		free(prev);
		return first;
	} 
	return first;
}

void traverseListInCLL(NODE first) {
	NODE temp = first;
	do {
		printf("%d --> ", temp -> data);
		temp = temp -> next;
	} while (temp != first);
	printf("\n");
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
					first = insertAtEndInCLL(first, x);
					break;
			case 2:	if (first == NULL) {
						printf("Circular Linked List is empty so deletion is not possible\n");
					} else {
						printf("Enter position : ");
						scanf("%d", &pos);
						first = deleteAtPositionInCLL(first, pos);
					}
					break;
			case 3:	if (first == NULL) {
						printf("Circular Linked List is empty\n");
					} else {
						printf("The elements in CLL are : ");
						traverseListInCLL(first);
					}
					break;
			case 4:	exit(0);
		}
	}
}