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
    poly ptr = head;
    while (ptr != NULL) {
        printf("%d X^ %d ---> ", ptr->coeff, ptr->exp);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

poly add(poly head1, poly head2) {
    poly head = NULL, temp;
    
    while (head1 != NULL && head2 != NULL) {
        temp = (poly)malloc(sizeof(struct polynomial));
        temp->next = NULL;
        
        if (head1->exp > head2->exp) {
            temp->coeff = head1->coeff;
            temp->exp = head1->exp;
            head1 = head1->next;
        } else if (head1->exp < head2->exp) {
            temp->coeff = head2->coeff;
            temp->exp = head2->exp;
            head2 = head2->next;
        } else {
            temp->coeff = head1->coeff + head2->coeff;
            temp->exp = head1->exp;
            head1 = head1->next;
            head2 = head2->next;
        }
        head = addTerm(head, temp);
    }
    
    while (head1 != NULL) {
        temp = (poly)malloc(sizeof(struct polynomial));
        temp->coeff = head1->coeff;
        temp->exp = head1->exp;
        temp->next = NULL;
        head = addTerm(head, temp);
        head1 = head1->next;
    }
    
    while (head2 != NULL) {
        temp = (poly)malloc(sizeof(struct polynomial));
        temp->coeff = head2->coeff;
        temp->exp = head2->exp;
        temp->next = NULL;
        head = addTerm(head, temp);
        head2 = head2->next;
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
	poly head1=NULL, head2= NULL, result = NULL;
	int ch;
	printf("Enter the first polynomial : \n");
	head1 = create(head1);
	printf("Enter the second polynomial : \n");
	head2 = create(head2);
	result = add(head1, head2);
	printf("The first polynomial : ");
	print(head1);
	printf("The second polynomial : ");
	print(head2);
	printf("Addition result : ");
	print(result);
}