#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../queue/queue.h"
#include "../vector/vector.h"

void insertNode( TreeNodePtr *treePtr, int val ) {

	if (*treePtr == NULL) {
		*treePtr = malloc( sizeof(TreeNode) );
		if (*treePtr == NULL) {
			printf("!!! Memory not allocated for Tree Node. !!!\n");
			exit(0);
		}
		else {
			(*treePtr)->data = val;
			(*treePtr)->left = (*treePtr)->right = NULL;
		}
	}
	else {
		if ((*treePtr)->data > val)
			insertNode( &((*treePtr)->left), val );
		else if ((*treePtr)->data < val)
			insertNode( &((*treePtr)->right), val );
		else
			printf("Duplicate!\n");
	}
}

TreeNodePtr deleteNode( TreeNodePtr root, int target ) {

	if (root == NULL)
		return root;

	if (root->data > target) {
		root->left = deleteNode(root->left, target);
		return root;
	}
	else if (root->data < target) {
		root->right = deleteNode(root->right, target);
		return root;
	}

	// root is the node to be deleted
	if (root->left == NULL) {
		TreeNodePtr temp = root->right;
		free(root);
		return temp;
	}
	else if (root->left == NULL) {
		TreeNodePtr temp = root->left;
		free(root);
		return temp;
	}
	// deleting node with two children
	else {
		TreeNodePtr RPnode = root->left, RPparent = root;
		while (RPnode->right != NULL) {
			RPparent = RPnode;
			RPnode = RPnode->right;
		}
		root->data = RPnode->data;
		if (RPparent == root)
			root->left = RPnode->left;
		else
			RPparent->right = RPnode->left;
		free(RPnode);
		return root;
	}
}

int search(TreeNodePtr node, int target) {

	if (node == NULL)
		return 0;
	if (node->data == target)
		return 1;
	if (node->data > target)
		return search(node->left, target);
	else
		return search(node->right, target);
}

TreeNodePtr cloneTree( TreeNodePtr root ) {
	if (root == NULL)
		return root;
	TreeNodePtr node = malloc( sizeof(TreeNode) );
	node->data = root->data;
	node->left = cloneTree(root->left);
	node->right = cloneTree(root->right);
	return node;
}

int heightOfTree( TreeNodePtr root ) {
	if (root == NULL)
		return 0;
	int leftLevel, rightLevel;
	leftLevel = heightOfTree(root->left);
	rightLevel = heightOfTree(root->right);
	return fmax(leftLevel, rightLevel) + 1;
}

int countOfNodes( TreeNodePtr root ) {
	if (root == NULL)
		return 0;
	return countOfNodes(root->left) + countOfNodes(root->right) + 1;
}

void inorder( TreeNodePtr treePtr ) {
	if (treePtr != NULL) {
		inorder(treePtr->left);
		printf("%d ", treePtr->data);
		inorder(treePtr->right);
	}
}

void preorder( TreeNodePtr treePtr ) {
	if (treePtr != NULL) {
		printf("%d ", treePtr->data);
		preorder(treePtr->left);
		preorder(treePtr->right);
	}
}

void postorder( TreeNodePtr treePtr ) {
	if (treePtr != NULL) {
		postorder(treePtr->left);
		postorder(treePtr->right);
		printf("%d ", treePtr->data);
	}
}

void levelorder( TreeNodePtr treePtr ) {
	QueuePtr que = malloc(sizeof(Queue));
	enqueue(que, treePtr);
	TreeNodePtr curr;

	while (!isQEmpty(que)) {	
		int n = qlength(que);
		for (int i = 0; i < n; i++) {
			curr = dequeue(que);
			if (curr == NULL)
				continue;
			printf("%d ", curr->data);
			if (curr->left != NULL)
				enqueue(que, curr->left);
			if (curr->right != NULL)
				enqueue(que, curr->right);
		}
	}
}

void outputTree( TreeNodePtr treePtr, int spaces ) {
	if (treePtr == NULL)
		return;
	outputTree(treePtr->right, spaces + 5);
	for (int i = 0; i < spaces; i++)
		printf(" ");
	printf("%d\n", treePtr->data);
	outputTree(treePtr->left, spaces + 5);
}

void printTree( TreeNodePtr treePtr ) {
	int h = heightOfTree(treePtr);
	int x = pow(2, h) - 1;

	QueuePtr que = malloc(sizeof(Queue));
	enqueue(que, treePtr);                                                                                                                         
	TreeNodePtr curr;                                                                                                                              

	int arr[x], k = 0;
	while (!isQEmpty(que)) {
		int n = qlength(que);
		for (int i = 0; i < n; i++) {
			curr = dequeue(que);                                                                                                           
			if (curr == NULL) {			
				arr[k++] = -1;
				continue;
			}
			else
				arr[k++] = curr->data;
			enqueue(que, curr->left);                                                                                              
			enqueue(que, curr->right);                                                                                             
		}
	}
	int z = 0;
	for (int i = 0; i < h; i++) {

		for (int j = 0; j < pow(2, h - i - 1) - 1; j++)
			printf("   ");

		for (int j = 0; j < pow(2, i); j++) {
			if (arr[z] < 0) {
				printf("  ");
			}
			else
				printf("%2d  ", arr[z]);

			if (j % 2 == 0)
				for (int jk = 0; jk < pow(2, h - i - 1) / 2 - 1; jk++)
					printf("  ");
			z++;
		}
		printf("\n");

	}

}

TreeNodePtr buildTree(void) {
	TreeNodePtr recFunc(Vector *, Vector *, int, int, int, int);

	Vector inorder, preorder;
	init(&inorder);
	init(&preorder);

	int n;
	printf("Enter no. of elements: ");
	scanf("%d", &n);

	printf("Enter inorder elements: ");
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		vappend(&inorder, num);
	}

	printf("Enter preorder elements: ");
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		vappend(&preorder, num);
	}
	
	vprint(&inorder);
	vprint(&preorder);

	return recFunc(&inorder, &preorder, 0, n - 1, 0, n - 1);
}

TreeNodePtr recFunc(Vector *inorder, Vector *preorder, int istart, int iend, int pstart, int pend) {
       if (istart > iend)
		return NULL;
	TreeNodePtr node = malloc(sizeof(TreeNode));
	node->data = vget(preorder, pstart);

	int i = vindex(inorder, node->data, istart, iend);
	if (i == -1) {
		printf("SHIT %d %d %d %d %d!!\n", node->data, istart, iend, pstart, pend);
		exit(0);
	}
	int newPend = i - istart + pstart;
	node->left = recFunc(inorder, preorder, istart, i - 1, pstart + 1, newPend);
	node->right = recFunc(inorder, preorder, i + 1, iend, newPend + 1, pend);
	
	return node;
} 
