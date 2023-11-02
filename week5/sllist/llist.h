#ifndef LLIST_H
#define LLIST_H

struct node {
	int data;
	struct node *next;
};

typedef struct node ListNode;
typedef ListNode *ListNodePtr;

void insertBeg(ListNodePtr *, int);
void insertBefore(ListNodePtr, int, int);
void insertAfter(ListNodePtr, int, int);
void insertEnd(ListNodePtr, int);
int deleteNode(ListNodePtr *, int);
int isEmpty(ListNodePtr);
int length(ListNodePtr);
void printList(ListNodePtr);

#endif

#include "llist.c"
