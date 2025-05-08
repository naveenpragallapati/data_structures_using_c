#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct queue { 
	int data; 
	// Lower values indicate higher priority 
	int priority; 
	struct queue* next; 
};
typedef struct queue* PQueue;
PQueue head = NULL;

// Function to create a new node
PQueue newNode(int d, int p) {
	PQueue temp = (PQueue)malloc(sizeof(struct queue)); 
	temp->data = d; 
	temp->priority = p; 
	temp->next = NULL; 
	return temp; 
} 
void enqueue(int d, int p) {
	PQueue temp = newNode(d, p);
    // If head is NULL or new node has higher priority (lower value)
    if (head == NULL || p < head->priority) {
        temp->next = head;
        head = temp;
    } else {
        PQueue start = head;
        while (start->next != NULL && start->next->priority <= p)
            start = start->next;
        temp->next = start->next;
        start->next = temp;
    }
} 
void display() {
	if (head == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }
    printf("Elements in the priority queue : ");
    PQueue temp = head;
    while (temp != NULL) {
        printf("%d (%d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
	int op, p, x;
	while(1) {	
		printf("1.Enqueue 2.Display 3.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d",&x);
				printf("Enter priority : ");
				scanf("%d",&p);
				enqueue(x,p);
				break;
			case 2: 
				display();
				break;
			case 3: exit(0);
		}
	}
}