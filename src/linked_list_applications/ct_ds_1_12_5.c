#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char title[100];
    int availableCopies;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new book node at the end of the doubly linked list
struct Node* insertBook(struct Node* head, char title[], int availableCopies) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->title, title);
    newNode->availableCopies = availableCopies;
    newNode->prev = NULL;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    return head;
}

// Function to delete all books with an even number of available copies from the doubly linked list
struct Node* deleteEvenCopiesBooks(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        struct Node* nextNode = current->next;

        if (current->availableCopies % 2 == 0) {  // Check if even
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;  // Update head if needed
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
        }

        current = nextNode;
    }

    return head;
    
    
}

// Function to print the doubly linked list of books in the library
void printBooks(struct Node* head) {
    if (head == NULL) {
        printf("Library is Empty\n");
        return;
    }

    struct Node* current = head;

    while (current != NULL) {
        printf("%s: %d\n", current->title, current->availableCopies);
        current = current->next;
    }
}

int main() {
    int totalBooks;
    scanf("%d", &totalBooks);
    struct Node* library = NULL;

    for (int i = 0; i < totalBooks; ++i) {
        char title[100];
        int availableCopies;
        scanf("%s %d", title, &availableCopies);
        library = insertBook(library, title, availableCopies);
    }

    printBooks(library);

    library = deleteEvenCopiesBooks(library);

    printf("Library Availability:\n");
    printBooks(library);

    return 0;
}
