#include<stdio.h>

int main()
{
 int A,B;
 char oper;
 scanf("%d %c",&A,&oper);
 scanf("%d",&B);
 int total;
 
 if(oper =='+')
   {
    total = A+B;
    printf("%d\n",total);     
   }
 else if(oper =='-')
   {
    total = A-B;     
    printf("%d\n",total);    
   }
 else if(oper =='*')
   {
    total = A*B;
    printf("%d\n",total);     
   }
 
 else if(oper =='=' )
   {
    if(A == B)
     {
      printf("benar\n");   
     }
     
     else if(A != B)
      {
       printf("salah\n");       
      }          
   }
 
 else if(oper =='>' )
   {
    if(A > B)
     {
      printf("benar\n");   
     }
     
    else if(A == B || A < B)
      {
       printf("salah\n");       
      }           
   }
   
 else if(oper =='<' )
   {
    if(A < B)
     {
      printf("benar\n");   
     }
    
    else if(A == B || A > B)
      {
       printf("salah\n");       
      } 
               
   }  

 return 0;   
}
