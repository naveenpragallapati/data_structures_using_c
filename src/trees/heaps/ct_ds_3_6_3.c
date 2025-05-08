#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void swap(int *x, int *y); 

typedef struct minheap { 
	int heap_arr[20]; 
	int capacity;
	int heap_size;
}* MinHeap;

void swap(int *x, int *y) { 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
}
int parent(int i) { 
	return i/2; 
} 
int left(int i) { 
	return 2*i; 
} 
int right(int i) { 
	return (2*i + 1); 
}
void minHeapify(MinHeap minh, int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if (l <= minh->heap_size && minh->heap_arr[l] < minh->heap_arr[smallest])
		smallest = l;

	if (r <= minh->heap_size && minh->heap_arr[r] < minh->heap_arr[smallest])
		smallest = r;

	if (smallest != i) {
		swap(&minh->heap_arr[i], &minh->heap_arr[smallest]);
		minHeapify(minh, smallest);
	}
}

void insertKey(MinHeap minh, int k) {
	if (minh->heap_size >= minh->capacity - 1) {
		printf("Heap overflow!\n");
		return;
	}
	
	minh->heap_size++;
	int i = minh->heap_size;
	minh->heap_arr[i] = k;

	while (i > 1 && minh->heap_arr[parent(i)] > minh->heap_arr[i]) {
		swap(&minh->heap_arr[i], &minh->heap_arr[parent(i)]);
		i = parent(i);
	}
} 
void deleteMin(MinHeap minh) {
	if (minh->heap_size == 0) {
		printf("Heap is empty.\n");
		return;
	}
	
	printf("Minimum value: %d\n", minh->heap_arr[1]);
	minh->heap_arr[1] = minh->heap_arr[minh->heap_size];
	minh->heap_size--;
	minHeapify(minh, 1);
}
void print(MinHeap minh) {
	if (minh->heap_size == 0) {
		printf("Heap is empty.\n");
		return;
	}
	printf("Elements of the min heap are: ");
	for (int i = 1; i <= minh->heap_size; i++) {
		printf("%d ", minh->heap_arr[i]);
	}
	printf("\n");
}

void main() {
	int choice;
	int element;
	MinHeap minh = (MinHeap) malloc(sizeof(struct minheap));
	minh->capacity = 20;
	while(1) {
		printf("1.Insert\n2.Delete Minimum\n3.Print\n4.Exit\nEnter Your Choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter an element: ");
				scanf("%d", &element);
				insertKey(minh, element);
				break;
			case 2:
				deleteMin(minh);
				break;
			case 3:
				print(minh);
				break;
			case 4:
				exit(0);
		}
	}
} 
