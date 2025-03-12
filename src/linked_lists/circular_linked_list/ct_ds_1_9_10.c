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

NODE insertAtBeginInCLL(NODE first, int x) {
	NODE temp = first;
	NODE newNode = createNodeInCLL();
	newNode->data = x;
	if (first == NULL){
		newNode->next = newNode;
		return newNode;
	}
    while (temp->next != first) {
        temp = temp->next;
    }    
    newNode->next = first;
    temp->next = newNode;
	return newNode;
}

int searchPosOfEleInCLL(NODE first, int key) {
    if (first == NULL) {
        return 0; // List is empty
    }

    int count = 1; // Start from position 1
    NODE currentNode = first;

    do {
        if (currentNode->data == key) {
            return count; // Return position if found
        }
        currentNode = currentNode->next;
        count++;
    } while (currentNode != first); // Traverse until we come back to first

    return 0; // Element not found
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
		printf("1.Insert At Begin 2.Search an element Position 3.Traverse the List 4.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element : ");
					scanf("%d", &x);
					first = insertAtBeginInCLL(first, x);
					break;
			case 2:	printf("Enter search element : ");
					scanf("%d", &x);
					pos = searchPosOfEleInCLL(first, x);
					if (pos == 0) {
						printf("The given element %d is not found in the given CLL\n", x);
					} else {
						printf("The given element %d is found at position : %d\n", x, pos);
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