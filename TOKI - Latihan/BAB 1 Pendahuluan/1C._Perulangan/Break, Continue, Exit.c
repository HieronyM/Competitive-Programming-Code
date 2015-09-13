#include<stdio.h>

int main()
{
    int N,a;
    scanf("%d",&N);
    for(a=1; a<=N; a++)
      {
       if(a%10==0)
         {
          continue;
         }
       else if(a==93)
         {
          printf("ERROR\n");
          break;           
         }
       else
         {
          printf("%d\n",a);                 
         }  
          
  } 
          
    return 0;
}

