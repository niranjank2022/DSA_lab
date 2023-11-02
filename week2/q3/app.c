#include <stdio.h>
#include "payroll.h"

void main() {

	EmpData e1;

	e1 = init();

	printData(&e1);

	float ans = calculateSalary(&e1);
	printf("Salary of Employee %s => %.2f\n", e1.name, ans);
}
