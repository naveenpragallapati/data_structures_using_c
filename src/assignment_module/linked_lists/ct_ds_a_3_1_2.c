#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} *NODE;

// Function to create a new node
NODE createNode(int val) {
    NODE newNode = (NODE)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse a linked list
NODE reverseList(NODE head) {
    NODE prev = NULL;
    NODE current = head;
    while (current != NULL) {
        NODE next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to check if a linked list is palindromic
bool isPalindrome(NODE head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // Find the middle of the linked list
    NODE slow = head;
    NODE fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    NODE secondHalf = reverseList(slow);
    NODE firstHalf = head;

    // Compare the two halves
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    NODE head = NULL, temp = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        NODE newNode = createNode(value);
        if (!head) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    if (isPalindrome(head)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    // Free allocated memory
    temp = head;
    while (temp != NULL) {
        NODE next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}