#include<stdio.h>

int main()
{
    long N;
    scanf("%ld",&N);
    
    double tampung[N];
    int a;
     double MAX,MIN;
    double RATA,TOTAL=0;
    for(a=0; a<N; a++)
       {
         scanf("%lf",&tampung[a]);
         TOTAL = TOTAL + tampung[a];        
       }
    
    RATA = TOTAL/N;
    MAX=tampung[0];
    MIN = tampung[0];
    
    for(a=1; a< N ; a++)
      {
        if(MAX < tampung[a])
          {
           MAX = tampung[a];    
          }
          
         if(MIN > tampung[a])
           {
            MIN = tampung[a];    
           }      
      }
     
    printf("%.2lf %.2lf %.2lf\n",MIN,MAX,RATA);
    
      return 0;
}
