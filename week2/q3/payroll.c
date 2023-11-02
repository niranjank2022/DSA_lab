#include <stdio.h>

EmpData init() {

	EmpData e1;                                                                                                                                    

	printf("Enter id: ");
	scanf("%d", &e1.id);
	printf("Enter name: ");
	scanf("%s", e1.name);
	printf("Enter Base Pay: ");
	scanf("%f", &e1.basePay);
	printf("Enter no. of working days arrived: ");
	scanf("%d", &e1.noDays);                                                                                                                       

	return e1;
}

void printData(EmpData *e1) {

	printf("Employee ID: %d\n"
		"Name: %s\n"
		"Base Pay; %.2f\n"
		"No. of working days: %d\n", e1->id, e1->name, e1->basePay, e1->noDays);
}

float calculateSalary(EmpData *e1) {

	float salary;
	salary = e1->noDays * e1->basePay;
	return salary;
}
