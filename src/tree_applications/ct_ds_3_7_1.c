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
void insert(struct node **root, int data, struct Queue* queue) { 
    struct node *temp = newNode(data); 
    if (!*root) 
        *root = temp; 
    else { 
        struct node* front = getFront(queue); 
        if (!front->left) {  
                front->left = NULL; 
            front->left = temp; 
        } 
        else if (!front->right) {
                front->right = NULL; 
            front->right = temp; 
        }
        if (hasBothChild(front)) {
                Dequeue(queue);
        }
    } 
            Enqueue(temp, queue); 
} 
void levelOrder(struct node* root)  { 
    struct Queue* queue = createQueue(SIZE); 
    Enqueue(root, queue); 
    while (!isEmpty(queue)) { 
        struct node* temp = Dequeue(queue); 
        printf("%d ", temp->data); 
        if (temp->left) 
            Enqueue(temp->left, queue); 
        if (temp->right) 
            Enqueue(temp->right, queue); 
    } 
} 
void inorder( struct node *ptr) {
     if (ptr == NULL)
        return;
    inorder(ptr->left);
    printf("%d ", ptr->data);
    inorder(ptr->right);      
}
int LeafCount(struct node* node) {
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    return LeafCount(node->left) + LeafCount(node->right);  
}

int main() {
    struct node* T1 = NULL;
    struct Queue* queue1 = createQueue(SIZE);
    int ele;
    while (1) {
        scanf("%d", &ele);
        if (ele == -1) {
            break;
        } else {
            insert(&T1, ele, queue1);
        }
    }
    inorder(T1);
    printf("\n%d\n", LeafCount(T1));
    return 0;
} 