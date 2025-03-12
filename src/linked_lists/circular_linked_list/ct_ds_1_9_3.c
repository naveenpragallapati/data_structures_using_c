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

NODE addNodesInCLL(NODE first, int x) {
	NODE temp = first;
	NODE newNode = NULL;
	newNode = createNodeInCLL();
	newNode->data = x;
	if (first == NULL){
		newNode->next = newNode;
		return newNode;
	}
	while(temp->next != first){
		temp = temp->next;
	}
	temp->next =newNode;
	newNode->next = first;
	return first;
}

void traverseListInCLL(NODE first) {
	NODE temp = first;
	if (first == NULL){
		printf("The list is empty");
		return;
	}
	do{
		printf("%d --> ",temp->data);
		temp = temp->next;
	}while(temp != first);
	printf("\n");
	return;
}
void main() {
	NODE first = NULL;
	int x;
	printf("Enter elements up to -1 : ");
	scanf("%d", &x);
	while (x != -1) {
		first = addNodesInCLL(first, x);
		scanf("%d", &x);
	}
	if (first == NULL) {
		printf("Circular Linked List is empty\n");
	} else {
		printf("The elements in CLL are : ");
		traverseListInCLL(first);
	}
}