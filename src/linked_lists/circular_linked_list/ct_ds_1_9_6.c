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

int countInCLL(NODE first) {
	int count = 0;
	NODE temp = first;
	if (first == NULL){
		return count;
	}
	do{
		count++;
		temp = temp->next;
	}while(temp != first);
	return count;
}

NODE insertAtPositionInCLL(NODE first, int pos, int x) {
	NODE temp = first;	
	NODE newNode = createNodeInCLL();
	newNode->data = x;
	int i=0, count = 0;
	count = countInCLL(first);
	if (pos>count+1){
		printf("No such position in CLL so insertion is not possible\n");
		free(newNode);
		return first;
	}
	// Case 1: Insert at the beginning
    if (pos == 1) {
        if (first == NULL) { // Empty list case
            newNode->next = newNode;
            return newNode;
        }

        // Find the last node to update its next pointer
        NODE temp = first;
        while (temp->next != first) {
            temp = temp->next;
        }
        newNode->next = first;
        temp->next = newNode; // Update last node's next
        return newNode; // New node becomes the first node
    }
	for(i=1; i<pos-1 && temp->next != first;i++){
		temp = temp->next;
	}
	// Insert newNode at the correct position
    newNode->next = temp->next;
    temp->next = newNode;
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
	int x, pos, op;
	while(1) {
		printf("1.Insert At specified position 2.Traverse the List 3.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter a position : ");
					scanf("%d", &pos);
					if (pos <= 0) {
						printf("No such position in CLL so insertion is not possible\n");
					} else {
						printf("Enter an element : ");
						scanf("%d", &x);
						first = insertAtPositionInCLL(first, pos, x);
					}
					break;
			case 2:	if (first == NULL) {
						printf("Circular Linked List is empty\n");
					} else {
						printf("The elements in CLL are : ");
						traverseListInCLL(first);
					}
					break;
			case 3:	exit(0);
		}
	}
}