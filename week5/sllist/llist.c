#include <stdio.h>
#include <stdlib.h>

void insertBeg(ListNodePtr *head, int val) {

	ListNodePtr newNode = malloc(sizeof(ListNode));
	if (newNode == NULL) {
		printf("!!! MEMORY NOT ALLOCATED. PROGRAM DISRUPTED. !!!\n");
		exit(0);
	}
	newNode->data = val;
	newNode->next = *head;
	*head = newNode;
}

void insertEnd(ListNodePtr head, int val) {

	ListNodePtr newNode = malloc(sizeof(ListNode));
	if (newNode == NULL) {
		printf("!!! MEMORY NOT ALLOCATED. PROGRAM DISRUPTED. !!!\n");
		exit(0);
	}
	newNode->data = val;
	newNode->next = NULL;
	
	ListNodePtr currPtr = head, prevPtr = NULL;
	while (currPtr != NULL) {
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}
	prevPtr->next = newNode;
}

void insertBefore(ListNodePtr head, int next_element, int val) {
	
	ListNodePtr newNode = malloc(sizeof(ListNode));
	if (newNode == NULL) {
		printf("!!! MEMORY NOT ALLOCATED. PROGRAM DISRUPTED. !!!\n");
		exit(0);
	}
	newNode->data = val;

	ListNodePtr currPtr = head, prevPtr = NULL;
	while (currPtr != NULL && currPtr->data != next_element) {
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}
	prevPtr->next = newNode;
	newNode->next = currPtr;
}


void insertAfter(ListNodePtr head, int prev_element, int val) {
	
	ListNodePtr newNode = malloc(sizeof(ListNode));
	if (newNode == NULL) {
		printf("!!! MEMORY NOT ALLOCATED. PROGRAM DISRUPTED. !!!\n");
		exit(0);
	}
	newNode->data = val;

	while (head != NULL && head->data != prev_element)
		head = head->next;
	
	newNode->next = head->next;
	head->next = newNode;
}

void insert(ListNodePtr *head, int val) {
	ListNodePtr newPtr = (ListNodePtr) malloc(sizeof(ListNode));	
	if (newPtr == NULL) {
		printf("!!! MEMORY NOT ALLOCATED. PROGRAM DISRUPTED. !!!\n");
		exit(0);
	}
	newPtr->data = val;
	newPtr->next = NULL;

	ListNodePtr currPtr = *head, prevPtr = NULL;
	while (currPtr != NULL && currPtr->data < newPtr->data) {
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}
	// Element to be inserted in the front
	if (prevPtr == NULL) {
		newPtr->next = *head;
		*head = newPtr;
	}
	// Element to be inserted in between or end
	else {
		prevPtr->next = newPtr;
		newPtr->next = currPtr;
	}
}

int deleteNode(ListNodePtr *head, int val) {
	ListNodePtr currPtr = *head, prevPtr = NULL;
	int removed;

	while (currPtr != NULL && currPtr->data != val) {
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}
	// Element not found
	if (currPtr == NULL) {
		printf("!! Element not found !!\n");
		return -1;
	}	
	// Element to be deleted is the head
	if (prevPtr == NULL) {
		removed = currPtr->data;
		*head = currPtr->next;
		free(currPtr);
	}
	// Element to be deleted is in between or end
	else {
		removed = currPtr->data;
		prevPtr->next = currPtr->next;
		free(currPtr);
	}
	return removed;
}

int isEmpty(ListNodePtr head) {
	return head == NULL;
}

void printList(ListNodePtr head) {

	ListNodePtr currPtr = head;
	while (currPtr != NULL) {
		printf("%d --> ", currPtr->data);
		currPtr = currPtr->next;
	}
	printf("END\n");
}

int length(ListNodePtr head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}
	return count;
}
