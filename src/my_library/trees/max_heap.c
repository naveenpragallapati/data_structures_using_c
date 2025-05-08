#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;

// Function to swap two elements in the heap array by their indices
void swap(int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Function to insert an element into the max heap
void insert(int value) {
    if (size >= MAX_SIZE) {
        printf("Heap overflow! Cannot insert more elements.\n");
        return;
    }

    // Insert the new element at the end of the heap
    heap[size] = value;
    int current = size;
    size++;

    // Heapify up: Fix the max heap property
    while (current > 0 && heap[current] > heap[(current - 1) / 2]) {
        swap(current, (current - 1) / 2);
        current = (current - 1) / 2;
    }

    printf("Inserted %d into the heap.\n", value);
}

// Function to delete the root element (maximum element) from the max heap
void delete_max() {
    if (size <= 0) {
        printf("Heap underflow! No elements to delete.\n");
        return;
    }

    printf("Deleted %d from the heap.\n", heap[0]);

    // Replace the root with the last element
    heap[0] = heap[size - 1];
    size--;

    // Heapify down: Fix the max heap property
    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int largest = current;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest == current) {
            break;
        }

        swap(current, largest);
        current = largest;
    }
}

// Function to display the elements of the heap
void display() {
    if (size <= 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Max Heap elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Max Heap Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                printf("Deleting the maximum element...\n");
                delete_max();
                break;
            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}