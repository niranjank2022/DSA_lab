#include <stdio.h>
#include <stdlib.h>
#define n 5
struct queue
{
    int front, rear;
    int elements[n];
} s, *p;

void create()
{
    s.front = 0;
    s.rear = 0;
}

int enque(int e)
{

    if ((s.rear + 1) % n == s.front)
    {
        printf("queue overflow");
        exit(1);
    }

    else
    {
        s.elements[s.rear] = e;
        s.rear = (s.rear + 1) % n;
    }
}
int deque()
{
    if (s.front == s.rear)
    {
        printf("qeue empty");
        exit(1);
    }
    else
    {
        int popped = s.elements[s.front];
        s.front = (s.front + 1) % n;
        return popped;
    }
}
void display()
{
    if (s.front == s.rear)
    {
        printf("qeueu is empty");
        exit(1);
    }
    else
    {
        int i = s.front;
        while (i != s.rear)
        {
            printf("%d ", s.elements[i]);
            i = (i + 1) % n;
        }
    }
}
int peep()
{
    if (s.front == s.rear)
    {
        printf("qeue is empty");
        exit(1);
    }
    else
    {
        return s.elements[s.front];
    }
}

void main()
{
    while (1)
    {
        int c, e, ee, eee;
        printf("\n1=>create 2=> enqeue 3=>deqquue 4=>peep 5=>dispaly 6=> exit");
        printf("\nenter your choice");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            create();
            break;
        case 2:
            printf(" \n enter element");
            scanf("%d", &e);
            enque(e);
            break;
        case 3:
            ee = deque();
            printf("%d", ee);
            break;
        case 4:
            eee = peep();
            printf("%d", eee);
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("enter the correct choice");
        }
    }
}