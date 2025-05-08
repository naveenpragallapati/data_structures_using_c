#include<stdio.h>

void main() {
	int a[20], i, n, key, pos=-1;
	printf("Enter value of n : ");
	scanf("%d", &n);
	for (i=0;i<n;i++) { //Complete the code in for
		printf("Enter element for a[%d] : ", i);
		scanf("%d", &a[i]);
	}
	printf("Enter key element : ");
	scanf("%d", &key);
	for (i=0;i<n;i++) { //Complete the code in for
		if (a[i]==key) { //Write the condition part			
			pos = i; // Complete the statement
			break;
		}
	}
	if (pos==-1) { //Write the condition part
		printf("The key element %d is not found in the array\n", key);		
	} else {
		printf("The key element %d is found at the position %d\n", key, pos);
	}
}
