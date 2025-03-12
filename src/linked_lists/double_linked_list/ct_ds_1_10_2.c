#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node * NODE;

NODE createNodeInDLL() {
	NODE temp; // declare a node
	temp = (NODE) malloc(sizeof(struct node)); // allocate memory using malloc()
	temp -> prev = NULL; // make prev point to NULL
	temp -> next = NULL; // make next point to NULL
	return temp; // return the new node
}

void main() {
	NODE first = NULL,second = NULL;
	int x;
	//Creating first node of DLL
	first = createNodeInDLL();
	printf("Enter element of first node : ");
	scanf("%d", &x);
	first -> data = x;
	//Creating Second Node of DLL
	second = createNodeInDLL();
	printf("Enter element of second node : ");
	scanf("%d", &x);
	second -> data = x;
	//creating Links
	first -> next = second;
	second -> prev = first;
	printf("The Double Linked List is : %d <--> %d <--> NULL\n", first -> data, first -> next -> data);
}