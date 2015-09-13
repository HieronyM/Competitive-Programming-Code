#include<stdio.h>

int main()
{
    int N,Bi,a;
    
    int total=0;
    scanf("%d",&N);
    for(a=1; a<=N; a++)
      {
       scanf("%d",&Bi);
       total = total + Bi;      
      }
    
    printf("%d\n",total);
    return 0;
}
