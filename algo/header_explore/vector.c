#include "vector.h"
struct vector getdata(struct vector v)
{
    v.c=1;
    printf("Enter number of rows for vector1 and vector2 : ");
    scanf("%d%d",&v.row1,&v.row2);
      v.vec1=(int**)malloc(v.row1*sizeof(int*));
    v.vec2=(int**)malloc(v.row2*sizeof(int*));
   v.sum=(int**)malloc(v.row2*sizeof(int *));
   v.mul=(int**)malloc(v.row2*sizeof(int*));
    v.s_mul=(int**)malloc(v.row2*sizeof(int *));
    v.sub=(int**)malloc(v.row2*sizeof(int *));
   
       for(int i=0;i<v.row1;i++)
   {
       v.vec1[i]=(int *)malloc(v.c *sizeof(int));
       v.sum[i]=(int *)malloc(v.c*sizeof(int));
      v.vec2[i]=(int*)malloc(v.c*sizeof(int));
       v.mul[i]=(int *)malloc(v.c*sizeof(int));
       v.s_mul[i]=(int *)malloc(v.c*sizeof(int));
       v.sub[i]=(int *)malloc(v.c*sizeof(int));
   }
    printf("Enter the elements of vector1 : ");
   for(int  i=0;i<v.row1;i++)
   scanf("%d",&(v.vec1[i][0]));
   printf("Enter the elements of vector2 : ");
   for(int  i=0;i<v.row2;i++)
   scanf("%d",&(v.vec2[i][0]));
   
   return v;
}
int add(struct vector v)
{

    for(int i=0;i<v.row1;i++)
    {
        v.sum[i][0]=v.vec1[i][0]+v.vec2[i][0];
      
    }
    printf("The Addition : ");
    for(int k=0;k<v.row1;k++)
    printf(" %d\n",v.sum[k][0]);
   
}
int mult(struct vector v)
{
    for(int i=0;i<v.row1;i++)
    {
        
        v.mul[i][0]=v.vec1[i][0]*v.vec2[i][0];
        
    }
    printf("The Multiplication : ");
    for(int k=0;k<v.row1;k++)
    printf(" %d\n",v.mul[k][0]);
    
   
}

int subt(struct vector v)
{
    for(int i=0;i<v.row1;i++)
    {
        
        v.sub[i][0]=v.vec1[i][0]+v.vec2[i][0];
        
    }
      printf("The Subtraction : ");
    for(int k=0;k<v.row1;k++)
    printf(" %d\n",v.sub[k][0]);
}
int s_mult(struct vector v)
{
    int sl;
    printf("Enter a scalar value to multiply : ");
    scanf("%d",&sl);
    for(int i=0;i<v.row1;i++)
    {
        
        v.s_mul[i][0]=sl*v.vec1[i][0];
    }
    printf("The Scalar multiplication: ");
    for(int k=0;k<v.row1;k++)
    printf(" %d\n",v.s_mul[k][0]);
}