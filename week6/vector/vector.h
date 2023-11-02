#ifndef VECTOR_H
#define VECTOR_H

struct vector {
	int *arr;
	int length;
};

typedef struct vector Vector;

void init( Vector * );
void vprint( Vector * );
void vappend( Vector *, int );
void vinsert( Vector *, int, int );
int vpop( Vector * );
int vremove( Vector *, int );
int vget( Vector *, int );
int vindex( Vector *, int, int, int );

#include "vector.c"
#endif
