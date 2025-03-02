#include <stdio.h>
void main() {
	int *intPtr, info;
	info = 5;
	intPtr = &info;
	printf("Value in info = %d\n", info);
	printf("Value referred by *intPtr = %d\n", *intPtr);
	//increment value of value at intptr by 5.
	*intPtr += 5;
	printf("Value in info = %d\n", info);
	printf("Value referred by *intPtr = %d\n", *intPtr);
}