#ifndef PAYROLL_H
#define PAYROLL_H

struct empData {

	int id;
	char name[20];
	float basePay;
	int noDays;
};

typedef struct empData EmpData;

EmpData init();
void printData(EmpData *);
float calculateSalary(EmpData *);

#include "payroll.c"

#endif
