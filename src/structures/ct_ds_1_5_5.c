#include <stdio.h>
void main() {
	int **a, *b, c = 22;
	// Do assignments such that all the next three lines print 22.
	b = &c;
	a = &b;
	printf("Accessing through double pointer the given value = %d\n", **a);
	printf("Accessing through single pointer the given value = %d\n", *b);
	printf("The given value = %d\n", c);
}