#include <stdio.h>
#include <stdlib.h>
int main() {
	int *p;
	//complete the missing malloc() statement 
	p = (int *) malloc (sizeof (int));
	//Also check if memory is allocated successfully or not.
	//If not print "Failed to allocate space for _ bytes
	if (p == NULL) {
        printf("Failed to allocate space for _ bytes\n");        
    }
	*p = 15;
	printf("Value with in heap memory = %d\n", *p);
	free(p);
	return 0;
}