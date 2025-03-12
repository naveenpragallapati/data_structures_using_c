#include <stdio.h>
struct example {
	int data;
	struct example *p;
};
void main() {
	struct example s1, s2;
	printf("Enter an integer for first structure variable : ");
	scanf("%d", &s1.data);
	printf("Enter an integer for second structure variable : ");
	scanf("%d", &s2.data);
	s1.p = &s2;
	s2.p = NULL;
	printf(" %d --> %d\n", s1.data, s1.p->data);
}