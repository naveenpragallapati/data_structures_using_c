#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
 };
typedef struct node *NODE;

NODE createNode() {
	NODE temp; // Declare a node
    temp = (NODE) malloc(sizeof(struct node)); // Allocate memory using malloc()
    temp -> next = NULL; // Make next point to NULL
    return temp; // return the new node
}

void main() {
	NODE first = NULL;
	int x;
	first = createNode();
	printf("Enter element of first node : ");
	scanf("%d", &x);
	first -> data = x;
	first -> next = createNode();
	printf("Enter element of second node : ");
	scanf("%d", &x);
	first -> next -> data = x;
	printf("The list is : %d --> %d --> NULL\n", first -> data, first -> next -> data);
}