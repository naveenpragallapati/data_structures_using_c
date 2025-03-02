#include <stdio.h>
#include <stdlib.h>
#define max 20

struct polynomial {
	int coeff;
	int exp;
	struct polynomial *next;
};
typedef struct polynomial *poly;

poly addTerm(poly head, poly temp) {
	if (head == NULL) {
        return temp;
    }
    
    poly ptr = head, prev = NULL;
    while (ptr != NULL && ptr->exp > temp->exp) {
        prev = ptr;
        ptr = ptr->next;
    }
    
    if (ptr != NULL && ptr->exp == temp->exp) {
        ptr->coeff += temp->coeff;
        free(temp);
    } else {
        if (prev == NULL) {
            temp->next = head;
            head = temp;
        } else {
            temp->next = ptr;
            prev->next = temp;
        }
    }
    return head;

}

void print(poly head) {
	poly ptr = head;
    while (ptr != NULL) {
        printf("%d X^ %d ---> ", ptr->coeff, ptr->exp);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

poly create(poly head) {
	poly temp;
	char ch;
	int coeff, exp;
	do {
		temp = (poly)malloc(sizeof(struct polynomial));
		printf("Enter coeff and exp of node : ");
		scanf("%d%d", &coeff, &exp);
		temp -> coeff = coeff;
		temp -> exp = exp;
		temp -> next = NULL;
		head = addTerm(head, temp);
		printf("Do u want another node (y/n) : ");
		scanf(" %c", &ch);
	} while(ch != 'n');
	return head;
}

void main() {
	poly head = NULL;
	int ch;
	head = create(head);
	printf("The polynomial is : ");
	print(head);
}