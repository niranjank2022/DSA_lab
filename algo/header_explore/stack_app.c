#include<stdio.h>
#include "stack.c"
int main()
{
    struct stack st;
   
   // create(st);
    int ch;
    int k=1;
    while(k)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Print stack\n5.Quit");
        scanf("%d",&ch);
        if(ch==1)
        push(st);
        else if(ch==2)
        {
            int a=pop(st);
            printf("Deleted element : %d",a);

            
        }
        else if(ch==3)
        peek(st);
        else if(ch==4)
        print(st);
        else if(ch==5)
        {
            printf("Program Terminated !");
            k=0;
        }
        else
        printf("WRONG INPUT!");
        
    }
}