#ifndef VECTOR_H
#define VECTOR_H

struct vector {
	int *arr;
	int length;
};

typedef struct vector Vector;

Vector init( void );
void vprint( Vector * );
void vappend( Vector *, int );
void vinsert( Vector *, int, int );
int vpop( Vector * );
int vremove( Vector *, int );
int isPresent( Vector *, int );

#include "vector.c"
#endif
