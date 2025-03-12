#include <stdio.h>
struct student {
	int regdno;
	int maths_marks, c_marks, java_marks;
	int total;
	float avg;
};
void main() {
	struct student s;
	printf("Enter regdno, three subjects marks : ");
	scanf("%d %d %d %d", &s.regdno, &s.maths_marks, &s.c_marks, &s.java_marks ); // Fill the code in scanf()
	s.total = s.maths_marks+s.c_marks+s.java_marks; // Complete the statement
	s.avg = s.total/3.0; ; // Complete the statement
	printf("Total marks = %d\n", s.total); // Complete the statement
	printf("Average marks = %f\n", s.avg); // Complete the statement
}