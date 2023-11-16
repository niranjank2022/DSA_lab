
struct vector
{
   int row1,row2,c;
    int **vec1 ;
  int  **vec2 ;
   int **sum ;
   int **mul;
   int **s_mul;
   int **sub;
   
   
};
struct vector v;
int get_data(struct vector v);
int add(struct vector v);
int subt(struct vector v);
int mult(struct vector v);
int s_mult(struct vector v);

