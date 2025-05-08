#include <stdlib.h>
#include <stdio.h>

struct queue { 
	int data; 
	// Lower values indicate higher priority 
	int priority; 
	struct queue* next; 
};
typedef struct queue* PQueue;
PQueue head = NULL;

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

void dequeue() {
    if (head == NULL) {
        printf("Priority queue is underflow.\n");
    } else {
        printf("Deleted value = %d\n", head->data);
        PQueue temp = head;
        head = head->next;
        free(temp);
    }
}

int isEmpty() {
    if (head == NULL) {
        printf("Priority queue is empty.\n");
        return 1;
    } else {
        printf("Priority queue is not empty.\n");
        return 0;
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

void size() {
    int count = 0;
    PQueue temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Priority queue size : %d\n", count);
}

int main() {
	int op, p, x;
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Is Empty 5.Size 6.Exit\n");
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
				dequeue();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				size();
				break;
			case 6: exit(0);
		}
	}
}