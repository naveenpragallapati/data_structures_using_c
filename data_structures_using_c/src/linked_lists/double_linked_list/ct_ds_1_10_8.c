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

int countInDLL(NODE first) {
	int count = 0;
	NODE temp = first;
	if (first == NULL){
		return count;
	}
	while(temp!= NULL){
		count++;
		temp = temp->next;
	};
	return count;
}

NODE deleteAtBeginInDLL(NODE first) {
	NODE temp = first;
	if (first == NULL){
		printf("List is empty so deletion not possible\n");
		return first;
	}
	if(first->next == NULL){
		printf("The deleted element from DLL : %d\n", first->data);
		first = NULL;
		return first;
	}
	first = temp->next;
	first->prev = NULL;
	printf("The deleted element from DLL : %d\n", temp->data);
	free(temp);
	return first;
}

NODE deleteAtEndInDLL(NODE first) {
	NODE temp = first;
	NODE prev_node = NULL;
	while(temp->next !=NULL){
		prev_node = temp;
		temp = temp->next;
	}
	if (temp->prev == NULL){
		printf("The deleted element from DLL : %d\n",temp->data);
		first = NULL;
		return first;
	}
	else{
		prev_node->next = NULL;
		printf("The deleted element from DLL : %d\n", temp->data);
		free(temp);
		return first;
	}
}

void traverseListInDLL(NODE first) {
	NODE lastNode = first;
	while (lastNode != NULL) {
		printf("%d <--> ", lastNode -> data);
		lastNode = lastNode -> next;
	}
	printf("NULL\n");
}

NODE insertAtEndInDLL(NODE first, int x) {
	NODE temp, lastNode = first;
	temp = createNodeInDLL();
	temp -> data = x;
	if (first == NULL) {
		first = temp;
	} else {
		while (lastNode -> next != NULL) {
			lastNode = lastNode -> next;
		}
		lastNode -> next = temp;
		temp -> prev = lastNode;
	}
	return first;
}

NODE deleteAtPositionInDLL(NODE first, int position) { 
	int count =0;
	NODE temp = first;
	NODE prev_node = NULL;
	count = countInDLL(first);
	if(position<0 || position>count){
		printf("No such position in DLL so deletion is not possible\n");
			return first;
	}
	if (position==1){
		first = deleteAtBeginInDLL(first);
		return first;
	}	
	if(position==count){
		first = deleteAtEndInDLL(first);
		return first;
	}
	for(int i=0;i<position-1 && temp != NULL; i++){
		prev_node = temp;
		temp = temp->next;
	}
	NODE successor = temp->next;
	successor->prev = prev_node;
	prev_node->next = successor;
	printf("The deleted element from DLL : %d\n",temp->data);
	free(temp);
	return first;
}

void main() {
	NODE first = NULL;
	int x, op, pos;
	while(1) {
		printf("1.Insert At End 2.Delete at Position 3.Traverse the List 4.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element : ");
					scanf("%d", &x);
					first = insertAtEndInDLL(first, x);
					break;
			case 2:	if (first == NULL) {
						printf("Double Linked List is empty so deletion is not possible\n");
					} else {
						printf("Enter position : ");
						scanf("%d", &pos);
						first = deleteAtPositionInDLL(first, pos);
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