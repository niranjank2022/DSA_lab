#include <stdio.h>
#include <math.h>
//#include "complex.h"

//struct Complex {
//	float rpart;
//	float ipart;
//};

//typedef struct Complex comp;

comp getComp() { 
	comp ans;
	printf("Enter real part: ");
	scanf("%f", &ans.rpart);
	printf("Enter imaginary part: ");
	scanf("%f", &ans.ipart);
	return ans;
}

void cprint(comp *c) {
	printf("Complex Number: %.2f + %.2fi\n", c->rpart, c->ipart);
}

comp cadd(comp *c1, comp *c2) {
	comp ans;
	ans.rpart = c1->rpart + c2->rpart;
	ans.ipart = c1->ipart + c2->ipart;
	return ans;
}

comp csub(comp *c1, comp *c2) {

	comp ans;
	ans.rpart = c1->rpart - c2->rpart;
	ans.ipart = c1->ipart - c2->ipart;
	return ans;
}

comp cprod(comp *c1, comp *c2) {
	comp ans;
	ans.rpart = c1->rpart * c2->rpart - c1->ipart * c2->ipart;
	ans.ipart = c1->ipart * c2->rpart + c1->rpart * c2->ipart;
	return ans;
}

comp cdiv(comp *c1, comp *c2) {
	comp ans;
	float c2_mod = cmod(c2);
	ans = cprod(c1, c2);
	ans.rpart /= c2_mod;
	ans.ipart /= c2_mod;
	return ans;
}

comp conjugate(comp *c1) {
	comp ans = *c1;
	ans.ipart *= -1;
	return ans;
}

float cmod(comp *c1) {
	return sqrt(pow(c1->rpart, 2) + pow(c1->ipart, 2));
}
