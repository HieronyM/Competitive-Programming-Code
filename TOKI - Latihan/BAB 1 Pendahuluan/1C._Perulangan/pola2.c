#include<stdio.h>

int main()
{
    int N,a,b,nilai=0;
    scanf("%d",&N);
    for(a=1; a<=N; a++)
      {
       for(b=1; b <= a; b++)
          {
           printf("%d",nilai%10);
           nilai++;     
          }
          printf("\n");      
      }

    return 0;
}

