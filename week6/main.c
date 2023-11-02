#include <stdio.h>
#include <curses.h>
#include "btree/btree.h"
#include "sllist/llist.h"

ListNodePtr ROOT = NULL;
TreeNodePtr *CURR;

void info() {
	printf( "## *********************************************       $$$     ****************************************** ##\n"
			"Welcome to the menu-driven program for the BINARY SEARCH TREE\n"
			"Available Keys:\n"
			"(0) Configure current Treenodes (1) Insert value\t(2) Remove value\t(3) Search value\t(4) Inorder Traversal\t\n"
			"(5) Preorder Traversal\t(6) Postorder Traversal\n"
			"(7) Levelorder Traversal\t(8) No. of nodes\t(9) Height of tree\t(10) Display Tree\t(12) Exit\n"
			"%%%______________________________________________________________________________________________________%%%\n"
	      );
}

void configNodes();

void main() {

	ROOT = malloc( sizeof(ListNode) );
	TreeNodePtr t = NULL;
	CURR = &t;	
	ROOT->name = "Default";
	ROOT->data = CURR;
	ROOT->next = NULL;

	int val, choice;
	int flag = 0;

	info();
	while (1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 0:
				configNodes();
				info();
				break;
			case 1:
				printf("Enter value to push: ");
				scanf("%d", &val);
				insertNode(CURR, val);
				break;
			case 2:
				printf("Enter value to delete: ");
				scanf("%d", &val);
				*CURR = deleteNode(*CURR, val);
				break;
			case 4:
				printf("Inorder Traversal: ");
				inorder(*CURR);
				printf("\n");
				break;
			case 5:
				printf("Preorder Traversal: ");
				preorder(*CURR);
				printf("\n");
				break;
			case 6:
				printf("Postorder Traversal: ");
				postorder(*CURR);
				printf("\n");
				break;
			case 7:
				printf("Levelorder Traversal: ");
				levelorder(*CURR);
				printf("\n");
				break;
			case 8:
				printf("Count of nodes: %d\n", countOfNodes(*CURR));
				break;
			case 9:
				printf("Height of tree: %d\n", heightOfTree(*CURR));
				break;
			case 12:
				flag = 1;
				break;
			case 10:
				outputTree(*CURR, 0);
				break;
			case 3:
				printf("Enter value to search: ");
				scanf("%d", &val);
				if (search(*CURR, val))
					printf("Element %d is found.\n", val);
				else
					printf("Element %d is not found.\n", val);
				break;
			default:
				printf("Invalid key entered!!!\n");
		}

		if (flag)	break;
	}
}

void configNodes() {

	printf( "Available options: \n"
			"(1) Current tree info	(2) Available trees	(3) Create new tree	(4) Delete current tree\n"
			"(5) Change tree	(6) Copy tree		(7) No. of trees	(8) Exit	(9) Build tree\n");

	int choice;

	while (1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printNode(ROOT, CURR);
				break;
			case 2:
				printList(ROOT, CURR);
				break;
			case 3:
				insert(&ROOT);
				printf("Created!\n");
				break;
			case 4:
				deleteNODE(&ROOT, CURR);
				printf("Deleted!\n");
				break;
			case 5:
				changeCurr(ROOT, &CURR);
				break;
			case 6:
				copyTree(ROOT, CURR);
				printf("Copied!\n");
				break;
			case 8:
				return;
			case 7:
				printf("No. of trees: %d\n", length(ROOT));
				break;
			case 9:
				buildtree(ROOT, CURR);
				printf("Built\n");
				break;
			default:
				printf("Invalid operation entered! Try again!\n");
		}
	}
}

