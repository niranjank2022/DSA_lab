#ifndef COMPLEX_H
#define COMPLEX_H

struct Complex{
	float rpart;
	float ipart;
};
typedef struct Complex comp;

comp getComp();
void cprint(comp *);
comp cadd(comp *, comp *);
comp csub(comp *, comp *);
comp cprod(comp *, comp *);
comp cdiv(comp *, comp *);
comp conjugate(comp *);
float cmod(comp *);

#include "complex.c"
#endif
