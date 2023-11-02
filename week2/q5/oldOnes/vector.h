#ifndef VECTOR_H
#define VECTOR_H

struct vector {
	int *arr;
	int length;
	int _size;
};

typedef struct vector Vector;

Vector init( void );
void vprint( Vector * );
void vappend( Vector *, int );
void vinsert( Vector *, int, int );
int vpop( Vector * );
int vremove( Vector *, int );

#include "vector.c"
#endif
