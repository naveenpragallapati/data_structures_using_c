#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} *NODE;

int hasCycle(NODE head) {
    NODE slow = head, fast = head;
    
    while (fast && fast->next) {
        slow = slow->next; // Move slow pointer by 1 step
        fast = fast->next->next; // Move fast pointer by 2 steps
        
        if (slow == fast) {
            return 1; // Cycle detected
        }
    }
    
    return 0; // No cycle
}

// Function to create a new node
NODE createNode(int val) {
    NODE newNode = (NODE)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, i, pos;
    scanf("%d", &n);
    
    NODE head = NULL, temp = NULL, cycleNode = NULL;
    NODE nodes[n]; // Array to store node pointers for cycle creation
    
    for (i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        NODE newNode = createNode(value);
        nodes[i] = newNode; // Store reference
        
        if (!head) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    
    scanf("%d", &pos);
    if (pos != 0) {
        temp->next = nodes[pos - 1]; // Creating a cycle
    }
    
    printf("%d\n", hasCycle(head));
    return 0;
}