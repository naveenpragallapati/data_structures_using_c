#include <stdio.h>
#include<stdlib.h>

#define SIZE 10
int HashTable[SIZE];

int hash(int x) {
    return x % SIZE;
}

void insert(int x) {
    int index = hash(x);
    if (HashTable[index] == -1) {
        HashTable[index] = x;
        printf("Successfully inserted.\n");
    } else {
        printf("Collision Occured.\n");
    }
}

void delete(int x) {
    int index = hash(x);
    if (HashTable[index] == x) {
        HashTable[index] = -1;
        printf("Successfully deleted.\n");
    } else {
        printf("Element not found. So cannot delete the element.\n");
    }
}

void search(int x) {
    int index = hash(x);
    if (HashTable[index] == x) {
        printf("Element found.\n");
    } else {
        printf("Element not found.\n");
    }
}

void print() {
    for (int i = 0; i < SIZE; i++) {
        if (HashTable[i] != -1) {
            printf("[%d]=>%d ", i, HashTable[i]);
        }
    }
    printf("\n");
}

int main() {
	int x, op, i = 0;
	for (i = 0; i < SIZE; i++)
		HashTable[i] = -1;
	while (1) {
		printf("1.Insert 2.Delete 3.Search 4.Print 5.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch (op) {
			case 1:	printf("Enter an element to be inserted : ");
					scanf("%d", &x);
					insert(x);
					break;
			case 2:
					printf("Enter an element to be deleted : ");
					scanf("%d", &x);
					delete(x);
					break;
			case 3: 
					printf("Enter an element to be searched : ");
					scanf("%d", &x);
					search(x);
					break;
			case 4: 
					print();
					break;
			case 5:	exit(0);
		}
	}
}