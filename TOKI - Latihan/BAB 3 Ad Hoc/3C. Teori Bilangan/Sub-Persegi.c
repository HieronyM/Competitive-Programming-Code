        /*
          Program     :  Sub Persegi(Latihan 3C TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  6 November 2013, 15:22
          Finish Date :  
        */
#include<stdio.h>
int main()
  {
   int N;
   scanf("%d",&N);
   
   long long total = 0;
   int a;
   for(a = 1; a<=N; a++)
      {
       total = total + (a*a);    
      }
   
   printf("%lld\n",total);
   return 0;       
  }
