#include <stdio.h>
#include "dynamic/queue.h"

void main() {

    Queue que;
    int ch, num, flag = 0;
    printf("Welcome to the menu-driven program for accessing functions of Queue Data structure (Dynamic implementation)!\n"
	   "Available operations:\n(1)Initialize a Queue\n(2)Enqueue\n(3)Dequeue\n(4)Front\n(5)Display\n(6)Size of queue\n(9)Exit\n");
    while (1) {
	printf("Enter your choice: ");
	scanf("%d", &ch);

	switch (ch) {
		case 1:
		    init(&que);
		    break;
		case 2:
		    printf("Enter element to enqueue: ");
		    scanf("%d", &num);
		    enqueue(&que, num);                                                                                                                               
		    break;
		case 3:
		    printf("Dequeued element: %d\n", dequeue(&que));
		    break;
		case 4:
		    printf("Element at the front of queue: %d\n", front(&que));
		    break;
		case 5:
		    display(&que);
		    break;
		case 6:
		   printf("Size of the queue: %d\n", que.size);
		   break;
		case 9:
		    flag = 1;
		    break;
	    }                                                                                                                                                              

	if (flag)
	    break;
	fflush(stdin);
    }  
}
