#include <stdio.h>
int size = 0;

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int array[], int size, int i) {
    int largest = i;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        largest = i;

        if (left < size && array[left] > array[largest])
            largest = left;

        if (right < size && array[right] > array[largest])
            largest = right;

        if (largest == i)
            break;

        // Swap and continue heapifying down the subtree
        swap(&array[i], &array[largest]);
        i = largest;
    }
   
}

void insert(int array[], int newNum) {
	int i = size;
    array[size++] = newNum;

    // Heapify from bottom up
    while (i != 0 && array[(i - 1) / 2] < array[i]) {
        swap(&array[i], &array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteRoot(int array[], int num) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == num)
            break;
    }

    if (i == size) {
        printf("Element not found\n");
        return;
    }

    swap(&array[i], &array[size - 1]);
    size--;

    heapify(array, size, i);    
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
    
}

int main() {
    int array[100]; // Increase the array size to handle more elements
    int choice, num;

    do {
        printf("1.Insert an element\n");
        printf("2.Delete an element\n");
        printf("3.Print the Max-Heap array\n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &num);
                insert(array, num);
                break;
            case 2:
                if (size == 0) {
                    printf("Max-Heap is empty");
                } else {
                    printf("Enter the element to delete: ");
                    scanf("%d", &num);
                    deleteRoot(array, num);
                }
                break;
            case 3:
                if (size == 0) {
                    printf("Max-Heap is empty");
                } else {
                    printf("Max-Heap array: ");
                    printArray(array, size);
                }
                break;
            case 4:
                printf("Exiting the program");
                break;
            default:
                printf("Invalid choice");
                break;
        }
    } while (choice != 4);

    return 0;
}
