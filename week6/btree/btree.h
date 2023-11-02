#ifndef BTREE_H
#define BTREE_H

struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
};

typedef struct treenode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode( TreeNodePtr *, int );
TreeNodePtr deleteNode( TreeNodePtr, int );
int heightOfTree( TreeNodePtr );
int countOfNodes( TreeNodePtr );
int search( TreeNodePtr, int );
TreeNodePtr cloneTree( TreeNodePtr );
void outputTree( TreeNodePtr, int );

// Traversals
void inorder( TreeNodePtr );
void preorder( TreeNodePtr );
void postorder( TreeNodePtr );
void levelorder( TreeNodePtr );

#include "btree.c"
#endif
