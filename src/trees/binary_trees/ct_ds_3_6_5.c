#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    TreeNode** queue = (TreeNode**) malloc(n * sizeof(TreeNode*));
    int front = 0, rear = 0, i = 0;

    TreeNode* root = newNode(arr[i++]);
    queue[rear++] = root;

    while (i < n) {
        TreeNode* current = queue[front++];
        if (i < n && arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

int maxSum = INT_MIN;

int maxPathUtil(TreeNode* root) {
    if (!root) return 0;
    int left = maxPathUtil(root->left);
    int right = maxPathUtil(root->right);

    int maxSingle = fmax(root->val, root->val + fmax(left, right));
    int maxTop = fmax(maxSingle, root->val + left + right);
    if (maxTop > maxSum) maxSum = maxTop;

    return maxSingle;
}


long maxPathSumBT(int nodesOfBT[], int nodesOfBTLen) {
	TreeNode* root = buildTree(nodesOfBT, nodesOfBTLen);
    maxSum = INT_MIN;
    maxPathUtil(root);
    return maxSum;
	
}
int readIntArray(char *argsArray, int arr[]) {
	int col = 0;
	char *token = strtok(argsArray, " ");
	while (token != NULL) {
		arr[col] = atoi(token);
		token = strtok(NULL, " ");
		col++;
	}
	return col;
}

int main(int argc, char *argv[]) {
	int nodesOfBT[strlen(argv[1])];
	int nodesOfBTLen = readIntArray(argv[1], nodesOfBT);
	printf("%ld\n", maxPathSumBT(nodesOfBT, nodesOfBTLen));
	return 0;
}