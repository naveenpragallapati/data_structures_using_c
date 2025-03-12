#include <stdio.h>
#include <stdlib.h>
struct list {
	int data;
	struct list *next;
};

struct list* create(struct list *first) {
	char op;
	struct list *q, *temp;
	do {
		temp = (struct list*)malloc(sizeof(struct list)); // Allocate memory
		if (temp == NULL) {
            printf("Memory allocation failed!\n");
            return first;
        }
		printf("Enter an integer value : ");
		scanf("%d",&temp->data); // Read data
		temp -> next = NULL ; // Place NULL
		if (first == NULL) {
			first = temp; // Assign temp to the first node
		} else {
			q -> next = temp ; // Create a link from the last node to new node temp
		}
		q = temp;
		printf("Do u want another list (y|n) : ");
		scanf(" %c", &op);
	} while(op == 'y' || op == 'Y');
	return first;
}
void display(struct list *first) {
	struct list *temp = first;
	while (temp != NULL) { // Stop the loop where temp is NULL
		printf("%d-->", temp->data);
		temp = temp->next; // Assign next of temp to temp
	}
	printf("NULL\n");
}

void main() {
	struct list *first = NULL;
	first = create(first);
	printf("The elements in the single linked lists are : ");
	display(first);
}