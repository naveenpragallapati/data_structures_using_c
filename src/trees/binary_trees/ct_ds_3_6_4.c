#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>
#define SIZE 100000

struct node  { 
    int data; 
    struct node *right,*left; 
}; 
struct Queue  { 
    int front, rear; 
    int size; 
    struct node* *array; 
}; 
void printPathsRecur(struct node* node, int path[], int pathLen);

struct node* newNode(int data) { 
    struct node* temp = (struct node*) malloc(sizeof( struct node )); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
struct Queue* createQueue(int size) { 
    struct Queue* queue = (struct Queue*) malloc(sizeof( struct Queue )); 
    queue->front = queue->rear = -1; 
    queue->size = size; 
    queue->array = (struct node**) malloc
                   (queue->size * sizeof( struct node* )); 
    int i; 
    for (i = 0; i < size; ++i) 
        queue->array[i] = NULL; 
    return queue; 
} 
int isEmpty(struct Queue* queue)  { 
    return queue->front == -1; 
} 
int isFull(struct Queue* queue)  {  
	return queue->rear == queue->size - 1; 
} 
int hasOnlyOneItem(struct Queue* queue) {
	return queue->front == queue->rear;  
} 
void Enqueue(struct node *root, struct Queue* queue) { 
    if (isFull(queue)) 
        return; 
    queue->array[++queue->rear] = root; 
    if (isEmpty(queue)) 
        ++queue->front; 
} 
struct node* Dequeue(struct Queue* queue)  { 
    if (isEmpty(queue)) 
        return NULL; 
    struct node* temp = queue->array[queue->front]; 
    if (hasOnlyOneItem(queue)) 
        queue->front = queue->rear = -1; 
    else
        ++queue->front; 
    return temp; 
} 
struct node* getFront(struct Queue* queue)  {  
	return queue->array[queue->front]; 
} 
int hasBothChild(struct node* temp)  { 
    return temp && temp->left && temp->right; 
} 
void insert(struct node **root, char *data1, struct Queue* queue)  { 
    if (strcmp(data1, "null") == 0) {
        return;
    }
    int data = atoi(data1);
    struct node* temp = newNode(data);

    if (!(*root)) {
        *root = temp;
    } else {
        struct node* front = getFront(queue);
        if (!front->left)
            front->left = temp;
        else if (!front->right)
            front->right = temp;

        if (hasBothChild(front))
            Dequeue(queue);
    }
    Enqueue(temp, queue);	
} 
void printArray(int ints[], int len) {   
    for (int i = 0; i < len; i++) {
        printf("%d ", ints[i]);
    }
    printf("\n");
} 
void printPathsRecur(struct node* node, int path[], int pathLen) {   
    if (node == NULL) 
        return;

    path[pathLen] = node->data;
    pathLen++;

    if (node->left == NULL && node->right == NULL) {
        printArray(path, pathLen);
    } else {
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }
}
void printPaths(struct node* node) {   
    int path[1000];
    printPathsRecur(node, path, 0);
}

int main()  {   
	struct node* T1 = NULL; 
    struct Queue* queue1 = createQueue(SIZE); 
    int i, N1;
    char ele[100000];
    scanf("%d",&N1);
    for(i = 1; i <= N1; ++i)
    {   scanf("%s",ele);
        insert(&T1, ele, queue1);
    }
    printPaths(T1);
    return 0; 
}