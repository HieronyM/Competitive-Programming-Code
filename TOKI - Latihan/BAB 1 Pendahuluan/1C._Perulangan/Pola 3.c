#include<stdio.h>

int main()
{
    int N,K,a;
    scanf("%d %d",&N,&K);
    for(a=1; a<=N; a++)
      {
       if(a%K==0)
         {
          if(a != N)
           {
             printf("* ");
           } 
          else
            {
             printf("*\n");          
            }       
         }
         
        else
          {
           if(a!=N)
           {
           printf("%d ",a);                  
           }
           
           else
           {
            printf("%d\n",a);   
           }
          }      
      }
        
    return 0;
}


