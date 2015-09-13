        /*
          Program     :  Faktorial (Latihan 3C TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  3 November 2013, 22:54
          Finish Date :  3 November 2013, 23:00
        */

#include<stdio.h>
int main()
 {
   int N;
   scanf("%d",&N);
   
   /*short int a;
   long long nilai =1;
   for(a=1; a<=N; a++)
      {
        nilai = nilai * a;    
      }
   printf("nilai : %ld \n",nilai);
   
   int hasilBagi,sisa;
   hasilBagi = N/10;
   sisa = N % 10;
   int total= hasilBagi * 2;
   if(sisa >= 5)
     {
      total++;     
     }
   printf("%d\n",total);
   */
    int p = 0; 
    while(N > 0) 
    { 
      p+=N/5; 
      N/=5; 
    }
   printf("%d\n",p);
 
   return 0;
 }
        
