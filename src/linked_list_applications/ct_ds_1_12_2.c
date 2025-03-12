#include <stdio.h>
#include <stdlib.h>

struct Node
{   int data;
    struct Node *next;
};

void append(struct Node** head_ref, int new_data)
{   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

static void reverse(struct Node** head_ref) {
	//Write the logic for the reversal of the linked list.
	struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move prev one step forward
        current = next;       // Move current one step forward
    }
    *head_ref = prev; // Update head to the new first node	
}

void printList(struct Node *node)
{   while (node != NULL)
    {	printf("%d --> ", node->data);
    	node = node->next;
    }
}

int main()
{   struct Node* head = NULL;
    int n,i,b[30],j,a;
    scanf("%d",&n);
    for(i=0,j=n-1;i<n;i++,j--)
    {   scanf("%d",&a);
        b[j]=a;
        append(&head, a);
    }
    printf("Linked list is: ");
    printList(head);
    reverse(&head);
    printf("\nReversed Linked list: ");
    printList(head);
    return 0;
}