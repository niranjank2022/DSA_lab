#include <stdio.h>
#include "queue.h"

void main() {
	
	QueueNodePtr head = NULL, tail = NULL;
	int val, choice;
	int flag = 0;

	printf("Available Keys:\n(1) Enqueue\t(2) Dequeue\t(3) Front\t(4) Display\t(5) Exit\n");
	while (1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("Enter value to push: ");
				scanf("%d", &val);
				enqueue(&head, &tail, val);
				break;
			case 2:
				printf("Value dequeued : %d\n", dequeue(&head, &tail));
				break;
			case 3:
				printf("Element at front: %d\n", front(head));
				break;
			case 4:
				display(head);
				break;
			case 5:
				flag = 1;
				break;
			default:
				printf("Invalid key entered!!!\n");
		}

		if (flag)	break;
	}
}
