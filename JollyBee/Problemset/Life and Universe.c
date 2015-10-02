#include<stdio.h>

int main()
  {
    int nilai;
    do
      {
      scanf("%d",&nilai);
       if(nilai != 42)
       {
         printf("%d\n",nilai);                      
       }
      }      
     while(nilai != 42);     
   return 0;       
  }
