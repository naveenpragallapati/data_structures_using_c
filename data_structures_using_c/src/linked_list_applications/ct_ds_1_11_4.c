#include <stdio.h>
#include <stdlib.h>

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
	poly temp = head;
	while(temp != NULL) {
		printf("%d X^ %d ---> ", temp -> coeff, temp -> exp);
		temp = temp -> next;
	}
	printf("NULL\n");
}

poly sub(poly head1, poly head2) {
	poly head = NULL, temp;
    
    while (head2 != NULL) {
        temp = (poly)malloc(sizeof(struct polynomial));
        temp->coeff = -head2->coeff;
        temp->exp = head2->exp;
        temp->next = NULL;
        head2 = head2->next;
        head = addTerm(head, temp);
    }
    
    while (head1 != NULL) {
        temp = (poly)malloc(sizeof(struct polynomial));
        temp->coeff = head1->coeff;
        temp->exp = head1->exp;
        temp->next = NULL;
        head1 = head1->next;
        head = addTerm(head, temp);
    }
    
    return head;
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
	poly head1 = NULL, head2 = NULL, result = NULL;
	int ch;
	printf("Enter the first polynomial : \n");
	head1 = create(head1);
	printf("Enter the second polynomial : \n");
	head2 = create(head2);
	result = sub(head1, head2);
	printf("The first polynomial : ");
	print(head1);
	printf("The second polynomial : ");
	print(head2);
	printf("Subtraction result : ");
	print(result);
}