#include <stdio.h>
struct account {
	char name[20];
	int acc_no;
	float balance;
};
void main() {
	struct account acc, *p;
	p = &acc;
	printf("Enter the name of account holder : ");
	scanf("%s", p->name ); 
	printf("Enter the account number : ");
	scanf("%d", &p->acc_no); 
	printf("Enter the balance : ");
	scanf("%f", &p->balance); 
	printf("The given account details are...\n");
	printf("Name: %s\nAccount number: %d\nBalance: %f\n",p->name, p->acc_no, p->balance ); 
}