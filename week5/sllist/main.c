#include <stdio.h>
#include "llist.h"

void main() {
	
	ListNodePtr list = NULL;
	int val, elmt, choice;
	int flag = 0;

	printf( "Available Keys:\n(1) Insert at Beginning\t(2) Insert at End\t(3) Insert after element\t(4) Insert before element\t(5) Delete\t"
		"(6) Length of list (7) Display\t(8) Exit\n");

	while (1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
		
			case 1:
				printf("Enter value to insert: ");
				scanf("%d", &val);
				insertBeg(&list, val);
				break;
			case 2:
				printf("Enter value to insert: ");
				scanf("%d", &val);
				insertEnd(list, val);
				break;
			case 3:
				printf("Enter previous element: ");
				scanf("%d", &elmt);
				printf("Enter value to insert: ");
				scanf("%d", &val);
				insertAfter(list, elmt, val);
				break;
			case 4:
				printf("Enter next element: ");
				scanf("%d", &elmt);
				printf("Enter value to insert: ");
				scanf("%d", &val);
				insertBefore(list, elmt, val);
				break;
			case 5:
				printf("Enter value to delete: ");
				scanf("%d", &val);
				deleteNode(&list, val);
				break;
			case 6:
				printf("Length of list: %d\n", length(list));
				break;
			case 7:
				printList(list);
				break;
			case 8:
				flag = 1;
				break;
			default:
				printf("Invalid key entered!!!\n");
		}

		if (flag)	break;
	}
}
