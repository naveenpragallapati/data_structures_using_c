#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node * next;
};
typedef struct node * NODE;

NODE createNodeInCLL() {
	 NODE temp; // Declare a node
    temp = (NODE) malloc(sizeof(struct node)); // Allocate memory using malloc()
    temp -> next = NULL; // Make next point to NULL
    return temp; // return the new node
}

void main() {
	NODE first = NULL;
	int x;
	first = createNodeInCLL();
	printf("Enter element of first node : ");
	scanf("%d", &x);
	first -> data = x;
	first -> next = createNodeInCLL();
	printf("Enter element of second node : ");
	scanf("%d", &x);
	first -> next -> data = x;
	first -> next -> next = first; //Showing the loop in the list.
	printf("The list is : %d --> %d --> %d\n", first -> data, first -> next -> data, first -> next -> next -> data);
}