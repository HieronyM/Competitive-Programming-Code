
#include<stdio.h>

int main()
{
 int A,B;
 
 scanf("%d %d",&A,&B);
 if(A < 1 || A > 100)
   {
   scanf("%d",&A);           
   }
 if(B < 1 || B > 100)
   {
   scanf("%d",&B);           
   }  
  
  printf("%d\n",A+B); 
       
       return 0;
}
