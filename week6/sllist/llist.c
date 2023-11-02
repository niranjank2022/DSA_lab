#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(ListNodePtr *head) {
	ListNodePtr newNode = malloc(sizeof(ListNode));
	TreeNodePtr *t = malloc(sizeof(TreeNodePtr));

	if (newNode == NULL || t == NULL) {
		printf("!!! MEMORY NOT ALLOCATED. PROGRAM DISRUPTED. !!!\n");
		exit(0);
	}
	newNode->data = t;
	newNode->next = NULL;
	
	printf("Enter node name: ");
	newNode->name = malloc(sizeof(char) * 15);
	scanf("%s", newNode->name);

	ListNodePtr currPtr = *head, prevPtr = NULL;
	while (currPtr != NULL) {
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}
	if (prevPtr == NULL)
		*head = newNode;
	else
		prevPtr->next = newNode;
}

TreeNodePtr deleteNODE(ListNodePtr *head, TreeNodePtr *target) {
	ListNodePtr currPtr = *head, prevPtr = NULL;
	TreeNodePtr removed;

	while (currPtr != NULL && currPtr->data != target) {
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}
	if (currPtr == NULL) {
		printf("!! Element not found !!\n");
		return NULL;
	}
	removed = *(currPtr->data);
	if (prevPtr == NULL)
		*head = currPtr->next;
	else
		prevPtr->next = currPtr->next;
	free(currPtr);
	return removed;
}

void changeCurr(ListNodePtr head, TreeNodePtr **curr) {
	char s[20];
	printf("Enter Treenode name: ");
	scanf("%s", s);

	while (head != NULL && strcmp(head->name, s) != 0)
		head = head->next;
	if (head == NULL) {
		printf("No node found with that name.\n");
		return;
	}
	else
		*curr = head->data;
	printf("Changed!\n");
}

void copyTree(ListNodePtr head, TreeNodePtr *curr) {
	
	char s[20];
	printf("Enter tree name where to be copied: ");
	scanf("%s", s);
	while (head != NULL && strcmp(head->name, s) != 0)
		head = head->next;

	*(head->data) = cloneTree(*curr);
}

void buildtree(ListNodePtr head, TreeNodePtr *curr) {
	
	while (head != NULL && head->data != curr)
		head = head->next;

	*(head->data) = buildTree();
}

int isEmpty(ListNodePtr head) {
	return head == NULL;
}

void printList(ListNodePtr head, TreeNodePtr *curr) {
	ListNodePtr currPtr = head;
	printf("Available Nodes:\n");
	while (currPtr != NULL) {
		printf("%s", currPtr->name, currPtr->data);
		if (currPtr->data == curr)
			printf(" $$");
		printf("\n");
		currPtr = currPtr->next;
	}
}

void printNode(ListNodePtr head, TreeNodePtr *target) {
	while (head != NULL && head->data != target)
		head = head->next;
	printf("Current Node Name: %s\n", head->name);
}

int length(ListNodePtr head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}
	return count;
}
