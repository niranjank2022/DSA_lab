#include<stdio.h>
#include<stdlib.h>
#include "vector.c"
//#include "vector.h"
int main()
{
    struct vector V;
    int k=1;
    V = getdata(V);    
   
    int ch;
   printf("\n1.Addition\n2.Subtaction\n3.Multiplication\n4.Scalar Multiplicaion\n5.Quit\n");
   scanf("%d",&ch);
   if(ch==1)
   add(V);
   else if(ch==2)
   subt(V);
   else if(ch==3)
   mult(V);
   else if(ch==4)
   s_mult(V);
   else if(ch==5)
   {
       printf("Program terminated!");
       k=0;
   }
   else
   printf("Enter correct input");
   }
