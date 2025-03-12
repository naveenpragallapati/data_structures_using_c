#include <stdio.h>
#include <stdlib.h>

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

NODE deleteAtEndInCLL(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    NODE lastNode = first;
    NODE prev = NULL;
    if (lastNode->next == first) {
        printf("The deleted item from CLL : %d\n", lastNode->data);
        free(lastNode);
        return NULL;
    }
    while (lastNode->next != first) {
        prev = lastNode;
        lastNode = lastNode->next;
    }
    prev->next = first;
    printf("The deleted item from CLL : %d\n", lastNode->data);
    free(lastNode);
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
	int x, op;
	while(1) {
		printf("1.Insert At End 2.Delete at End 3.Traverse the List 4.Exit\n");
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
						first = deleteAtEndInCLL(first);
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