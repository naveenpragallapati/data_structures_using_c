#include <stdio.h>
#include <stdlib.h>
struct student {
	int regdno;
	int maths_marks, c_marks, java_marks;
	int total;
	float avg;
};
void read1(struct student *, int);
void compute(struct student *, int);
void display(struct student *, int);
void main() {
	struct student *p;
	int i, n;
	printf("Enter number of students : ");
	scanf("%d", &n);
	p = (struct student *) malloc(n * sizeof(struct student));
	read1(p, n); // Fill the arguments in the function call
	compute(p, n); // Fill the arguments in the function call
	display(p, n); // Fill the arguments in the function call
}
void read1(struct student *p, int n) { // Write the parameters in the function header
	int i;
	for (i = 0; i < n; i++) {
		printf("Enter regdno, three subjects marks of student-%d: ", i);
		scanf("%d %d %d %d", &p[i].regdno, &p[i].maths_marks, &p[i].c_marks, &p[i].java_marks ); // Complete the statement
	}
}
void compute(struct student *p, int n) { // Write the parameters in the function header
	int i;
	for (i = 0; i < n; i++) {
		(p + i)->total = p[i].maths_marks + p[i].c_marks + p[i].java_marks; ; // Complete the statement
		(p + i)->avg = p[i].total / 3.0;; // Complete the statement
	}
}
void display(struct student *p, int n) { // Write the parameters in the function header
	int i;
	for (i = 0; i < n; i++) {
		printf("Student-%d Regdno = %d\tTotal marks = %d\tAverage marks = %f\n",i, p[i].regdno, p[i].total, p[i].avg ); // Complete the statement
	}
}