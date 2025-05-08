#include<stdio.h>
#include<string.h>

void main() {
	char a[20][20];
	int i, n, j,index;
	char large[20];
	printf("Enter value of n : ");
	scanf("%d", &n);
	char temp[20];
	for(i = 0; i < n; i++) {
        printf("Enter string for a[%d] : ", i);
        scanf("%s", a[i]);
    }

	printf("Before sorting the strings in the array are\n");	
    for(i = 0; i < n; i++) {
        printf("String at a[%d] = %s\n", i, a[i]);
    }

    // Selection sort - Largest element method
    for(i = n - 1; i > 0; i--) {
        index = 0;
        for(j = 1; j <= i; j++) {
            if(strcmp(a[j], a[index]) > 0) {
                index = j;
            }
        }
        // Swap a[index] and a[i]
        strcpy(temp, a[index]);
        strcpy(a[index], a[i]);
        strcpy(a[i], temp);
    }
	
	printf("After sorting the strings in the array are\n");
	for(i = 0; i < n; i++) {
        printf("String at a[%d] = %s\n", i, a[i]);
    }
}

// description: This program sorts an array of strings in descending order using selection sort. It first takes the number of strings and the strings themselves as input, then sorts them in descending order, and finally prints the sorted strings.