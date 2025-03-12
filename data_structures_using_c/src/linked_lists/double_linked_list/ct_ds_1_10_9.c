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

void traverseListInDLL(NODE first) {
	NODE lastNode = first;
	while (lastNode != NULL) {
		printf("%d <--> ", lastNode -> data);
		lastNode = lastNode -> next;
	}
	printf("NULL\n");
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
int searchPosOfEleInDLL(NODE head, int value) { 
	NODE tempNode = head;
    int position = 1;
    while (tempNode != NULL) {
        if (tempNode->data == value) {            
            return position;
        }
        position++;
        tempNode = tempNode->next;
    }
    return 0;
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
					first = insertAtBeginInDLL(first, x);
					break;
			case 2:	printf("Enter search element : ");
					scanf("%d", &x);
					pos = searchPosOfEleInDLL(first, x);
					if (pos == 0) {
						printf("The given element %d is not found in the given DLL\n", x);
					} else {
						printf("The given element %d is found at position : %d\n", x, pos);
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