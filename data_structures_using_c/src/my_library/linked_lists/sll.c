#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node *NODE;

NODE createNode(int value){
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("\n No memory is allocated for the new node\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;    
    return newNode;    
}

void displaySingleLinkedList(NODE head){
    NODE tempNode = head;
    printf("\n The Singly Linked List is:\n");
    while(tempNode != NULL){
        printf("%d -->", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("NULL");
    return;
}

int displayCount(NODE head){
    NODE tempNode = head;
    int count = 0;
    while(tempNode != NULL){
        count++;
        tempNode = tempNode->next;
    }    
    return count;
}

int searchElement(NODE head, int value){
    NODE tempNode = head;
    int position = 1;
    while(tempNode != NULL){
        if (tempNode->data == value){
            printf("\n The element %d is found at position %d", value, position);
            return position;
        }
        position++;
        tempNode = tempNode->next;
    }
    printf("\n The element %d is not found in the linked list", value);
    return -1;
}

NODE insertNodeAtTheEnd(NODE head, int value){
   NODE tempNode = head;   
   NODE newNode = createNode(value);
   if (newNode == NULL){
       printf(" Not able to add the new node\n");
   }
   if (head == NULL){
       head = newNode;
       return head;
   }
   if (newNode!= NULL){
       while(tempNode->next != NULL){           
           tempNode = tempNode->next;
       }
   tempNode->next = newNode;
   }
   return head;
}

NODE deleteNodeAtTheEnd(NODE head){
    NODE tempNode = head;
    NODE prevNode = NULL;
    if (head == NULL){
        printf("\n The linked list is empty\n");
        return head;
    }
    if (head->next == NULL){
        free(head);
        head = NULL;
        return head;
    }
    while(tempNode->next != NULL){
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    prevNode->next = NULL;
    free(tempNode);
    return head;
}

NODE insertNodeAtTheBeginning(NODE head, int value){
   NODE tempNode = head;   
   NODE newNode = createNode(value);
   if (newNode == NULL){
       printf(" Not able to add the new node\n");
   }
   if (head == NULL){
       head = newNode;
       return head;
   }
    newNode->next = head;
    head = newNode;
   return head;
}

NODE deleteNodeAtTheBeginning(NODE head){
    NODE tempNode = head;
    if (head == NULL){
        printf("\n The linked list is empty\n");
        return head;
    }
    if (head->next == NULL){
        free(head);
        head = NULL;
        return head;
    }
    head = head->next;
    free(tempNode);
    return head;
}

NODE insertNodeAtSpecifiedPosition(NODE head, int value, int position) {
    int node_count = displayCount(head);
    NODE newNode = createNode(value);
    if (newNode == NULL) {
        printf(" Not able to add the new node\n");
        return head;
    }
    if (position > node_count + 1 || position <= 0) {
        printf("\n The position is out of range\n");
        free(newNode); // Free the allocated memory
        return head;
    }
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    NODE tempNode = head;
    for (int i = 1; i < position - 1; i++) {
        tempNode = tempNode->next;
    }
    newNode->next = tempNode->next;
    tempNode->next = newNode;
    return head;
}

NODE deleteNodeAtSpecifiedPosition(NODE head, int position) {
    if (head == NULL) {
        printf("\n The linked list is empty\n");
        return head;
    }

    int node_count = displayCount(head);
    if (position > node_count || position <= 0) {
        printf("\n The position is out of range\n");
        return head;
    }

    NODE tempNode = head;
    if (position == 1) {
        head = head->next;
        free(tempNode);
        return head;
    }

    NODE prevNode = NULL;
    for (int i = 1; i < position; i++) {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }

    prevNode->next = tempNode->next;
    free(tempNode);
    return head;
}

NODE reverseSingleLinkedList(NODE head){
    NODE prevNode = NULL;
    NODE nextNode = NULL;
    NODE currentNode = head;
    while(currentNode != NULL){
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    return head;
}

int main(){
    int choice, node_value, position, count;
    NODE head = NULL;
    printf("\n\n Singly Linked List Operations\n");

    printf("\n\n 1. Display SLL\n 2. Display Count\n 3. Search for an element\n 4. Insert a node at the end\n 5. Insert a node at the beginning\n 6. Insert at a specified position\n ");
    printf("7. Delete a node at the end \n 8. Delete a node at the beginning\n 9. Delete a node at a specified position\n 10. Reverse the Singly Linked List\n 11. Exit\n");
    printf("\n Enter your choice : ");
    scanf("%d", &choice);

    while(choice != 11){
        switch(choice){
        case 1:
            printf("\n The updated Singly Linked List is :\n");
            displaySingleLinkedList(head);
            break;
        case 2:
            count = displayCount(head);
            printf("\n The count of the nodes in the Singly Linked List is : %d", count);        
            break;
        case 3:
            printf("\n Enter the element to be searched: ");
            scanf("%d", &node_value);
            position = searchElement(head, node_value);
            break;
        case 4:
            printf("\n Enter the node value : ");
            scanf("%d", &node_value);
            head = insertNodeAtTheEnd(head, node_value);
            displaySingleLinkedList(head);
            break;
        case 5:
            printf("\n Enter the node value: ");
            scanf("%d", &node_value);
            head = insertNodeAtTheBeginning(head, node_value);
            displaySingleLinkedList(head);
            break;
        case 6:
            printf("\n Enter the node value: ");
            scanf("%d", &node_value);
            printf("\n Enter the position: ");
            scanf("%d", &position);
            head = insertNodeAtSpecifiedPosition(head, node_value, position);
            displaySingleLinkedList(head);        
            break;    
        case 7:
            head = deleteNodeAtTheEnd(head);
            displaySingleLinkedList(head);
            break;
        case 8:
            head = deleteNodeAtTheBeginning(head);
            displaySingleLinkedList(head);
            break;
        case 9:
            printf("\n Enter the position of the node to be deleted: ");
            scanf("%d", &position);
            head = deleteNodeAtSpecifiedPosition(head, position);
            displaySingleLinkedList(head);
            break;
        case 10:
            head = reverseSingleLinkedList(head);
            displaySingleLinkedList(head);
            break;
        case 11:
            printf("\n Exiting the program\n");
            break;
        default:
            printf("\n Wrong selection of choice\n");
            break;
        }
        printf("\n\n 1. Display SLL\n 2. Display Count\n 3. Search for an element\n 4. Insert a node at the end\n 5. Insert a node at the beginning\n 6. Insert at a specified position\n ");
        printf("7. Delete a node at the end \n 8. Delete a node at the beginning\n 9. Delete a node at a specified position\n 10. Reverse the Singly Linked List\n 11. Exit\n");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
    }
    return 0;
}