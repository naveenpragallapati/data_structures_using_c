#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	char key[40];
	char value[40];
	struct node *next;
};

typedef struct node *NODE;

NODE dict = NULL;

NODE createNode(char key[40], char value[40]) {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	strcpy(temp->key, key);
	strcpy(temp->value, value);
	temp -> next = NULL;
	return temp;
}

void putInDict(char key[40], char value[40]) {
	NODE temp, lastNode;
	temp = createNode(key, value);
	
    if (dict == NULL) {
        dict = temp; // If dict is empty, set the new node as the first node
    } else {
        lastNode = dict;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next; // Traverse to the last node
        }
        lastNode->next = temp; // Add the new node to the end
    }
}

char * getFromDict(char key[40]) {
	// Complete the code here to travers the linked list called dict to find the node with key value matching key
	// and assign the value to result before returning it
	NODE temp = dict;
	    while (temp != NULL) {
	        if (strcmp(temp->key, key) == 0) {
	            return temp->value; // Return the value if matches
	        }
	        temp = temp->next;
	    }
	    return NULL; // Return NULL if key is not found

}

char * removeFromDict(char key[40]) {
	char *result = NULL;
	// Complete the code here to travers the linked list called dict to find the node with key value matching key
	// and assign the value to result before returning it
	// In addition, remove the found node from the linked list as well as freeing the node
      NODE temp = dict, prev = NULL;
    // Traverse the list to find the node to delete
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            result = (char*)malloc(sizeof(char) * 40);
            strcpy(result, temp->value); // Store the value of the deleted node
            if (prev == NULL) {
                dict = temp->next; // If it's the first node, move the head to the next node
            } else {
                prev->next = temp->next; // Otherwise, bypass the current node
            }
            free(temp); // Free the memory of the deleted node
            return result; // Return the value of the removed node
        }
        prev = temp;
        temp = temp->next;
    }                 
	return result;
}

void printDict() {
	NODE temp = dict;
	while (temp != NULL) {
		printf("%s:%s --> ",temp -> key, temp -> value);
		temp = temp -> next;
	}
	printf("NULL\n");
}

int main() {
	int choice;
	char key[40];
	char value[40];
	while(1) {
		printf("1.Put\n"
		"2.Get\n"
		"3.Remove\n"
		"4.Exit\n"
		"Enter Your Choice : ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter the key: ");
				scanf("%s", key);
				printf("Enter the value: ");
				scanf("%s", value);
				putInDict(key, value);
				printDict();
				break;
			case 2:
				printf("Enter the key: ");
				scanf("%s", key);
				char* value;
				value = getFromDict(key);
				if (value) {
					printf("%s is found with value %s\n", key, value);
				} else {
					printf("%s is not found\n", key);
				}
				break;
			case 3:
				printf("Enter the key: ");
				scanf("%s", key);
				if (removeFromDict(key)) {
					printf("%s deleted successfully\n", key);
				} else {
					printf("Deletion Failed: %s\n", key);
				}
				printDict();
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}