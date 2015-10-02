#include<stdio.h>

  int NoAlamat[10001];
int main()
  {
   int TC;
   scanf("%d",&TC);
   int a,b,N,M;
   for(a=0; a < TC; a++)
      {
        scanf("%d %d",&N,&M);
        for(b = 0; b < N; b++)
          {
           scanf("%d",&NoAlamat[b]); 
          }
        for(b = 0; b < N; b++)
          {
           if(NoAlamat[b] == M)
             {
              printf("%d\n",b+1);            
              break;             
             } 
          }  
      }
 return 0;     
 }
