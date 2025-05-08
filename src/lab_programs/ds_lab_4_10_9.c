#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int TABLE_SIZE = 128;

struct entry {
    char key[100];
    char value[100];
    struct entry* next; // to handle collisions via chaining
};

typedef struct entry *ENTRY;

ENTRY table[128];

ENTRY createNode(char key[100], char value[100]) {
    ENTRY temp = (ENTRY)malloc(sizeof(struct entry));
    strcpy(temp->key, key);
    strcpy(temp->value, value);
    temp->next = NULL;
    return temp;
}

int hashf(char *key) {
    int asciiSum = 0;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        asciiSum = asciiSum + key[i];
    }
    return asciiSum % TABLE_SIZE;
}

void put(char *key, char *value) {
    int index = hashf(key);
    ENTRY newNode = createNode(key, value);
    
    // If the slot is empty, directly insert the new node
    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        // Handle collisions using chaining
        ENTRY temp = table[index];
        while (temp != NULL) {
            if (strcmp(temp->key, key) == 0) {
                // Key exists, update the value
                strcpy(temp->value, value);
                free(newNode); // Free the new node as it won't be needed
                return;
            }
            temp = temp->next;
        }
        // If the key does not exist, insert the new node at the end of the chain
        newNode->next = table[index];
        table[index] = newNode;
    }
}

char* get(char *key) {
    int index = hashf(key);
    ENTRY temp = table[index];
    
    // Traverse the chain to find the key
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value; // Key found, return the value
        }
        temp = temp->next;
    }
    
    return NULL; // Key not found
}

int removeFromDict(char *key) {
    int index = hashf(key);
    ENTRY temp = table[index];
    ENTRY prev = NULL;
    
    // Traverse the chain to find the key
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            if (prev == NULL) {
                // Key is at the head of the chain
                table[index] = temp->next;
            } else {
                // Key is in the middle or end of the chain
                prev->next = temp->next;
            }
            free(temp); // Free the memory allocated for the node
            return 1; // Successfully deleted
        }
        prev = temp;
        temp = temp->next;
    }
    
    return 0; // Key not found
}

// Move these outside the switch block
char key[100];
char value[100];

int main() {
    int choice;

    while (1) {
        printf("1.Put\n"
               "2.Get\n"
               "3.Remove\n"
               "4.Exit\n"
               "Enter Your Choice : ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the key: ");
                scanf("%s", key);
                printf("Enter the value: ");
                scanf("%s", value);
                put(key, value);
                printf("Inserted successfully\n");
                break;
            }
            case 2: {
                printf("Enter the key: ");
                scanf("%s", key);
                char *result = get(key);
                if (result != NULL) {
                    printf("%s is found with value %s\n", key, result);
                } else {
                    printf("%s is not found\n", key);
                }
                break;
            }
            case 3: {
                printf("Enter the key: ");
                scanf("%s", key);
                if (removeFromDict(key)) {
                    printf("%s deleted successfully\n", key);
                } else {
                    printf("Deletion Failed: %s\n", key);
                }
                break;
            }
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

// description: This program implements a simple hash table with separate chaining for collision resolution. It allows the user to insert, retrieve, and delete key-value pairs. The hash function is based on the sum of ASCII values of the characters in the key. The program uses a linked list to handle collisions, allowing multiple entries to be stored at the same index in the hash table.