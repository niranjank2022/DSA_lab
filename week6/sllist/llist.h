/**
 * This source file is to support the implementaion of main file of BSTree, in order to easen the handling of the menu driven program for the BST data structure.
*/

#ifndef LLIST_H
#define LLIST_H

#include "../btree/btree.h"

struct node {
	TreeNodePtr *data;
	char *name;
	struct node *next;
};

typedef struct node ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *);
TreeNodePtr deleteNODE(ListNodePtr *, TreeNodePtr *);
void changeCurr(ListNodePtr, TreeNodePtr **);
void buildtree(ListNodePtr, TreeNodePtr *);
int isEmpty(ListNodePtr);
int length(ListNodePtr);
void printList(ListNodePtr, TreeNodePtr *);
void printNode(ListNodePtr, TreeNodePtr *);

#endif

#include "llist.c"
